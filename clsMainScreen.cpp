#include"clsMainScreen.h"


short clsMainScreen::_ReadMainMenueOption()
{
  cout <<"Choose what do you want to do[1/10]";
  short Choice=clsInputValidate::ReadIntNumberBetween(1,10,"Enter number in range 1 to 10?");
  return Choice;
}
void clsMainScreen::_GoBackToMainMenue()
{
  #ifdef _WIN32
  system("pause");
#else

  cout << "Press any key to go back to main menu...\n";

  cin.ignore();
  cin.get();
#endif
  ShowMainMenue();
}
void clsMainScreen::_ShowAllClientsScreen()
{
 // cout<<"Client list Will Be Here.....\n";
  clsClientScreen::ShowAllClientsScreen(); 
}
void clsMainScreen::_ShowAddNewClientScreen()
{
  //cout<<"Add New Client Screen Will Be Here....\n";
  clsAddClientScreen::ShowAddNewClientScreen();
}
void clsMainScreen::_ShowDeleteClientScreen ()
{
  //cout<<"Delete Client Screen Will Be Here....\n";
  clsDeleteClientScreen::ShowDeleteClientScreen ();
}
void clsMainScreen::_ShowUpdateClientScreen()
{
  //cout<<"Update Client Screen Will Be Here....\n";
  clsUpdateClientScreen::ShowUpdateClientScreen ();
}
void clsMainScreen::_ShowFindClientScreen()
{
  //cout<<"Find Client Screen Will Be Here....\n";
  clsFindClientScreen::ShowFindClientScreen ();
}
void clsMainScreen::_ShowTransactionsMenue ()
{
 // cout<<"Transactions Menu Screen Will Be H....\n";
  clsTransactionsScreen::ShowTransactionsMenueScreen();
}
void clsMainScreen::_ShowLoginRegisterScreen()
{
  clsLoginRegisterScreen::ShowLoginRegisterScreen();
}
void clsMainScreen::_ShowManageUsersMenue()
{
  //cout <<"Manage Users Screen Will Be Here....\n";
  clsManageUsersScreen::ShowManageUsersMenue();

}
void clsMainScreen::_ShowCurrencyExchangeScreen()
{
  clsCurrencyMainScreen::ShowCurrenciesMainMenue();
}
/*void clsMainScreen::_ShowEndScreen()
{cout<<"Exit Screen Will be Here....\n";
}*/
void clsMainScreen::_Logout()
{
  CurrentUser=clsUser::Find("","");
  
}
void clsMainScreen::PerformMainMenueOption(enMainMenueOptions MainMenueOption)
{
  switch(MainMenueOption)
    {
      case enMainMenueOptions::eListClients:
      (void)system("clear");
      _ShowAllClientsScreen();
      _GoBackToMainMenue ();
      case enMainMenueOptions::eAddNewClient:
    (void)system("clear");
      _ShowAddNewClientScreen();
      _GoBackToMainMenue ();
      case enMainMenueOptions ::eDeleteClient:
     (void) system("clear");
      _ShowDeleteClientScreen();
      _GoBackToMainMenue ();
      case enMainMenueOptions::eUpdateClient:
     (void) system("clear");
      _ShowUpdateClientScreen();
      _GoBackToMainMenue ();
      case enMainMenueOptions::eFindClient:
     (void) system("clear");
      _ShowFindClientScreen();
      _GoBackToMainMenue ();
      case enMainMenueOptions::eShowTransactionsMenue:
     (void) system("clear");
      _ShowTransactionsMenue();
      _GoBackToMainMenue ();
      case enMainMenueOptions::eManageUsers:
      (void)system("clear");
      _ShowManageUsersMenue();
      _GoBackToMainMenue ();
      case enMainMenueOptions::eLoginRegisters:
        
          (void)system("clear");
          _ShowLoginRegisterScreen ();
          _GoBackToMainMenue();
      case enMainMenueOptions::eCurrencyExchange:
      (void)system("clear");
      _ShowCurrencyExchangeScreen ();
      _GoBackToMainMenue ();
        
      case enMainMenueOptions::eExit:
     (void) system("clear");
      //_ShowEndScreen();
        _Logout();
        break;
    }
}
  

void clsMainScreen::ShowMainMenue()
{(void)system("clear");
 _DrawHeaderScreen("Main Screen","");
cout<<"==================================\n";
  cout<<"\t\t Main Menue.\n";
  cout<<"==================================\n";
  cout<<"\t[1] Show Client List.\n";
  cout<<"\t[2] Add New Client.\n";
  cout<<"\t[3] Delete Client.\n";
  cout<<"\t[4] Update Client.\n";
  cout<<"\t[5] Find Client.\n";
  cout<<"\t[6] Transactions. \n";
  cout<<"\t[7] Manage Users.\n";
 cout<<"\t[8] Show Logins.\n";
 cout<<"\t[9] Currency Exchange.\n";
  cout<<"\t[10] LogOut.\n";
  cout<<"==================================\n";
  PerformMainMenueOption((enMainMenueOptions)clsMainScreen::_ReadMainMenueOption());
}
