#include <iostream>
#ifndef CLSSCREEN_H
#define CLSSCREEN_H
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
  protected:
  static void _DrawHeaderScreen(string Title,string SubTitle);
static bool CheckAccessRights(clsUser::enPermissions Permission);
static void PrintUserLogin_Date();
};
#endif