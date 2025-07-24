#include"clsTransactionsScreen.h"
#include"clsDepositeScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"

short clsTransactionsScreen::_ReadTransactionsMenueOptions()
{
  short Choice;
  cout <<"\nChoose what do you want to do [1/6]?";
  Choice=clsInputValidate::ReadIntNumberBetween(1,6,"Enter Number In Range 1 to 6?");
  return Choice;
}
void clsTransactionsScreen::_GoBackToTransactionsMenue()
{
  #ifdef _WIN32
  system("pause");
#else

  cout << "\nPress any key to go back to transactions menu...\n";

  cin.ignore();
  cin.get();
#endif
ShowTransactionsMenueScreen();
}
void clsTransactionsScreen::_ShowTransferScreen()
{
  clsTransferScreen::ShowTransferScreen();
}
void clsTransactionsScreen::_ShowTransferLogScreen ()
{
  clsTransferRegisterScreen::ShowTransferRegisterScreen();
}
void clsTransactionsScreen::_ShowDepositeScreen()
{
  //cout <<"\nDeposite Screen Will Be Here....\n";

  clsDepositeScreen::ShowDepositeScreen();
}
void clsTransactionsScreen::_ShowWithdrawScreen()
{
  //cout<<"\nWithdraw Screen Will Be Here....\n";
clsWithdrawScreen::ShowWithdrawScreen();
}
void clsTransactionsScreen::_ShowTotalBalancesScreen()
{
  //cout<<"\nTotal Balances Screen Will Be Here....\n";
  clsTotalBalancesScreen::ShowTotalBalancesScreen ();
}
void clsTransactionsScreen::_PerformTransactionsOption(enTransactionsMenueOptions Option)
{
  switch(Option){
    case enTransactionsMenueOptions::eDeposite:
  (void)system("clear");
  _ShowDepositeScreen();
  _GoBackToTransactionsMenue();
  case enTransactionsMenueOptions::eWithdraw:  (void)system("clear");
    _ShowWithdrawScreen();
    _GoBackToTransactionsMenue();
    case enTransactionsMenueOptions::eTotalBalances:
    (void)system("clear");
    _ShowTotalBalancesScreen();
    _GoBackToTransactionsMenue();
    case enTransactionsMenueOptions::eTransfer:
    (void)system("clear");
    _ShowTransferScreen();
    _GoBackToTransactionsMenue();
    case enTransactionsMenueOptions::eTransferLog:
    (void)system("clear");
    _ShowTransferLogScreen();
    _GoBackToTransactionsMenue();
    case enTransactionsMenueOptions::eMainMenue:
    break;

}
}
void clsTransactionsScreen::ShowTransactionsMenueScreen()
{
  if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epAddNewClient ))
  {return;}
  (void)system("clear");
  clsScreen::_DrawHeaderScreen("Transactions Menu ","");
  
  cout<<"==================================\n";
    cout<<"\t\tTransactions Menue \n";
  cout<<"==================================\n";
  cout<<"\t[1] Deposite.\n";
  cout<<"\t[2] Withdraw. \n";
  cout<<"\t[3] Transfer.\n";
  cout<<"\t[4] Transfer Log.\n";
  cout<<"\t[5] Total Balances. \n";
  cout<<"\t[6] Main Menue. \n";
  cout<<"==================================\n";
  _PerformTransactionsOption((enTransactionsMenueOptions)_ReadTransactionsMenueOptions()); 
}