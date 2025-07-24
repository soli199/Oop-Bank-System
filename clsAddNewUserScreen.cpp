#include "clsAddNewUserScreen.h"
clsUser clsAddNewUserScreen::_ReadUserInfo(clsUser &User) {
  cout << "\nEnter FirstName: ";
  User.SetFirstName(clsInputValidate::ReadString());

  cout << "\nEnter LastName: ";
  User.SetLastName(clsInputValidate::ReadString());

  cout << "\nEnter Email: ";
  User.SetEmail(clsInputValidate::ReadString());

  cout << "\nEnter Phone: ";
  User.SetPhone(clsInputValidate::ReadString());

  cout << "\nEnter Password: ";
  User.SetPassword(clsInputValidate::ReadString());

  cout << "\nEnter Permission: ";
  User.SetPermissions(_ReadPermissionsToSet());
  return User;
}
int clsAddNewUserScreen::_ReadPermissionsToSet() {

  int Permissions = 0;
  char Answer = 'n';

  cout << "\nDo you want to give full access? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    return -1;
  }

  cout << "\nDo you want to give access to : \n ";

  cout << "\nShow Client List? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {

    Permissions += clsUser::enPermissions::epListClients;
  }

  cout << "\nAdd New Client? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epAddNewClient;
  }

  cout << "\nDelete Client? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epDeleteClient;
  }

  cout << "\nUpdate Client? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epUpdateClient;
  }

  cout << "\nFind Client? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epFindClient;
  }

  cout << "\nTransactions? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epTransactions;
  }

  cout << "\nManage Users? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epManageUsers;
  }
    cout << "\nShow Login Registers? y/n? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y') {
    Permissions += clsUser::enPermissions::epLoginRegister;
  }

  return Permissions;
}
void clsAddNewUserScreen::_PrintUser(clsUser User) {
  cout << "\n=====================================";
  cout << "\nUser Card:";
  cout << "\n=====================================";
  cout << "\nFirstName   : " << User.FirstName();
  cout << "\nLastName    : " << User.LastName();
  cout << "\nFull Name   : " << User.FullName();
  cout << "\nEmail       : " << User.Email();
  cout << "\nPhone       : " << User.Phone();
  cout << "\nUser Name   : " << User.UserName();
  cout << "\nPassword    : " << User.Password();
  cout << "\nPermissions : " << User.Permissions();
  cout << "\n=====================================\n";
}
void clsAddNewUserScreen:: ShowAddNewUserScreen()
{
  clsScreen::_DrawHeaderScreen("Add New User Screen ","");
  
  string UserName="";
  cout<<"\nEnter UserName:";
UserName=clsInputValidate::ReadString();
  while(clsUser::IsUserExist(UserName))
    {
      cout<<"\nUser with ["<<UserName<<"] already exists, Enter another UserName:";
      UserName =clsInputValidate::ReadString();
    }
  clsUser User=clsUser::GetAddNewUserObject(UserName);
  _ReadUserInfo(User);
  clsUser::enSaveResults SaveResults=User.Save();
  switch(SaveResults)
    {
      case clsUser::enSaveResults::svFaildEmptyObject:
      cout<<"\nError User Was Not Saved Because It Is Empty\n";
      break;
      case clsUser::enSaveResults::svSucceeded:
      cout<<"\nUser Added Succseccfully\n ";
      _PrintUser(User);
      break;
      case clsUser::enSaveResults::svFaildUserExists:
      cout<<"\nError User Was Not Saved Because User Exists\n";
      break;
      
      
    }
  
}