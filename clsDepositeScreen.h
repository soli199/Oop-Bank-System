#ifndef CLSDEPOSITESCREEN_H
#define CLSDEPOSITESCREEN_H
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsDepositeScreen:protected clsScreen
{
private:
static void _PrintClient(clsBankClient Client);
static string _ReadAccountNumber();
static double _ReadAmount();
public:
static void ShowDepositeScreen();
};
#endif
