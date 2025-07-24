#ifndef CLSTRANSACTIONSSCREEN_H
#define CLSTRANSACTIONSSCREEN_H
#include "clsScreen.h"
#include "clsMainScreen.h"
#include"Global.h"
#include"clsTransferScreen.h"
#include "clsTransferRegisterScreen.h"
#include"clsInputValidate.h"
class clsTransactionsScreen:protected clsScreen
{
private:
enum enTransactionsMenueOptions {
eDeposite=1,eWithdraw,eTransfer,eTransferLog,eTotalBalances,eMainMenue};
static short _ReadTransactionsMenueOptions();
static void _GoBackToTransactionsMenue();
static void _ShowDepositeScreen();
static void _ShowWithdrawScreen();
static void _ShowTotalBalancesScreen();
static void _ShowTransferLogScreen();
static void _ShowTransferScreen();
static void _PerformTransactionsOption(enTransactionsMenueOptions Choice);
public:
static void ShowTransactionsMenueScreen(); 

};
#endif