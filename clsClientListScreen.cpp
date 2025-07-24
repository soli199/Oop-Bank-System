#include"clsClientListScreen.h"
void clsClientScreen::_PrintClientRecordLine(clsBankClient Client)
{
  cout<<"|"<<setw(6)<<left<<Client.AccountNumber()<<"|"<<setw(15)<<left<<Client.FullName()<<"|"<<setw(10)<<left<<Client.Phone()<<"|"<<setw(20)<<left<<Client.Email()<<"|"<<setw(5)<<left<<Client.PinCode()<<"|"<<setw(5)<<left<<Client.AccountBalance()<<"|"<<endl;
}
void clsClientScreen::ShowAllClientsScreen()
{
  if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epListClients))
  {return;
  }
  vector<clsBankClient>vClients=clsBankClient::GetClientsList();
  string Title="Client List Screen";
  string SubTitle="("+to_string(vClients.size())+")Clients (s).";  clsScreen::_DrawHeaderScreen(Title,SubTitle);
  
  cout<<"========================================\n";
  cout<<"|"<<setw(6)<<left<<"Acc.No"<<"|"<<setw(15)<<left<<"Clinet Name"<<"|"<<setw(10)<<left<<"Phone"<<"|"<<setw(20)<<left<<"Email"<<"|"<<setw(5)<<left<<"Pin Code"<<"|"<<setw(5)<<left<<"Balance"<<"|"<<endl;
  cout<<"========================================\n";
  if(vClients.size()==0)
    cout<<"\t\tNo Clients Available In The System. \n";
  else{
    for(clsBankClient &Client:vClients)
      {
        _PrintClientRecordLine(Client);
      }}
  cout<<"=========================================\n";
  
}