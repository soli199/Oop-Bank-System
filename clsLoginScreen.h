#ifndef CLSLOGINSCREEN_H
#define CLSLOGINSCREEN_H
#include"Global.h"
#include"clsUser.h"
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsMainScreen.h"

class clsLoginScreen:protected clsScreen
{
private:
static bool _Login();
public:
static bool ShowLoginScreen();
};
#endif
