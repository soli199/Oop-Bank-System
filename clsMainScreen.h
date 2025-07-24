#ifndef CLSMAINSCREEN_H
#define CLSMAINSCREEN_H
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"Global.h"
#include"clsClientListScreen.h"
#include"clsAddClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyMainScreen.h"
class clsMainScreen:protected clsScreen
{
private:
enum enMainMenueOptions{eListClients=1,eAddNewClient=2,eDeleteClient=3,eUpdateClient=4,eFindClient=5,eShowTransactionsMenue=6,eManageUsers=7,eLoginRegisters=8,eCurrencyExchange=9,eExit=10};
static short _ReadMainMenueOption();
static void _GoBackToMainMenue();
static void _ShowAllClientsScreen ();
static void _ShowAddNewClientScreen();
static void _ShowDeleteClientScreen();
static void _ShowUpdateClientScreen();
static void _ShowFindClientScreen();
static void _ShowTransactionsMenue();
static void _ShowManageUsersMenue();
static void _ShowLoginRegisterScreen ();
static void _ShowCurrencyExchangeScreen();
static void _ShowEndScreen();
static void PerformMainMenueOption(enMainMenueOptions MainMenueOption);
static void _Logout();
public:
static void ShowMainMenue();

};
#endif