#include"clsLoginRegisterScreen.h"
void clsLoginRegisterScreen::_PrintRegisterRecord(clsUser::stLoginRegisterRecord Record)
{
  cout<<setw(20)<<left<<Record.Date_Time<<setw(10)<<left<<Record.UserName<<setw(10)<<left<<Record.Password<<setw(6)<<left<<Record.Permissions<<endl;
}
void clsLoginRegisterScreen::_PrintRegisterList(vector<clsUser::stLoginRegisterRecord >vRecords)
{cout<<"\n==========================================\n";
  cout<<setw(20)<<left<<"Date_Time"<<setw(10)<<left<<"UserName"<<setw(10)<<left<<"Password"<<setw(6)<<left<<"Permissions"<<endl;
 cout<<"\n==========================================\n";
 if(vRecords.size()==0)
   cout<<"\n\t\tNo Registers Available In The System \n";
 for(clsUser::stLoginRegisterRecord &Record:vRecords)
   {
     _PrintRegisterRecord (Record);
   }
}
void clsLoginRegisterScreen::ShowLoginRegisterScreen()
{
  if(!clsScreen::CheckAccessRights(clsUser::enPermissions::epLoginRegister))
  {
    return;
  }
  clsScreen::_DrawHeaderScreen("Reg. Logins Screen","");
  vector<clsUser::stLoginRegisterRecord >vRecord=clsUser::LoadRegistersData ();
  _PrintRegisterList(vRecord);
  cout<<"\n==========================================\n";
  cout<<"\n\t\t\tEnd Of Registers\n\n";
  cout<<"\n==========================================\n";
    
  
}