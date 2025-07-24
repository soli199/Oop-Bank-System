#include "clsBankClient.h"
#include"clsDate.h"

clsBankClient clsBankClient::_ConvertLineToClientObject(string Line,string Seperator) 
{
vector<string> vClientsData;
vClientsData = clsString::Split(Line, Seperator);
return clsBankClient{clsBankClient::enMode::UpdateMode,
                       vClientsData[0],
                       vClientsData[1],
                       vClientsData[2],
                       vClientsData[3],
                       vClientsData[4],
                       vClientsData[5],
                       stof(vClientsData[6])};
}
clsBankClient::stTransferLogRecord clsBankClient::_ConvertLineToTransferLogRecord(string Line,string Seperator)
{
  vector<string> vInfo=clsString::Split(Line,Seperator);
  stTransferLogRecord Record;
 Record.DateTime=vInfo[0];
  Record.SourceAccountNumber=vInfo[1];
 Record.DestinationAccountNumber=vInfo[2];
Record.Amount=stod(vInfo[3]);
  Record.SourceBalance=stod(vInfo[4]);
  Record.DestinationBalance=stod(vInfo[5]);
  Record.UserName=vInfo[6];
  return Record;
}
vector<clsBankClient::stTransferLogRecord >clsBankClient::GetTransferData()
{
  vector<clsBankClient::stTransferLogRecord >vInfo;
  fstream MyFile;
MyFile.open("TransferLog.txt",ios::in);
  if(MyFile.is_open ())
  {
    string Line;
    while(getline(MyFile,Line))
      {vInfo.push_back(_ConvertLineToTransferLogRecord(Line));
       
      }
  MyFile.close();
  }
  return vInfo;
}
string clsBankClient::_ConvertClientObiectToLine(clsBankClient Client,string Seperator)
{
  string stClientRecord = "";
  stClientRecord += Client.FirstName() + Seperator;
  stClientRecord += Client.LastName() + Seperator;
  stClientRecord += Client.Email() + Seperator;
  stClientRecord += Client.Phone() + Seperator;
  stClientRecord += Client.AccountNumber() + Seperator;
  stClientRecord += Client.PinCode() + Seperator;
  stClientRecord += to_string(Client.AccountBalance());

  return stClientRecord;
}
string clsBankClient::_PrepareTransferLogRecord(double Amount,clsBankClient DestinationClient,string UserName,string Seperator)
{
  string Line="";
  Line+=clsDate::GetSystemDateTimeString ()+Seperator;
  Line+=AccountNumber()+Seperator;
  Line+=DestinationClient. AccountNumber ()+Seperator;
  Line+=to_string(Amount)+Seperator;
  Line+=to_string(AccountBalance())+Seperator;
  Line+=to_string (DestinationClient. AccountBalance ())+Seperator;
  Line+=UserName;
  return Line;
}
void clsBankClient::_RegisterTransferLogRecord(double Amount,clsBankClient DestinationClient,string UserName)
{
  string Line=_PrepareTransferLogRecord (Amount,DestinationClient,UserName);
  fstream MyFile;
  MyFile.open("TransferLog.txt",ios::out|ios::app);
  if(MyFile.is_open ())
  {
    MyFile <<Line<<endl;
  }
MyFile.close();  
}
vector<clsBankClient> clsBankClient::_LoadClientsDataFromFile() {
  vector<clsBankClient> vClients;
  fstream MyFile;
  MyFile.open("Clients.txt", ios::in);
  if (MyFile.is_open()) {
    string Line;
    while (getline(MyFile, Line)) {
      clsBankClient Client =
          clsBankClient::_ConvertLineToClientObject(Line, "#//#");
      vClients.push_back(Client);
    }
    MyFile.close();
  }
  return vClients;
}

void clsBankClient::_SaveClientsDataToFile(vector<clsBankClient> vClients) {
  fstream MyFile;
  MyFile.open("Clients.txt", ios::out);
  if (MyFile.is_open()) {
    string line = "";
    for (clsBankClient C : vClients) {if(C.MarkedForDelete() ==false)
    {line = clsBankClient::_ConvertClientObiectToLine(C);
      MyFile << line << endl;
    }}
    MyFile.close();
  }
}

void clsBankClient::_Update() {
  vector<clsBankClient> vClients;
  vClients = clsBankClient::_LoadClientsDataFromFile();
  for (clsBankClient &C : vClients) {
    if (C.AccountNumber() == AccountNumber()) {
      C = *this;
      break;
    }
  }
  clsBankClient::_SaveClientsDataToFile(vClients);
}
void clsBankClient ::_AddNew()
{
  _AddDataLineToFile(_ConvertClientObiectToLine (*this));
}

void clsBankClient::_AddDataLineToFile(string Line) {
  fstream MyFile;
  MyFile.open("Clients.txt", ios::out | ios::app);
  if (MyFile.is_open()) {
    MyFile << Line << endl;
  }
  MyFile.close();
}
clsBankClient clsBankClient::_GetEmptyClientObject() {
  return clsBankClient{
      clsBankClient::enMode::EmptyMode, "", "", "", "", "", "", 0};
}

