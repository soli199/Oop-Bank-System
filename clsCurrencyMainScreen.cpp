#include"clsCurrencyMainScreen.h"
short clsCurrencyMainScreen::_ReadCurrenciesMainMenueOptions()
{
  short Choice=0;
  cout<<"Enter what do you want to do?[1 to 5]?";
  Choice=clsInputValidate::ReadIntNumberBetween(1,5,"Enter number between 1 to 5?");
  return Choice;
}
void clsCurrencyMainScreen::_GoBackToCurrenciesMainMenue ()
{
      #ifdef _WIN32
  system("pause");
#else

  cout << "\nPress any key to go back to manage users menu...\n";

  cin.ignore();
  cin.get();
#endif
  ShowCurrenciesMainMenue();
  
}
void clsCurrencyMainScreen::_ShowCurrenciesListScreen()
{
 // cout<<"Currencies List Screen Will Be Here....\n";
  clsCurrencyListScreen::ShowCurrenciesList();
}
void clsCurrencyMainScreen::_ShowFindCurrencyScreen()
{
 // cout<<"Find Currency Screen Will Be Here....\n";
  clsFindCurrencyScreen::ShowFindCurrencyScreen();
}
void clsCurrencyMainScreen::_ShowUpdateCurrencyRateScreen()
{
  //cout<<"Update Currency Rate Screen Will Be Here....\n";
  clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen ();
}
void clsCurrencyMainScreen::_ShowCurrencyCalculatorScreen()
{
 // cout<<"Currency Calculator Screen Will Be Here....\n";
  clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
}
void clsCurrencyMainScreen::_PerformCurrenciesMainMenueOptions (enCurrenciesMenueOptions Option)
{
  switch(Option)
    {
      case enCurrenciesMenueOptions::eListCurrencies:
      (void)system("clear");
      _ShowCurrenciesListScreen ();
      _GoBackToCurrenciesMainMenue ();
      case enCurrenciesMenueOptions::eFindCurrency:
      (void)system("clear");
        _ShowFindCurrencyScreen();
      _GoBackToCurrenciesMainMenue ();
      case enCurrenciesMenueOptions::eUpdateCurrencyRate:
      (void)system("clear");
      _ShowUpdateCurrencyRateScreen();
      _GoBackToCurrenciesMainMenue ();
      case enCurrenciesMenueOptions::eCurrencyCalculator:
      (void)system("clear");
      _ShowCurrencyCalculatorScreen();
      _GoBackToCurrenciesMainMenue ();
      case enCurrenciesMenueOptions::eMainMenue:
      break;
    }
  
}
void clsCurrencyMainScreen::ShowCurrenciesMainMenue()
{(void)system("clear");
  clsScreen::_DrawHeaderScreen("Currency Exchange Main Screen","");
  cout<<"======================================\n";
  cout<<"\t[1] List Currencies.\n";
  cout<<"\t[2] Find Currency.\n";
  cout<<"\t[3] Update Currency Rate.\n";
  cout<<"\t[4] Currency Calculator.\n";
  cout<<"\t[5] Main Menue.\n";
  cout<<"\n=====================================\n";
  _PerformCurrenciesMainMenueOptions((enCurrenciesMenueOptions)_ReadCurrenciesMainMenueOptions());
  
}
