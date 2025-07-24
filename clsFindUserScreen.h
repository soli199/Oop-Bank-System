#ifndef CLSFINDUSERSCREEN_H
#define CLSFINDUSERSCREEN_H
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsFindUserScreen:protected clsScreen
{
private:
static void _PrintUser(clsUser User);
public:
static void ShowFindUserScreen();
};
#endif
