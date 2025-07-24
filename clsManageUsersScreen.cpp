#include"clsManageUsersScreen.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
short clsManageUsersScreen::_ReadUsersMenueOption()
{
  cout<<"\nChoose what do you want to do [1/6]?:";
  short Choice=clsInputValidate::ReadIntNumberBetween(1,6,"Enter Number In Range 1 to 6?");
  return Choice;
}
void clsManageUsersScreen::_GoBackToManageUsersMenue()
{
    #ifdef _WIN32
  system("pause");
#else

  cout << "\nPress any key to go back to manage users menu...\n";

  cin.ignore();
  cin.get();
#endif
ShowManageUsersMenue();
}
void clsManageUsersScreen::_AddNewUserScreen()
{
  //cout<<"\nAdd New User Screen Will Be Here....\n";
  clsAddNewUserScreen::ShowAddNewUserScreen ();
}

void clsManageUsersScreen::_DeleteUserScreen()
{
  //cout<<"\nDelete User Screen Will Be Here....\n";
  clsDeleteUserScreen::ShowDeleteUserScreen();
}
void clsManageUsersScreen::_UpdateUserScreen()
{
  //cout<<"\nUpdate User Screen Will Be Here....\n";
  clsUpdateUserScreen::ShowUpdateUserScreen();
}
void clsManageUsersScreen::_FindUserScreen()
{
 // cout<<"\nFind User Screen Will Be Here....\n";
  clsFindUserScreen::ShowFindUserScreen();
}
void clsManageUsersScreen::_ShowAllUsersScreen()
{
  //cout<<"\nShow All Users Screen Will Be Here....\n";
  clsUsersListScreen::ShowUsersListScreen();
}
void clsManageUsersScreen::_PerformManageUsersMenueOption(enManageUsersMenueOptions Option)
{
  switch(Option)
    {
      case enManageUsersMenueOptions::eListUsers:
      (void)system("clear");
      _ShowAllUsersScreen ();
      _GoBackToManageUsersMenue ();
      case enManageUsersMenueOptions::eAddNewUser:
      (void)system("clear");
      _AddNewUserScreen();
      _GoBackToManageUsersMenue ();
      case enManageUsersMenueOptions::eDeleteUser:
      (void)system("clear");
      _DeleteUserScreen();
      _GoBackToManageUsersMenue ();
      case enManageUsersMenueOptions::eUpdateUser:
      (void)system ("clear");
      _UpdateUserScreen();
      _GoBackToManageUsersMenue ();
      case enManageUsersMenueOptions::eFindUser:
      (void)system ("clear");
      _FindUserScreen();
      _GoBackToManageUsersMenue();
      case enManageUsersMenueOptions::eMainMenu:
      break;
    }
}
void clsManageUsersScreen::ShowManageUsersMenue()
{
 if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epManageUsers ))
   
 {return;}
  (void)system ("clear");
  clsScreen::_DrawHeaderScreen("Manage Users Menue","");
  
  cout<<"\n==================================\n";
  cout<<"\t\tManage Users Menue\n";
  cout<<"==================================\n";
  cout<<"\t[1] List Users. \n";
  cout<<"\t[2] Add New User.\n";
  cout<<"\t[3] Delete User.\n";
  cout<<"\t[4] Update User.\n";
  cout<<"\t[5] Find User.\n";
  cout<<"\t[6] Main Menue.\n";
  cout<<"\n=================================\n";
  _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadUsersMenueOption());
  
}