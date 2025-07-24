#ifndef CLSCLIENTLISTSCREEN_H
#define CLSCLIENTLISTSCREEN_H
#include"clsScreen.h"
#include "clsBankClient.h"
#include<iomanip>
#include<iostream>
#include"Global.h"
class clsClientScreen:protected clsScreen
{
private:
static void _PrintClientRecordLine(clsBankClient Client);
public:
static void ShowAllClientsScreen();
};
#endif

