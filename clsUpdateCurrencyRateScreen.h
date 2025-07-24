#ifndef CLSUPDATECURRENCYRATESCREEN_H
#define CLSUPDATECURRENCYRATESCREEN_H
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
{
private:
static void _PrintCurrencyRecord(clsCurrency Currency);
static float _ReadRate();
public:
static void ShowUpdateCurrencyRateScreen();

};
#endif