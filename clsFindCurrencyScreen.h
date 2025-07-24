#ifndef CLSFINDCURRENCYSCREEN_H
#define CLSFINDCURRENCYSCREEN_H
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsFindCurrencyScreen:protected clsScreen
{
private:
static void _PrintCurrencyRecord(clsCurrency Currency );
static void _ShowResults(clsCurrency Currency);
public:
static void ShowFindCurrencyScreen();
};
#endif