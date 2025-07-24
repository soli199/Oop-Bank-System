#ifndef CLSUSERSLISTSCREEN_H
#define CLSUSERSLISTSCREEN_H
#include"clsScreen.h"
#include<iomanip>
#include"clsUser.h"
#include<string>
class clsUsersListScreen:protected clsScreen
{private:
static void _PrintUserRecord(clsUser User);
public:
static void ShowUsersListScreen();

};
#endif