#ifndef CLSLOGINREGISTERSCREEN_H
#define CLSLOGINREGISTERSCREEN_H
#include "clsString.h"
#include"clsScreen.h"
#include"clsUser.h"
class clsLoginRegisterScreen :protected clsScreen
{
private:
static void _PrintRegisterRecord(clsUser::stLoginRegisterRecord Record);
static void _PrintRegisterList(vector<clsUser::stLoginRegisterRecord >Records);

public:
static void ShowLoginRegisterScreen();
};
#endif