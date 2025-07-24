#include"clsAddClientScreen.h"
void clsAddClientScreen::_ReadClientInfo(clsBankClient &Client)
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
void clsAddClientScreen::_PrintClient(clsBankClient C)
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
void clsAddClientScreen::ShowAddNewClientScreen()
{if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epAddNewClient ))
 {return;
 }
   clsScreen::_DrawHeaderScreen("Add New Client","");
 
 string AccountNumber="";
 cout<<"Enter Account Number: ";
 AccountNumber=clsInputValidate::ReadString();
 while(clsBankClient::IsClientExist(AccountNumber))
   {
     cout<<"\nClient With This Number Is Exist, Enter another number;";
     AccountNumber =clsInputValidate::ReadString ();
   }
 clsBankClient Client=clsBankClient::GetAddNewClientObject(AccountNumber);
 clsAddClientScreen::_ReadClientInfo(Client);
 clsBankClient::enSaveResults SaveResults;
 SaveResults=Client.Save();
 switch(SaveResults)
   {
     case clsBankClient::enSaveResults::svSucceeded:
     cout<<"\nClient Added Succseccfully.\n";
     _PrintClient(Client);
     break;
     case clsBankClient::enSaveResults::svFaildEmptyObject:
 
 cout << "\nError account was not saved because it's Empty";
 break;
 
 case clsBankClient::enSaveResults::svFaildAccountNumberExists:
 
 cout << "\nError account was not saved because account number is used!\n";
 
       
   
}
}