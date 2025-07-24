#include"clsInputValidate.h"
bool clsInputValidate::IsNumberBetween(short Number,short From,short To)
{
  return (Number>=From&&Number<=To);
}
bool clsInputValidate::IsNumberBetween(int Number,int From,int To)
{
  return (Number>=From&&Number<=To);
}
bool clsInputValidate::IsNumberBetween(float Number,float From,float To)
{
  return (Number>=From&&Number<=To);
}
bool clsInputValidate::IsNumberBetween(double Number,double From,double To)
{
  return (Number>=From&&Number<=To);
}
bool clsInputValidate::IsDateBetween(clsDate Date,clsDate From,clsDate To)
{
  if((clsDate::IsDate1AfterDate2(Date,From)||clsDate::IsDate1EqualDate2 (Date,From))&&(clsDate::IsDate1BeforeDate2(Date,To)||clsDate::IsDate1EqualDate2 (Date,To)))
{
  return true;
}
  if((clsDate::IsDate1AfterDate2(Date,To)||clsDate::IsDate1EqualDate2 (Date,To))&&(clsDate::IsDate1BeforeDate2(Date,From)||clsDate::IsDate1EqualDate2 (Date,From)))
{
  return true;
}
  return false;
}
int clsInputValidate::ReadIntNumber(string Msg="Invalid Number,Enter again:")
{
  int number;
  while(!(cin>>number))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<Msg;
      cout<<endl;
    }
  return number;
}
int clsInputValidate::ReadIntNumberBetween(int From,int To,string Msg="Number is not within range,Enter again:")
{
  int t=ReadIntNumber();
  while(!IsNumberBetween(t,From,To))
    {
      cout<<Msg;
      t=ReadIntNumber ();
    }
  return t;
}
double clsInputValidate::ReadDbNumber(string Msg="Invalid Number,Enter again:")
{
  double number;
  while(!(cin>>number))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<Msg;
      cout<<endl;
    }
  return number;
}
string clsInputValidate::ReadString()
{
  string S="";
  getline(std::cin>>std::ws,S);
  return S;
  
}
double clsInputValidate::ReadDbNumberBetween(double From,double To,string Msg="Number is not within range,Enter again:")
{
  double t=ReadIntNumber();
  while(!IsNumberBetween(t,From,To))
    {
      cout<<Msg;
      t=ReadIntNumber ();
    }
  return t;
}
float clsInputValidate::ReadFloatNumber()
{
  float number;
  while(!(cin>>number))
    {
 cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\nInvalid number,Enter again:";
       
    }
  return number;
}
bool clsInputValidate::IsValidDate(clsDate Date)
{
return clsDate::IsValid(Date);
}
