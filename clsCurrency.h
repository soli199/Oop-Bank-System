#ifndef CLSCURRENCY_H
#define CLSCURRENCY_H
#include<iostream>
#include"clsString.h"
#include<fstream>
#include<vector>
#include<string>
class clsCurrency
{
private:
enum enMode{EmptyMode=0,UpdateMode=1};
enMode _Mode;
string _Country;
string _CurrencyCode;
string _CurrencyName;
float _Rate;
static clsCurrency _ConvertLineToCurrencyObject(string Line,string Seperator ="#//#");
static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Seperator ="#//#");
static vector<clsCurrency> _LoadCurrencyDataFromFile();
static void _SaveCurrencyDataToFile(vector<clsCurrency>Currency);
void _Update();
static clsCurrency _GetEmptyCurrencyObject();

public:
clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate);
enMode Mode()
{
  return _Mode;
}
string Country ()
{
  return _Country;
}
string CurrencyCode()
{
  return _CurrencyCode;
}
string CurrencyName()
{
  return _CurrencyName;
}
float Rate()
{
  return _Rate;
}
void UpdateRate(float Rate);
bool IsEmpty();
static bool IsCurrencyExist(string CurrencyCode);
static clsCurrency FindByCode(string Code);
static clsCurrency FindByCountry(string Country); 
static  vector<clsCurrency>GetCurrenciesList();
float ConvertToUsd(float Amount);
float ConvertFromUsd(float Amount,clsCurrency Currency);
};
#endif