#include"clsPerson.h"
clsPerson::clsPerson(string FirstName,string LastName,string Email,string Phone)
{
  _FirstName =FirstName;
  _LastName =LastName;
  _Email =Email;
  _Phone =Phone;
}
void clsPerson::SetFirstName(string FirstName)
{
 _FirstName =FirstName;
}
string clsPerson::FirstName ()
{
  return _FirstName;
}
void clsPerson::SetLastName (string LastName)
{
  _LastName =LastName;
}
string clsPerson::LastName()
{
  return _LastName;
}
void clsPerson::SetEmail(string Email)
{
  _Email=Email;
}
string clsPerson::Email()
{
  return _Email;
}
void clsPerson::SetPhone(string Phone)
{
  _Phone=Phone;
}
string clsPerson::Phone()
{
  return _Phone;
}

string clsPerson::FullName()
{
  return _FirstName+" "+_LastName;
}
void clsPerson::Print()
{cout<<"\nInfo:"<<endl;
 cout<<"_______________________"<<endl;
  cout<<"First Name: "<<_FirstName <<endl;
  cout<<"Last Name: "<<_LastName<<endl;
  cout<<"Email: "<<_Email<<endl;
  cout<<"Phone: "<<_Phone<<endl;
 cout<<"_______________________"<<endl;
}

