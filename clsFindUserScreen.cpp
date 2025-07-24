#include"clsFindUserScreen.h"
void clsFindUserScreen::_PrintUser(clsUser User) {
  cout << "\n=====================================";
  cout << "\nUser Card:";
  cout << "\n=====================================";
  cout << "\nFirstName   : " << User.FirstName();
  cout << "\nLastName    : " << User.LastName();
  cout << "\nFull Name   : " << User.FullName();
  cout << "\nEmail       : " << User.Email();
  cout << "\nPhone       : " << User.Phone();
  cout << "\nUser Name   : " << User.UserName();
  cout << "\nPassword    : " << User.Password();
  cout << "\nPermissions : " << User.Permissions();
  cout << "\n=====================================\n";
}
void clsFindUserScreen::ShowFindUserScreen()
{
  clsScreen::_DrawHeaderScreen("Find User Screen ","");
  
  string UserName="";
  cout<<"\nEnter UserName:"; UserName=clsInputValidate::ReadString();
  while(!clsUser::IsUserExist(UserName))
    {
      cout<<"\nUserName is not found,Enter another UserName:";
      UserName=clsInputValidate::ReadString();
    }
  clsUser User=clsUser::Find(UserName);
  if(!User.IsEmpty())
    cout<<"\nUser Found :-)\n";
  else cout<<"User is not found :-(\n";
  _PrintUser(User);
  
}