#ifndef CLSUPDATECLIENTSCREEN_H
#define CLSUPDATECLIENTSCREEN_H
#include "clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include"Global.h"
#include<iomanip>
class clsUpdateClientScreen:protected clsScreen
{
private:
static void _ReadClientInfo(clsBankClient &Client);
static void _PrintClient(clsBankClient C);
public:
static void ShowUpdateClientScreen();
};
#endif