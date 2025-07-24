#ifndef CLSADDNEWUSERSCREEN_H
#define CLSADDNEWUSERSCREEN_H
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
#include"clsInputValidate.h"
#include<iostream>
class clsAddNewUserScreen:protected clsScreen
{
private:
static clsUser _ReadUserInfo(clsUser&User);
static int _ReadPermissionsToSet();
static void _PrintUser(clsUser User);
public:
static void ShowAddNewUserScreen();
};
#endif