bool clsBankClient::IsEmpty() { return (_Mode ==enMode::EmptyMode); }

string clsBankClient::AccountNumber() { return _AccountNumber; }

void clsBankClient::SetPinCode(string PinCode) { _PinCode = PinCode; }
string clsBankClient::PinCode() { return _PinCode; }
void clsBankClient::SetAccountBalance(float AccountBalance) {
  _AccountBalance = AccountBalance;
}
float clsBankClient::AccountBalance() { return _AccountBalance; }

void clsBankClient::Print()

{
  cout << "\nClient Card:";
  cout << "\n___________________";
  cout << "\nFirstName   : " << FirstName();
  cout << "\nLastName    : " << LastName();
  cout << "\nFull Name   : " << FullName();
  cout << "\nEmail       : " << Email();
  cout << "\nPhone       : " << Phone();
  cout << "\nAcc. Number : " << _AccountNumber;
  cout << "\nPassword    : " << _PinCode;
  cout << "\nBalance     : " << _AccountBalance;
  cout << "\n___________________\n";
}
clsBankClient clsBankClient::Find(string AccountNumber) {
  fstream MyFile;
  MyFile.open("Clients.txt", ios::in);
  if (MyFile.is_open()) {
    string Line;
    while (getline(MyFile, Line))
      {
      clsBankClient Client = clsBankClient::_ConvertLineToClientObject(Line);
      if (Client.AccountNumber() == AccountNumber) {
        MyFile.close();
        return Client;
      }
    }
    MyFile.close();
  }
  return clsBankClient::_GetEmptyClientObject();
}
clsBankClient clsBankClient::Find(string AccountNumber, string PinCode) {
  fstream MyFile;
  MyFile.open("Clients.txt", ios::in);
  if (MyFile.is_open()) {
    string Line;
    while (getline(MyFile, Line)) {
      clsBankClient Client = clsBankClient::_ConvertLineToClientObject(Line);
      if (Client.AccountNumber() == AccountNumber &&
          Client.PinCode() == PinCode) {
        MyFile.close();
        return Client;
      }
    }
    MyFile.close();
  }
  return clsBankClient::_GetEmptyClientObject();
}

clsBankClient::enSaveResults clsBankClient::Save() {

  switch (_Mode) {
  case enMode::EmptyMode: {
if(IsEmpty())
    return enSaveResults::svFaildEmptyObject;
  }

  case enMode::UpdateMode: {

    _Update();

    return enSaveResults::svSucceeded;
  

  }
    case enMode::AddNewMode:
      {
        if(IsClientExist(_AccountNumber))
          return enSaveResults::svFaildAccountNumberExists;
        else{
    _AddNew();
    _Mode=enMode::UpdateMode;
    return enSaveResults::svSucceeded;
  }
}
  }
}
bool clsBankClient::IsClientExist(string AccountNumber) {
  clsBankClient Client1 = clsBankClient::Find(AccountNumber);
  return (!Client1.IsEmpty());
}
bool clsBankClient::IsClientExist(string AccountNumber, string PinCode) {
  clsBankClient Client1 = clsBankClient::Find(AccountNumber, PinCode);
  return (!Client1.IsEmpty());
}
  clsBankClient clsBankClient::GetAddNewClientObject(string AccountNumber)
{
  return clsBankClient {enMode::AddNewMode,"","","","",AccountNumber,"",0};
}
bool clsBankClient::MarkedForDelete()
{
  return _MarkForDelete;
}
bool clsBankClient::Delete()
{
  vector<clsBankClient >vClients;
  vClients=_LoadClientsDataFromFile ();
  for(clsBankClient &C:vClients)
    {
      if(C.AccountNumber ()==_AccountNumber)
      {
        C._MarkForDelete=true;
        break;
      }
    }
  _SaveClientsDataToFile (vClients);
  *this=clsBankClient::_GetEmptyClientObject();
  return true;
  
}
vector <clsBankClient >clsBankClient::GetClientsList()
{
  return clsBankClient::_LoadClientsDataFromFile ();
}
float clsBankClient::GetTotalBalances()
{
  vector <clsBankClient >vClients;
  vClients =_LoadClientsDataFromFile ();
  float TotalBalances =0;
  for(clsBankClient &C:vClients)
    TotalBalances +=C.AccountBalance ();

return TotalBalances;
}
bool clsBankClient::Transfer(double Amount,clsBankClient &DestinationClient,string UserName )
{
  if(Amount>_AccountBalance)
   {return false;}
  
    Withdraw(Amount);
  DestinationClient.Deposite(Amount);
  _RegisterTransferLogRecord(Amount,DestinationClient,UserName);
  return true;   
}


void clsBankClient::Deposite(double Amount)
{
  _AccountBalance+=Amount;
  Save();
}
bool clsBankClient::Withdraw(double Amount)
{
  if(Amount>_AccountBalance)
    return false;
  else
  {
    _AccountBalance-=Amount;
    Save();
    return true;
  }
}


