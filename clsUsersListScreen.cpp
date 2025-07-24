#include"clsUsersListScreen.h"
void clsUsersListScreen::_PrintUserRecord(clsUser User)
{
  cout<<"|"<<setw(10)<<left<<User.UserName()<<"|"<<setw(15)<<left<<User.FullName()<<"|"<<setw(12)<<left<<User.Phone()<<"|"<<setw(20)<<left<<User.Email()<<"|"<<setw(6)<<left<<User.Password()<<setw(6)<<left<<User.Permissions()<<"|"<<endl;
}
void clsUsersListScreen::ShowUsersListScreen()
{
  (void)system("clear");  vector<clsUser>vUsers=clsUser::GetUsersList();
  string Title="Users List Screen";
  string SubTitle="\t("+to_string(vUsers.size())+")User(s)"; clsScreen::_DrawHeaderScreen(Title,SubTitle);
  
  cout<<"====================================\n";
  cout<<"\n|"<<setw(10)<<left<<"UserName"<<"|"<<setw(15)<<left<<"FullName"<<"|"<<setw(12)<<left<<"Phone"<<"|"<<setw(20)<<left<<"Email"<<"|"<<setw(6)<<left<<"Password"<<"|"<<setw(6)<<left<<"Permissions"<<"|"<<endl;
  cout<<"====================================\n";
  if(vUsers.size()==0)
    cout<<"\nNo Users Available In The System!\n";
  for(clsUser&User:vUsers)
    {
      _PrintUserRecord(User);
    }
  cout<<"====================================\n";
  
}