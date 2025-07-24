#ifndef CLSUSER_H
#define CLSUSER_H
#include"clsPerson.h"
#include<fstream>
#include<vector>
#include"clsString.h"
#include<iostream>
#include<string>
#include"clsUtil.h"
#include"clsDate.h"
class clsUser:public clsPerson
{
private:
enum enMode{EmptyMode=0,UpdateMode,AddNewMode};
public:struct stLoginRegisterRecord{
string Date_Time;
string UserName;
string Password;
int Permissions;
};
private:
static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line,string Seperator="#//#");

enMode _Mode;
string _UserName;
string _Password;
int _Permissions;
bool _MarkForDelete=false;
static clsUser _ConvertLineToUserObject(string Line,string Seperator="#//#");
static string _ConvertUserObjectToLine(clsUser User,string Seperator="#//#");
static vector<clsUser> _LoadUsersDataFromFile();
static void _SaveUsersDataToFile(vector<clsUser>User);
string _PrepareLoginRecord(string Seperator="#//#");
static void _AddDataLineToFile(string DataLine);
void _Update();
void _AddNew();
static clsUser _GetEmptyUserObject();
public:

static vector<stLoginRegisterRecord>LoadRegistersData();
void RegisterLogin();
clsUser(enMode Mode,string FirstName,string LastName,string Email,string Phone,string UserName,string Password,int Permissions):clsPerson(FirstName,LastName,Email,Phone)
{
  _Mode=Mode;
  _UserName=UserName;
  _Password=Password;
  _Permissions=Permissions;
}
bool IsEmpty();
bool MarkedForDelete();
static bool IsUserExist(string UserName);
static bool IsUserExist(string UserName,string Password);
void SetUserName(string UserName);
string UserName();
void SetPassword(string Password);
string Password();
void SetPermissions(int Permissions);
int Permissions();
static clsUser Find(string UserName);
static clsUser Find(string UserName,string Password);
bool Delete();
static clsUser GetAddNewUserObject(string UserName);
static vector<clsUser>GetUsersList();
enum enSaveResults {svSucceeded=0,svFaildEmptyObject,svFaildUserExists};

enSaveResults Save();
enum enPermissions{epAll=-1,epListClients=1,epAddNewClient=2,epDeleteClient=4,epUpdateClient=8,epFindClient=16,epTransactions=32,epManageUsers=64,epLoginRegister=128};
bool CheckAccessPermission(enPermissions Permissions);
};
#endif