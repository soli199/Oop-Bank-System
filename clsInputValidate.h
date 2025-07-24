#ifndef CLSINPUTVALIDATE_H
#define CLSINPUTVALIDATE_H
#include<iostream>
#include<limits>
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
public:
static bool IsNumberBetween(short Number,short From,short To);
static bool IsNumberBetween(int Number,int From,int To);
static bool IsNumberBetween(float Number,float From,float To);
static bool IsNumberBetween(double Number,double From,double To );
static bool IsDateBetween(clsDate Date,clsDate From,clsDate To);
static int ReadIntNumber(string Msg);
static int ReadIntNumberBetween(int From,int To,string Msg);
static double ReadDbNumber(string Msg);
static string ReadString();
static float ReadFloatNumber();
static double ReadDbNumberBetween(double From,double To,string Msg);
static bool IsValidDate(clsDate);
};
#endif