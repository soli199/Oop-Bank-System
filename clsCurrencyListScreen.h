#ifndef CLSCURRENCYLISTSCREEN_H
#define CLSCURRENCYLISTSCREEN_H
#include"clsCurrency.h"
#include"clsScreen.h"
#include<vector>
#include<iomanip>
class clsCurrencyListScreen:protected clsScreen
{
private:
static void _PrintCurrencyRecord(clsCurrency Currency);
public:
static void ShowCurrenciesList();
};
#endif