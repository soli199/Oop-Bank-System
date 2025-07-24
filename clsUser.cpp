#include "clsUser.h"
clsUser clsUser::_ConvertLineToUserObject(string Line, string Seperator) {
  vector<string> vUserData = clsString::Split(Line, Seperator);
  return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],vUserData[3], vUserData[4],clsUtil::DecryptText (vUserData[5],2), stoi(vUserData[6]));
}
string clsUser::_PrepareLoginRecord(string Seperator)
{
 string Line="";
  Line+=clsDate::GetSystemDateTimeString()+Seperator;
  Line+=_UserName+Seperator;
  Line+=clsUtil::EncryptText(_Password,2)+Seperator;
  Line+=to_string(_Permissions);
  return Line ;
}
clsUser::stLoginRegisterRecord clsUser::_ConvertLineToLoginRegisterRecord(string Line,string Seperator)
{
  vector<string>vRecord=clsString::Split(Line,Seperator);
  stLoginRegisterRecord Record;
 Record.Date_Time=vRecord[0];
Record.UserName=vRecord[1];
  Record.Password=clsUtil::DecryptText (vRecord[2],2);
  Record.Permissions=stoi(vRecord[3]);
  return Record;
  
}
vector<clsUser::stLoginRegisterRecord>clsUser::LoadRegistersData()
{
  vector<stLoginRegisterRecord>vRecords;
  fstream MyFile;
MyFile.open("Login Register.txt",ios::in);
  if(MyFile.is_open())
  {
    string Line;
    while(getline(MyFile,Line))
      {
      vRecords.push_back(_ConvertLineToLoginRegisterRecord(Line));
    }
   MyFile.close();
  }
  return vRecords;
}
string clsUser::_ConvertUserObjectToLine(clsUser User, string Seperator) {
  string Line = "";
  Line += User.FirstName() + Seperator + User.LastName() + Seperator +
          User.Email() + Seperator + User.Phone() + Seperator+
          User.UserName() + Seperator + clsUtil::EncryptText (User.Password(),2) + Seperator +
          to_string(User.Permissions());
  return Line;
}
vector<clsUser> clsUser::_LoadUsersDataFromFile() {
  vector<clsUser> vUsers;
  fstream MyFile;
  MyFile.open("Users.txt", ios::in);
  if (MyFile.is_open()) {
    string Line;
    while (getline(MyFile, Line)) {
      clsUser User = _ConvertLineToUserObject(Line, "#//#");
      vUsers.push_back(User);
    }
    MyFile.close();
  }
  return vUsers;
}
void clsUser::_SaveUsersDataToFile(vector<clsUser> vUsers) {
  fstream MyFile;
  MyFile.open("Users.txt", ios::out);
  if (MyFile.is_open()) {
    for (clsUser &User : vUsers) {
      if (User.MarkedForDelete() == false)
        MyFile << _ConvertUserObjectToLine(User, "#//#") << endl;
    }
    MyFile.close();
  }
}
bool clsUser::CheckAccessPermission(enPermissions Permissions)
{
  if(this->Permissions()==enPermissions::epAll)
    return true;
  if((Permissions & this->Permissions())==Permissions)
    return true;
  else
    return false;
    
}
void clsUser::_AddDataLineToFile(string Line) {
  fstream MyFile;
  MyFile.open("Users.txt", ios::out | ios::app);
  if (MyFile.is_open()) {
    MyFile << Line << endl;
  }
  MyFile.close();
}
void clsUser::_Update() {
  vector<clsUser> vUsers = _LoadUsersDataFromFile();
  for (clsUser &C : vUsers) {
    if (C.UserName() == UserName()) {
      C = *this;
      break;
    }
  }
  _SaveUsersDataToFile(vUsers);
}
void clsUser::RegisterLogin()
{
  fstream MyFile;
  MyFile.open("Login Register.txt",ios::out|ios::app);
  string DataLine=_PrepareLoginRecord ();
  if(MyFile.is_open ())
  {
    MyFile<<DataLine<<endl;
  }
  MyFile.close();
}
void clsUser::_AddNew() { _AddDataLineToFile(_ConvertUserObjectToLine(*this)); }
clsUser clsUser::_GetEmptyUserObject() {
  return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
}
bool clsUser::IsEmpty() { return (_Mode == enMode::EmptyMode); }
bool clsUser::MarkedForDelete() { return _MarkForDelete; }
bool clsUser::IsUserExist(string UserName) {
  clsUser User = clsUser::Find(UserName);
  return (!User.IsEmpty());
}
bool clsUser::IsUserExist(string UserName, string Password) {
  clsUser User = clsUser::Find(UserName, Password);
  return (!User.IsEmpty());
}
void clsUser::SetUserName(string UserName) { _UserName = UserName; }

string clsUser::UserName() { return _UserName; }
void clsUser::SetPassword(string Password) { _Password = Password; }
string clsUser::Password() { return _Password; }
void clsUser::SetPermissions(int Permissions) { _Permissions = Permissions; }
int clsUser::Permissions() { return _Permissions; }
clsUser clsUser::Find(string UserName) {
  fstream MyFile;
  MyFile.open("Users.txt", ios::in);
  if (MyFile.is_open()) {
    string Line;
    while (getline(MyFile, Line)) {
      clsUser C = _ConvertLineToUserObject(Line, "#//#");

      if (C.UserName() == UserName) {
        return C;
      }
    }
    MyFile.close();
  }
  return _GetEmptyUserObject();
}
clsUser clsUser::Find(string UserName, string Password) {
  fstream MyFile;
  MyFile.open("Users.txt", ios::in);
  if (MyFile.is_open()) {
    string Line;
    while (getline(MyFile, Line)) {
      clsUser C = _ConvertLineToUserObject(Line, "#//#");

      if (C.UserName() == UserName && C.Password() == Password) {
        return C;
      }
    }
    MyFile.close();
  }
  return _GetEmptyUserObject();
}
bool clsUser::Delete() {
  vector<clsUser> vUsers = _LoadUsersDataFromFile();
  for (clsUser &U : vUsers) {
    if (U.UserName() == _UserName) {
      U._MarkForDelete = true;
      break;
    }
  }
  _SaveUsersDataToFile(vUsers);
  *this = _GetEmptyUserObject();
  return true;
}
clsUser clsUser::GetAddNewUserObject(string UserName) {
  return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
}
vector<clsUser> clsUser::GetUsersList() { return _LoadUsersDataFromFile(); }
clsUser::enSaveResults clsUser::Save() {
  switch (_Mode) {
  case enMode::EmptyMode:
    if (IsEmpty())
      return enSaveResults::svFaildEmptyObject;

  case enMode::UpdateMode: {
    _Update();
    return enSaveResults::svSucceeded;

  case enMode::AddNewMode:
    if (IsUserExist(_UserName))
      return enSaveResults::svFaildUserExists;
    else {
      _AddNew();
      _Mode = enMode::UpdateMode;
      return svSucceeded;
    }
  }
  }
}
