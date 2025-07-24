#include"clsTotalBalancesScreen.h"
void clsTotalBalancesScreen::_PrintClientRecordBalanceLine(clsBankClient Client)
{
  cout<<"|"<<setw(8)<<left<<Client.AccountNumber()<<"|"<<setw(20)<<left<<Client.FullName()<<"|"<<setw(12)<<left<<Client.AccountBalance();
  
}
void clsTotalBalancesScreen::ShowTotalBalancesScreen()
{
vector<clsBankClient>vClients=clsBankClient::GetClientsList();
  string Title="Total Balances Screen";
  string SubTitle="\t("+to_string(vClients.size())+")Client(s).";
  clsScreen::_DrawHeaderScreen(Title,SubTitle);
  
  
  cout<<"\n=======================================\n";
  cout<<"|"<<setw(7)<<left<<"Acc. No."<<"|"<<setw(20)<<left<<"  Client Name"<<"|"<<setw(12)<<left<<"Balance";
  cout<<"\n=======================================\n";
  double TotalBalances=clsBankClient::GetTotalBalances();
  if(vClients.size ()==0)
    cout<<"\t\tNo Clients Available In The System!\n";
  else
  {
    for(clsBankClient &Client:vClients)
      {
        _PrintClientRecordBalanceLine(Client);
        cout<<endl; 
      }
    cout<<"=======================================\n";
    cout<<"Total Balances = ("<<TotalBalances<<")"<<endl;
    cout<<"("<<clsUtil::NumberToText(TotalBalances)<<")"<<endl;
    
  }
}