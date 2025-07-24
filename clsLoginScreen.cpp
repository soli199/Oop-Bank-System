#include"clsLoginScreen.h"

bool clsLoginScreen::_Login()
{short loginfailds=0;
  bool LoginFaild= false;
  string UserName,Password;
  do
    {
      if(LoginFaild==true){
        loginfailds++;
        cout<<"\nInvalid UserName /Password ,Try Again\n";
      cout<<"You have "<<3-loginfailds<<" Trial(s) to login\n";
      }
      if(loginfailds==3)
      {
        cout<<"\nYou are locked after 3 trials\n\n";
        return false;
      }
      cout<<"\nEnter UserName:";
      cin>>UserName;
      cout<<"\nEnter Password:";
      cin>>Password;
      CurrentUser=clsUser::Find(UserName,Password);
      LoginFaild=CurrentUser.IsEmpty();
      
    }while(LoginFaild);
 CurrentUser.RegisterLogin();
clsMainScreen::ShowMainMenue();
 return true;
}
bool clsLoginScreen::ShowLoginScreen()
{
  (void)system("clear");
  clsScreen::_DrawHeaderScreen("Login Screen","");
  
 return _Login();
}
