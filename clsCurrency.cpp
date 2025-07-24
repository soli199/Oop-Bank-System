#include"clsCurrency.h"
clsCurrency clsCurrency::_ConvertLineToCurrencyObject(string Line,string Seperator)
{
  vector<string>Currency=clsString::Split(Line,Seperator);
  clsCurrency currency(enMode::UpdateMode,Currency[0],Currency[1],Currency[2],stof(Currency[3]));
  return currency;
}
clsCurrency::clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate)
{
  _Mode=Mode;
  _Country=Country;
  _CurrencyCode=CurrencyCode;
  _CurrencyName=CurrencyName;
  _Rate=Rate;
}
float clsCurrency::ConvertToUsd(float Amount)
{
  return Amount/_Rate;
}
float clsCurrency::ConvertFromUsd(float Amount,clsCurrency Currency)
{
  float AmountInUsd=ConvertToUsd(Amount);
  if(Currency.CurrencyCode()=="USD")
    return AmountInUsd;
  else
    return AmountInUsd*Currency.Rate();
}
string clsCurrency::_ConvertCurrencyObjectToLine(clsCurrency Currency,string Seperator)
{
  string Line="";
  Line+=Currency.Country()+Seperator;
  Line+=Currency.CurrencyCode()+Seperator;
  Line+=Currency.CurrencyName()+Seperator;
  Line+=to_string(Currency.Rate());
  return Line;
  
}
vector<clsCurrency> clsCurrency::_LoadCurrencyDataFromFile()
{
  vector<clsCurrency>Currency;
  fstream MyFile;
  MyFile.open("Currencies.txt",ios::in);
  if(MyFile.is_open())
  {
    string Line;
    while(getline(MyFile,Line))
      {
        Currency.push_back(_ConvertLineToCurrencyObject(Line));
        
      }
    MyFile.close ();
  }
  return Currency;
}
void clsCurrency::_SaveCurrencyDataToFile(vector<clsCurrency>Currency)
{
  fstream MyFile;
  MyFile.open ("Currencies.txt",ios::out);
  if(MyFile.is_open ())
  {
    for(clsCurrency &C:Currency)
      {
        MyFile<<_ConvertCurrencyObjectToLine (C)<<endl;
        
      }
    MyFile.close ();
  }
}
void clsCurrency::_Update()
{
  vector<clsCurrency>Currency=_LoadCurrencyDataFromFile();
  for(clsCurrency &C:Currency)
    {
      if(C.CurrencyCode()==_CurrencyCode)
      {
        C=*this;
        break;
      }
    }
  _SaveCurrencyDataToFile(Currency);    
}
clsCurrency clsCurrency::_GetEmptyCurrencyObject()
{
  return clsCurrency(enMode::EmptyMode,"","","",0);
}
void clsCurrency::UpdateRate(float Rate)
{
  _Rate=Rate;
  _Update();
}
bool clsCurrency::IsEmpty()
{
  return (_Mode==enMode::EmptyMode);
}
bool clsCurrency::IsCurrencyExist(string CurrencyCode)
{
  clsCurrency Currency=clsCurrency::FindByCode(CurrencyCode);
  return(!Currency.IsEmpty());
}
clsCurrency clsCurrency::FindByCode(string CurrencyCode)
{
  CurrencyCode=clsString::UpperAllString (CurrencyCode);
  fstream MyFile;
  MyFile.open("Currencies.txt",ios::in);
  if(MyFile.is_open ())
  {
    string Line;
    while (getline(MyFile,Line))
      {
        clsCurrency Currency=_ConvertLineToCurrencyObject (Line);
        if(Currency.CurrencyCode()==CurrencyCode)
          {
          MyFile.close ();
          return Currency;
          }
      }
  }
  return _GetEmptyCurrencyObject ();  
}
clsCurrency clsCurrency::FindByCountry(string Country)
{
  Country=clsString::UpperAllString (Country);
  fstream MyFile;
  MyFile.open("Currencies.txt",ios::in);
  if(MyFile.is_open ())
  {
    string Line;
    while (getline(MyFile,Line))
      {
        clsCurrency Currency=_ConvertLineToCurrencyObject (Line);
        if(clsString::UpperAllString (Currency.Country())==Country)
          {
          MyFile.close ();
          return Currency;
          }
      }
  }
  return _GetEmptyCurrencyObject ();  
}
vector<clsCurrency> clsCurrency::GetCurrenciesList ()
{
  return _LoadCurrencyDataFromFile ();
}
