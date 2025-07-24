#ifndef CLSDELETECLIENTSCREEN_H
#define CLSDELETECLIENTSCREEN_H
#include"clsScreen.h"
#include "clsBankClient.h"
#include<iomanip>
#include"Global.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
{
private:
static void _PrintClient(clsBankClient C);
public:
static void ShowDeleteClientScreen ();
};

#endif