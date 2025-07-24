#include"clsUtil.h"
void clsUtil::Srand()
{
  srand((unsigned)time(NULL));
}
int clsUtil::RandomNumber(int from,int to)
{
  return rand()%(to-from+1)+from;
}
char clsUtil:: GetRandomCharacter(clsUtil::enCharType CharType)
{
  if(CharType==clsUtil::enCharType::Mix)
  {
    CharType=(clsUtil::enCharType)clsUtil::RandomNumber(1,3);
  }
  switch(CharType)
    {
      case(clsUtil::enCharType::SmallLetter):return(char)(clsUtil::RandomNumber(97,122));
      break;
      case(clsUtil::enCharType::CapitalLetter):return(char)(clsUtil::RandomNumber(65,90));
      break;
      case(clsUtil::enCharType::SpecialCharacter):return (char)(clsUtil::RandomNumber(33,47));
      break;
      case(clsUtil::enCharType::Digit):
      return (char)(clsUtil::RandomNumber(48,57));
      break;
      case(clsUtil::enCharType::Mix):
        return 0;
      break;
    }
}
string clsUtil::GenerateWord(clsUtil::enCharType CharType,short length)
{
  string Word="";
  for(int i=0;i<length;i++)
    {
      Word+=GetRandomCharacter(CharType);
    }
  return Word;
}
string clsUtil::GenerateKey(clsUtil::enCharType CharType)
{
  string Key="";
  Key=GenerateWord(CharType,4)+"-"+GenerateWord(CharType,4)+"-"+GenerateWord(CharType,4)+"-"+GenerateWord(CharType,4);
  return Key;
}
void clsUtil::GenerateKeys(short NumberOfKeys,clsUtil::enCharType CharType)
{
  for(int i=1;i<=NumberOfKeys;i++)
    {
      cout<<"Key["<<i<<"]:"<<GenerateKey(CharType)<<endl; 
    }
}
void clsUtil::FillArrayWithRandomNumbers(int arr[],short arrlength,int from,int to)
{
  for(int i=0;i<arrlength;i++)
    {
      arr[i]=clsUtil::RandomNumber(from,to);
    }
}
string clsUtil::NumberToText(int Number)
{

 if (Number == 0) {
 return "";
 }
 if (Number>=1&&Number<=19) {
 string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
 "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
 "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
 return arr[Number] + " ";
 }
 if (Number>=20&&Number<=99) {
 string arr[] = { 
"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
 return arr[Number / 10] + " " + NumberToText(Number%10);
 }
 if (Number >= 100 && Number <= 199)
 { return "One Hundred " + NumberToText(Number % 100);
 }
 if (Number >= 200 && Number <= 999)
 {
 return NumberToText(Number / 100) + "Hundreds " +
NumberToText(Number % 100);
 }
 if (Number >= 1000 && Number <= 1999)
 {
 return "One Thousand " + NumberToText(Number % 1000);
 }
 if (Number >= 2000 && Number <= 999999)
 {
 return NumberToText(Number / 1000) + "Thousands " +
NumberToText(Number % 1000);
 }
 if (Number >= 1000000 && Number <= 1999999)
 {
 return "One Million " + NumberToText(Number % 1000000);
 }
 if (Number >= 2000000 && Number <= 999999999)
 {
 return NumberToText(Number / 1000000) + "Millions " +
NumberToText(Number % 1000000);
 }
 if (Number >= 1000000000 && Number <= 1999999999)
 {
 return "One Billion " + NumberToText(Number % 1000000000);
 }
 else
 {
 return NumberToText(Number / 1000000000) + "Billions " +
NumberToText(Number % 1000000000);
 }
 }


void
clsUtil::FillArrayWithRandomWords(string arr[],short arrlength,clsUtil::enCharType CharType,short WordLength)
{
  for(int i=0;i<arrlength;i++)
    {
      arr[i]=clsUtil::GenerateWord(CharType,WordLength);
    }
}
void clsUtil::FillArrayWithRandomKeys(string arr[],short arrlength,clsUtil::enCharType CharType)
{
  for(int i=0;i<arrlength;i++)
    {
      arr[i]=clsUtil::GenerateKey(CharType);  
    }
}
void clsUtil::Swap(int&A,int&B)
{
  int temp=A;
  A=B;
  B=temp;
}
void clsUtil::Swap(float&A,float&B)
{
  float temp=A;
  A=B;
  B=temp;
}
void clsUtil::Swap(double &A,double &B)
{
  double temp=A;
  A=B;
  B=temp;
}
void clsUtil::Swap(bool&A,bool&B)
{
  bool temp=A;
  A=B;
  B=temp;
}
void clsUtil::Swap(char&A,char&B)
{
  char temp=A;
  A=B;
  B=temp;
}
void clsUtil::Swap(string&A,string&B)
{
  string temp=A;
  A=B;
  B=temp;
}
void clsUtil::Swap(clsDate&A,clsDate&B)
{
  clsDate::SwapDates(A,B);
}
void clsUtil::ShuffleArray(string arr[],short arrlength)
{
  for(int i=0;i<arrlength;i++)
    {
      Swap(arr[clsUtil::RandomNumber(0,arrlength-1)],arr[clsUtil::RandomNumber(0,arrlength-1)]);
    }
}
void clsUtil::ShuffleArray(int arr[],int arrlength)
{
  for(int i=0;i<arrlength;i++)
    {
      Swap(arr[clsUtil::RandomNumber(0,arrlength-1)],arr[clsUtil::RandomNumber(0,arrlength-1)]);
    }
}
string clsUtil::Tabs(short NumberOfTabs)
{
  string t="";
  for(int i=0;i<NumberOfTabs;i++)
    {
      t+="\t";
    }
  return t;
}
string clsUtil::EncryptText(string Text,short Key)
{
  for(int i=0;i<Text.length();i++)
    {
      Text[i]=char((int)Text[i]+Key);
    }
  return Text;
}
string clsUtil::DecryptText(string Text,short Key)
{
  for(int i=0;i<Text.length();i++)
    {
      Text[i]=char((int)Text[i]-Key);
    }
  return Text;
}


      
      
      
      
  