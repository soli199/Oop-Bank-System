#ifndef CLSTOTALBALANCESSCREEN_H
#define CLSTOTALBALANCESSCREEN_H
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include<iomanip>
class clsTotalBalancesScreen:protected clsScreen
{
private:
static void _PrintClientRecordBalanceLine(clsBankClient Client);
public:
static void ShowTotalBalancesScreen();
};
#endif

