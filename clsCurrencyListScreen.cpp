#include"clsCurrencyListScreen.h"
void clsCurrencyListScreen::_PrintCurrencyRecord(clsCurrency Currency)
{
  cout<<left<<setw(15)<<Currency.Country()<<"|"<<left<<setw(5)<<Currency.CurrencyCode()<<"|"<<left<<setw(10)<<Currency.CurrencyName()<<"|"<<left<<setw(5)<<Currency.Rate()<<endl;
}
void clsCurrencyListScreen::ShowCurrenciesList()
{
  vector<clsCurrency>vCurr=clsCurrency::GetCurrenciesList();
  string Title="Currencies List Screen ";
  string SubTitle="("+to_string(vCurr.size())+"Currency )";
  clsScreen::_DrawHeaderScreen(Title,SubTitle);
  cout<<"\n==========================================\n";
  cout<<left<<setw(15)<<"Country"<<"|"<<left<<setw(5)<<"Code"<<"|"<<left<<setw(10)<<"Name"<<"|"<<left<<setw(5)<<"Rate/(1$)"<<endl;
  cout<<"==========================================\n";
  if(vCurr.size()==0)
    cout<<"\tNo Currencies Available In The System\n";
  else
  {
    for(clsCurrency &C:vCurr)
      _PrintCurrencyRecord(C);
  }
  cout<<"====================================\n";
  
  
}