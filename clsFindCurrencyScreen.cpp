#include "clsFindCurrencyScreen.h"
void clsFindCurrencyScreen::_PrintCurrencyRecord (clsCurrency Currency)
{cout<<"\n=========================================\n";
 cout<<"\t Currency Informations \n";
 cout<<"=========================================\n";
  cout<<left<<setw(15)<<"Country : "<<Currency.Country()<<endl;
  cout<<left<<setw(15)<<"Code.   : "<<Currency.CurrencyCode()<<endl;
  cout<<left<<setw(15)<<"Name.   : "<<Currency.CurrencyName()<<endl;
  cout<<left<<setw(15)<<"Rate.   : "<<Currency.Rate()<<endl;
  cout<<"\n=========================================\n";
}
void clsFindCurrencyScreen::_ShowResults(clsCurrency Currency)
{
  if(Currency.IsEmpty())
  {
    cout<<"\nCurrency Is Not Found :-(\n";
  }
  else{
  
    cout<<"\nCurrency Is Found :-)\n";
    _PrintCurrencyRecord(Currency);
}
}
void clsFindCurrencyScreen::ShowFindCurrencyScreen()
{
  clsScreen::_DrawHeaderScreen("Find Currency Screen","");
  int Answer=0;
  cout<<"Find By [1] Code or [2] Country Name ?";
  Answer=clsInputValidate::ReadIntNumberBetween (1,2,"Enter 1 or 2 ?");
  if(Answer==1)
  {cout<<"\nEnter Currency Code : ";
    string Code=clsInputValidate::ReadString();
   clsCurrency Currency=clsCurrency::FindByCode(Code);
  _ShowResults(Currency);
  }
  else if(Answer==2)
  {
    cout<<"\nEnter Country Name : ";
    string Country=clsInputValidate::ReadString();
    clsCurrency Currency =clsCurrency::FindByCountry(Country);
    _ShowResults(Currency);
    
  }
  
}