#ifndef CLSPERSON_H
#define CLSPERSON_H
#include<iostream>
#include<string>
using namespace std;
class clsPerson{
private:
string _FirstName;
string _LastName;
string _Email;
string _Phone;
public:
clsPerson(string FirstName,string LastName,string Email,string Phone);
void SetFirstName(string FirstName);
string FirstName ();
void SetLastName(string LastName);
string LastName ();
void SetEmail(string Email);
string Email();
void SetPhone(string Phone);
string Phone();

string FullName();
void Print();

};
#endif
