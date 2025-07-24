#include"clsDepositeScreen.h"
void clsDepositeScreen::_PrintClient(clsBankClient C)
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
string clsDepositeScreen::_ReadAccountNumber()
{
  cout<<"\nPlease enter Account Number:";
  string AccountNumber=clsInputValidate::ReadString();
  return AccountNumber;
}
double clsDepositeScreen::_ReadAmount()
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
void clsDepositeScreen::ShowDepositeScreen()
{
  clsScreen::_DrawHeaderScreen("Deposite Screen","");
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
    Client.Deposite(Amount);
    cout<<"\nDone Successfully .";
    cout<<"\nNew Balance is: "<<Client.AccountBalance();
    cout<<endl;
  }
  else{
    cout<<"\nOperation is cancelled.\n";
  }
}