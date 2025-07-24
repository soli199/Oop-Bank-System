#include"clsDeleteUserScreen.h"
void clsDeleteUserScreen::_PrintUser(clsUser User)
{
     cout<<"\n=====================================\n";
        cout << "\nUser Card:";
        cout<<"\n======================================\n";
        cout << "\nFirstName   : " << User.FirstName();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " << User.Password();
        cout << "\nPermissions : " << User.Permissions();
        cout <<"\n=====================================\n";

}
void clsDeleteUserScreen::ShowDeleteUserScreen ()
{
  clsScreen::_DrawHeaderScreen("Delete User Screen ","");

  string UserName="";
  cout<<"\nEnter UserName:";
  UserName=clsInputValidate::ReadString();
  while(!clsUser::IsUserExist(UserName))
    {
      cout<<"\nUserName is not found,Enter another username:";
      UserName=clsInputValidate::ReadString();
    }
  clsUser User=clsUser::Find(UserName);
  _PrintUser(User);
  char Answer='n';
  cout<<"\nAre you sure you want to delete this user [y/n]?";
  cin>>Answer;
  if(Answer=='y'||Answer=='Y')
  {
    if(User.Delete())
    {
      cout<<"\nUser Deleted Successfully \n";
      _PrintUser(User);
    }
    else
      cout<<"\nError , User was not deleted \n";
    
  }
  else cout<<"\nOperation was cancelled \n";
}