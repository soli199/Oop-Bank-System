#include"clsScreen.h"

void clsScreen ::_DrawHeaderScreen(string Title,string SubTitle="")
{
  cout<<"  _______________________________\n";
  cout<<"          "<<Title<<endl;
  if(SubTitle!="")
   cout<<"          "<<SubTitle<<endl;
cout<<"  _______________________________\n";
  cout<<endl;
  cout<<"\tUser : "<<CurrentUser.UserName()<<endl;
  cout<<"\tDate : "<<clsDate::DateToString(clsDate())<<endl;
}
bool clsScreen::CheckAccessRights(clsUser::enPermissions Permission)

{if(!CurrentUser.CheckAccessPermission(Permission))
{cout<<"\n======================================\n";
  cout<<"\tAccess Denied,Contact Your Admin\n";
  cout<<"======================================\n";
 return false;
}
 else return true;
}
