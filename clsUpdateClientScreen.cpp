#include"clsUpdateClientScreen.h"
void clsUpdateClientScreen::_PrintClient(clsBankClient C)
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
void clsUpdateClientScreen::_ReadClientInfo(clsBankClient &Client)
{
  cout<<"\nEnter First Name:";
  Client.SetFirstName(clsInputValidate::ReadString());
  cout<<"\nEnter Last Name:";
  Client.SetLastName(clsInputValidate::ReadString());
  cout<<"\nEnter Email:";
  Client.SetEmail(clsInputValidate::ReadString());
  cout<<"\nEnter Phone:";
  Client.SetPhone(clsInputValidate::ReadString());
  cout<<"\nEnter Pin Code:";
  Client.SetPinCode(clsInputValidate::ReadString());
  cout<<"\nEnter Balance:";
  Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
}
void clsUpdateClientScreen::ShowUpdateClientScreen ()
{ 
  if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epAddNewClient ))
  {return;}
  clsScreen::_DrawHeaderScreen("Update Client","");
string AccountNumber=""; 
 cout<<"Enter Account Number:"; AccountNumber=clsInputValidate::ReadString();
 while(!clsBankClient::IsClientExist(AccountNumber))
   {
     cout<<"\nClient With This Account Number Is Not Exists,Enter Another Number:";
     AccountNumber=clsInputValidate::ReadString();
   }
 clsBankClient Client=clsBankClient::Find(AccountNumber);
 _PrintClient(Client);
 char Answer='n';
 cout<<"\nAre you sure you want to update this client information?(y/n)?";
 cin>>Answer;
 if(Answer=='Y'||Answer=='y')
 {
 _ReadClientInfo(Client);
 }
 clsBankClient::enSaveResults Result;
Result=Client.Save();
 switch(Result)
   {
     case clsBankClient::enSaveResults::svSucceeded:
     cout<<"\nClient Updated successfully. \n";
     _PrintClient(Client);
     break;
     case clsBankClient::enSaveResults::svFaildEmptyObject:
     cout<<"\nError : Client Was Not Saved Because Is Empty\n";
     break;
     case clsBankClient::enSaveResults::svFaildAccountNumberExists:
     cout<<"\nError : Client Was Not Saved Because Account Number Is Used\n";
     break;
   }
}