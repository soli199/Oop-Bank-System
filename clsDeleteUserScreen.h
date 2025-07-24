#ifndef CLSDELETEUSERSCREEN_H
#define CLSDELETEUSERSCREEN_H
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
class clsDeleteUserScreen:protected clsScreen
{
private:
static void _PrintUser(clsUser User);
public:
static void ShowDeleteUserScreen();
};
#endif