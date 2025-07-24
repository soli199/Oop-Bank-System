#include"clsWithdrawScreen.h"
void clsWithdrawScreen::_PrintClient(clsBankClient C)
{cout<<"========================\n";
  cout<<"\n.  Client Card.\n";
 cout<<"========================\n";
 cout<<"First Name: "<<C.FirstName();
 cout<<"\nLast Name: "<<C.LastName();
 cout<<"\nFull Name: "<<C.FullName();
 cout<<"\nEmail: "<<C.Email();
 cout<<"\nPhone: "<<C.Phone();
 cout<<"\nAccount Number: "<<C.AccountNumber();
 cout<<"\nPassword: "<<C.PinCode();
 cout<<"\nBalance: "<<C.AccountBalance ();
 cout<<"\n=======================\n";
}
string clsWithdrawScreen::_ReadAccountNumber()
{
  cout<<"\nPlease enter Account Number:";
  string AccountNumber=clsInputValidate::ReadString();
  return AccountNumber;
}
double clsWithdrawScreen::_ReadAmount()
{
  double Amount=0;
  cout<<"\nPlease enter Deposite Amount:";
  Amount=clsInputValidate::ReadDbNumber("Invalid Amount,Enter again:");
  while(Amount<=0)
    {
      cout<<"\nAmount must be greater than zero,Enter again:";
      Amount=clsInputValidate::ReadDbNumber("Invalid Amount,Enter again:");
      
    }
  return Amount;  
}
void clsWithdrawScreen::ShowWithdrawScreen()
{
  clsScreen::_DrawHeaderScreen("Withdraw Screen","");
  
  string AccountNumber =_ReadAccountNumber();
  while(!clsBankClient::IsClientExist(AccountNumber))
    {
      cout<<"\nClient with ["<<AccountNumber<<"] does not exist.\n";
      AccountNumber=_ReadAccountNumber();
    }
  clsBankClient Client =clsBankClient::Find(AccountNumber);
  _PrintClient(Client);
  double Amount =_ReadAmount();
  char Answer='n';
  cout<<"Are you sure you want to perform this transaction? y/n?";
  cin>>Answer;
if(Answer=='y'||Answer=='Y')
   {
   if(Client.Withdraw(Amount))
    {
cout << "\nAmount Withdrew Successfully.\n";
cout << "\nNew Balance Is: " << Client.AccountBalance();
    }
else
  {
cout << "\nCannot withdraw, Insuffecient Balance!\n";
cout << "\nAmout to withdraw is: " << Amount;
cout << "\nYour Balance is: " << Client.AccountBalance()<<endl;
  cout<<"\nDo you want to withdraw less amount? y/n?";
  cin>>Answer;
  if(Answer=='y'||Answer=='Y')
   {
      #ifdef _WIN32
  system("pause");
#else

  cout << "\nPress any key to try again....\n";

  cin.ignore();
  cin.get();
#endif
  (void)system("clear");
   ShowWithdrawScreen();
  }
  }
   }
else
{ cout << "\nOperation was cancelled.\n"; }
}
  