#include"clsCurrencyCalculatorScreen.h"
float clsCurrencyCalculatorScreen::_ReadAmount()
{
  float Amount;
  cout<<"Please Enter Amonut To Exchange : ";
  Amount=clsInputValidate::ReadFloatNumber();
  return Amount;  
}
clsCurrency clsCurrencyCalculatorScreen::_GetCurrency(string Msg)
{
  cout<<Msg;
  string CurrencyCode;
  CurrencyCode =clsInputValidate::ReadString ();
  while(!clsCurrency::IsCurrencyExist(CurrencyCode))
    {
      cout<<"\nCurrency  Is Not Found,Please enter another one : ";
      CurrencyCode =clsInputValidate::ReadString ();
    }
  clsCurrency Currency =clsCurrency::FindByCode(CurrencyCode);
  return Currency;
}
void clsCurrencyCalculatorScreen::_PrintCurrencyCard(clsCurrency Currency, string Title )
{
 cout << "\n" << Title << "\n";
 cout << "====================================\n";
 cout << "\nCountry : " << Currency.Country();
 cout << "\nCode : " << Currency.CurrencyCode();
 cout << "\nName : " << Currency.CurrencyName();
 cout << "\nRate(1$) = : " << Currency.Rate();
 cout << "\n====================================\n\n";
}
void clsCurrencyCalculatorScreen::_PrintCalculationResults(float Amount,clsCurrency FromCurrency,clsCurrency ToCurrency)
{
  _PrintCurrencyCard(FromCurrency,"Convert From");
  cout<<Amount<<" "<<FromCurrency.CurrencyCode()<<" = "<<FromCurrency.ConvertToUsd(Amount)<<" USD\n";
  if(ToCurrency.CurrencyCode()=="USD")
    return;
  cout<<"\nConverting From USD To :";
  _PrintCurrencyCard(ToCurrency,"Convert To");
  cout<<Amount<<" "<<FromCurrency.CurrencyCode ()<<" = "<<FromCurrency.ConvertFromUsd(Amount,ToCurrency)<<"  "<<ToCurrency.CurrencyCode()<<endl;
  
}
void clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen()
{
  char Answer='Y';
while(Answer=='y'||Answer=='Y')
  {
    (void)system("clear");
    clsScreen::_DrawHeaderScreen("Currency Calculator Screen ","");
    clsCurrency Currency1=_GetCurrency("Enter Currency Code To Exchange From : ");
    clsCurrency Currency2=_GetCurrency("Enter Currency Code To Exchange To : ");
    float Amount=_ReadAmount();
    _PrintCalculationResults (Amount,Currency1,Currency2);
    cout<<"\nDo you want to perform another calculation?Y/N ";
    cin>>Answer;
  }
}


