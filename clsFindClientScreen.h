#ifndef CLSFINDCLIENTSCREEN_H
#define CLSFINDCLIENTSCREEN_H
#include "clsScreen.h"
#include"clsBankClient.h"
#include"Global.h"
#include"clsInputValidate.h"
class clsFindClientScreen:protected clsScreen
{private:
static void _PrintClient(clsBankClient Client);
public:
static void ShowFindClientScreen();
};
#endif