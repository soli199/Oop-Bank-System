#ifndef CLSUTIL_H
#define CLSUTIL_H
#include "clsDate.h"
#include "clsString.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class clsUtil{
public:
static void Srand();
static int RandomNumber(int from,int to);
enum enCharType{SmallLetter=1,CapitalLetter=2,SpecialCharacter=3,Mix=4,Digit=5};
static char GetRandomCharacter(enCharType CharType);
static string GenerateWord(enCharType CharType,short Length);
static string GenerateKey(enCharType CharType);
static void GenerateKeys(short KeysNumber,enCharType CharType);
static void FillArrayWithRandomNumbers(int arr[],short arrlength,int from ,int to);
static void FillArrayWithRandomWords(string arr[],short arrlength,enCharType CharType,short Length);
static void Swap(int&A,int&B);
static void Swap(float&A,float&B);
static void Swap(double&A,double&B);
static void Swap(bool&A,bool&B);
static void Swap(char&A,char&B);
static void Swap(string&A,string&B);
static void Swap(clsDate&S,clsDate&B);
static void ShuffleArray(int arr[],short arrlength);
static void ShuffleArray(string arr[],short arrlength);
static void ShuffleArray(int arr[],int arrlength);
static string Tabs(short NumberOfTabs);
static void FillArrayWithRandomKeys(string arr[],short arrlength,enCharType CharType);
static string EncryptText(string Text,short Key);
static string DecryptText(string Text,short Key);
static string NumberToText(int Number);




};
#endif
