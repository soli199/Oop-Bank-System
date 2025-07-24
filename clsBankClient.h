#ifndef CLSBANKCLIENT_H
#define CLSBANKCLIENT_H
#include"clsPerson.h"
#include"clsString.h"
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class clsBankClient:public clsPerson
{public: struct stTransferLogRecord{
string DateTime;
string SourceAccountNumber;
string DestinationAccountNumber;
double Amount;
double SourceBalance;
double DestinationBalance;
string UserName;
};
private:
enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
enMode _Mode;
string _AccountNumber;
string _PinCode;
float _AccountBalance;
bool _MarkForDelete=false;
static clsBankClient _ConvertLineToClientObject(string Line,string Seperator="#//#");

static clsBankClient _GetEmptyClientObject();
string _PrepareTransferLogRecord(double Amount,clsBankClient DestinationClient,string UserName,string Seperator="#//#");
void _RegisterTransferLogRecord(double Amount,clsBankClient DestinationClient,string UserName);

static string _ConvertClientObiectToLine(clsBankClient Client,string Seperator="#//#");

static vector<clsBankClient >_LoadClientsDataFromFile ();

static void _SaveClientsDataToFile (vector <clsBankClient >vClients);

void _Update();
void _AddNew();
static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line,string Seperator ="#//#");

void _AddDataLineToFile (string Line);

public:

static vector<stTransferLogRecord> GetTransferData();

clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
{
  _Mode=Mode;
  _AccountNumber=AccountNumber;
  _PinCode=PinCode;
  _AccountBalance =AccountBalance;
}


bool IsEmpty();

string AccountNumber ();

void SetPinCode(string PinCode);
string PinCode ();
void SetAccountBalance(float AccountBalance);
float AccountBalance ();
void Print();
static clsBankClient Find(string AccountNumber);
static clsBankClient Find(string AccountNumber,string PinCode);


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svFaildAccountNumberExists=2 };

    enSaveResults Save();
static bool IsClientExist(string AccountNumber);
static bool IsClientExist (string AccountNumber,string PinCode);
static clsBankClient GetAddNewClientObject(string AccountNumber);
bool MarkedForDelete();
bool Delete();
bool Transfer(double Amount,clsBankClient &DestinationClient,string UserName);
static vector<clsBankClient >GetClientsList();
static float GetTotalBalances();
void Deposite(double Amount);
bool Withdraw(double Amount);

};
#endif