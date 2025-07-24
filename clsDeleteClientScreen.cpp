#include"clsDeleteClientScreen.h"
void clsDeleteClientScreen::_PrintClient(clsBankClient C)
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
void clsDeleteClientScreen::ShowDeleteClientScreen ()
{
  
  if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epDeleteClient ))
  
  {return;}
  clsScreen::_DrawHeaderScreen("Delete Client ","");
  
  string AccountNumber ="";
  cout<<"\nEnter Account Number:";
  AccountNumber=clsInputValidate::ReadString ();
  while(!clsBankClient::IsClientExist(AccountNumber))
    {
      cout<<"\nClient With This Number Is Not Exist,Enter another number:";
      AccountNumber =clsInputValidate::ReadString ();
    }
  clsBankClient Client=clsBankClient::Find(AccountNumber);
  _PrintClient(Client);
  char Answer='n';
  cout<<"\nAre you sure you want to delete this client?(y/n)?";
  cin>>Answer;
  if(Answer=='y'||Answer=='Y')
  {
    if(Client.Delete())
    {
      cout<<"\nCleint Deleted Successfully\n";
      _PrintClient(Client);
    }
    else
      cout<<"Error: Client Wasn't Deleted\n";
  }
}