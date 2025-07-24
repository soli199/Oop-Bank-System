#ifndef CLSWITHDRAWSCREEN_H
#define CLSWITHDRAWSCREEN_H
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsWithdrawScreen:protected clsScreen
{
private:
static void _PrintClient(clsBankClient Client);
static string _ReadAccountNumber();
static double _ReadAmount();
public:
static void ShowWithdrawScreen();
};
#endif
