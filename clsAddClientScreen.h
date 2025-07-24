#ifndef CLSADDCLIENTSCREEN_H
#define CLSADDCLIENTSCREEN_H
#include"clsBankClient.h"
#include<iostream>
#include"clsScreen.h"
#include"Global.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddClientScreen:protected clsScreen
{
private:
static void _ReadClientInfo(clsBankClient &Client);
static void _PrintClient(clsBankClient Client);
public:
static void ShowAddNewClientScreen(); 
};
#endif