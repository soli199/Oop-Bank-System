#ifndef CLSCURRENCYMAINSCREEN_H
#define CLSCURRENCYMAINSCREEN_H
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
class clsCurrencyMainScreen:protected clsScreen
{private:
enum enCurrenciesMenueOptions{
eListCurrencies=1,eFindCurrency,eUpdateCurrencyRate,eCurrencyCalculator,eMainMenue};
static short _ReadCurrenciesMainMenueOptions();
static void _GoBackToCurrenciesMainMenue();
static void _ShowCurrenciesListScreen();
static void _ShowFindCurrencyScreen();
static void _ShowUpdateCurrencyRateScreen();
static void _ShowCurrencyCalculatorScreen();
static void _PerformCurrenciesMainMenueOptions(enCurrenciesMenueOptions Option);
 public:
static void ShowCurrenciesMainMenue();


};
#endif

