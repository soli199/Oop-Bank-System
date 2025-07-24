#ifndef CLSMANAGEUSERSSCREEN_H
#define CLSMANAGEUSERSSCREEN_H
#include<iostream>
#include"clsScreen.h"
#include"Global.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsManageUsersScreen:protected clsScreen
{
private:
enum enManageUsersMenueOptions{eListUsers=1,eAddNewUser,eDeleteUser,eUpdateUser,eFindUser,eMainMenu};
static short _ReadUsersMenueOption();
static void _GoBackToManageUsersMenue();
static void _ShowAllUsersScreen();
static void _AddNewUserScreen();
static void _DeleteUserScreen();
static void _UpdateUserScreen();
static void _FindUserScreen();
static void _PerformManageUsersMenueOption(enManageUsersMenueOptions Option);
public:
static void ShowManageUsersMenue();


};
#endif