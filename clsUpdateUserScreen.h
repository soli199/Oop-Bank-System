#ifndef CLSUPDATEUSERSCREEN_H
#define CLSUPDATEUSERSCREEN_H
#include "clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsUpdateUserScreen:protected clsScreen
{
private:
static clsUser _ReadUserInfo(clsUser &User);
static int _ReadPermissionsToSet();
static void _PrintUser(clsUser User);
public:
static void ShowUpdateUserScreen();

};
#endif