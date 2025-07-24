#include "clsUpdateUserScreen.h"
clsUser clsUpdateUserScreen::_ReadUserInfo(clsUser &User) {
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
int clsUpdateUserScreen::_ReadPermissionsToSet() 

  {

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
      Permissions += clsUser::enPermissions::epUpdateClient
        ;
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

    return Permissions;
  }
void clsUpdateUserScreen::_PrintUser(clsUser User)
     {
cout<<"\n===================================\n";
cout << "\nUser Card:";
cout<<"\n===================================\n";
        cout << "\nFirstName   : " << User.FirstName();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " <<User.Password();
        cout << "\nPermissions : " << User.Permissions();
cout <<"\n=================================\n";

}
void clsUpdateUserScreen::ShowUpdateUserScreen()
{
  clsScreen::_DrawHeaderScreen("Update User Screen","");
  
  string UserName ="";
  cout<<"\nEnter UserName:";
  UserName =clsInputValidate::ReadString ();
  while(!clsUser::IsUserExist (UserName))
    {
      cout <<"\nUser Name is not found, Enter another UserName:";
      UserName=clsInputValidate::ReadString ();
    }
  clsUser User=clsUser::Find(UserName);
  _PrintUser(User);
char Answer ='n';
  cout<<"\nAre you sure you want to update this user [y/n]?";
  cin>>Answer;
  if(Answer=='y'||Answer=='Y')
  {
    _ReadUserInfo(User);
    clsUser::enSaveResults SaveResult =User.Save();
    switch(SaveResult)
      {
        case clsUser::enSaveResults::svFaildEmptyObject:
        cout<<"\nError ,User was not saved because it is empty\n";
        break;
        case clsUser::enSaveResults::svSucceeded:
        cout<<"\nUser Updated successfully\n";
        break;
        case clsUser::enSaveResults::svFaildUserExists:
        cout<<"\nError ,User was not saved because User exists\n";
        break;
      }
  }
  else 
    cout<<"\nOperation was cancelled \n";
}