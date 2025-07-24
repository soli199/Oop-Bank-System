#include"clsFindClientScreen.h"
void clsFindClientScreen::_PrintClient(clsBankClient C)
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
void clsFindClientScreen::ShowFindClientScreen ()
{
 if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epFindClient ))
 {return;}
   clsScreen::_DrawHeaderScreen("Find Client","");
  
  string AccountNumber ="";
  cout<<"Enter Account Number:";
  AccountNumber =clsInputValidate::ReadString ();
  while(!clsBankClient::IsClientExist (AccountNumber))
    {
      cout<<"\nClient number is not found, Try another number:";
      AccountNumber=clsInputValidate::ReadString();
    }
  clsBankClient Client=clsBankClient::Find (AccountNumber);
  if(Client.IsEmpty())
  {
    cout<<"\nClient is not found. \n";
  }
  else
  {
    cout<<"\nClient is found.\n";
  }
  _PrintClient(Client);
}