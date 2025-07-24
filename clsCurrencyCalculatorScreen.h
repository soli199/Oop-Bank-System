#ifndef CLSCURRENCYCALCULATORSCREEN_H
#define CLSCURRENCYCALCULATORSCREEN_H
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iomanip>
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
static float _ReadAmount();
static clsCurrency _GetCurrency(string Msg);
static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:");
static void _PrintCalculationResults(float Amount,clsCurrency FromCurrency,clsCurrency ToCurrency);
public:
static void ShowCurrencyCalculatorScreen();
};
#endif