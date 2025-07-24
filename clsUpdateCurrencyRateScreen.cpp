#include"clsUpdateCurrencyRateScreen.h"
float clsUpdateCurrencyRateScreen::_ReadRate()
{
  cout<<"\nEnter New Rate : ";
  return clsInputValidate::ReadFloatNumber();
}
void clsUpdateCurrencyRateScreen::_PrintCurrencyRecord (clsCurrency Currency)
{
cout<<"\n=========================================\n";
 cout<<"\t Currency Informations \n";
 cout<<"=========================================\n";
  cout<<left<<setw(15)<<"Country : "<<Currency.Country()<<endl;
  cout<<left<<setw(15)<<"Code.   : "<<Currency.CurrencyCode()<<endl;
  cout<<left<<setw(15)<<"Name.   : "<<Currency.CurrencyName()<<endl;
  cout<<left<<setw(15)<<"Rate.   : "<<Currency.Rate()<<endl;
  cout<<"\n=========================================\n";
}
void clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen ()
{
  clsScreen::_DrawHeaderScreen ("Uodate Rate Screen","");
  string Code="";
  cout<<"\nEnter Currency Code : ";
  Code=clsInputValidate::ReadString();
  while(!clsCurrency::IsCurrencyExist(Code))
    {
      cout<<"\nCurrency Code Is Not Found, Enter Another One : "; 
      Code=clsInputValidate::ReadString();
    }
  clsCurrency Currency=clsCurrency::FindByCode(Code);
  _PrintCurrencyRecord (Currency);
  char Answer='n';
  cout<<"\nAre you sure you want to update this currency rate [y/n] ?";
  cin>>Answer;
  if(toupper(Answer)=='Y')
  {
    cout<<"\nUpdate Currency Rate\n";
    cout<<"=========================\n";
    Currency.UpdateRate(_ReadRate());
    
    _PrintCurrencyRecord (Currency);
    cout<<"\nCurrency Rate Updated Successfully\n";
    
  }
  else
    cout<<"\nUpdate Currency Rate Cancelled\n";
}

