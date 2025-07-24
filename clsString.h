#ifndef CLSSTRING_H
#define CLSSTRING_H

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class clsString {
private:
    string _Value;

public:
    clsString();
    clsString(string Value = "");
    void SetValue(string Value);
    string Value();
    
    static short length(string S);
    short length();
    static short CountWords(string S);
    short CountWords();
    static string UpperFirstLettersOfEachWord(string S);
    string UpperFirstLettersOfEachWord();
    static string LowerFirstLettersOfEachWord(string S);
    string LowerFirstLettersOfEachWord();
    static string UpperAllString(string S);
    string UpperAllString();
    static string LowerAllString(string S);
    string LowerAllString();
    static string InvertAllLettersCase(string S);
    string InvertAllLettersCase();
    static short CountCapitalLetters(string S);
    short CountCapitalLetters();
    static short CountSmallLetters(string S);
    short CountSmallLetters();
    static short CountSpecifiecLetter(string S, char C, bool matchcase);
    short CountSpecifiecLetter(char C, bool matchcase);
    static bool IsVowel(char C);
    static short CountVowels(string S);
    short CountVowels();
    static vector<string> Split(string S, string delim);
    vector<string> Split(string delim);
    static string TrimLeft(string S);
    string TrimLeft();
    static string TrimRight(string S);
    string TrimRight();
    static string Trim(string S);
    string Trim();
    static string JoinString(vector<string> vS, string delim);
    static string JoinString(string arrstring[], short length, string delim);
    static string ReverseWords(string S);
    string ReverseWords();
    static string ReplaceWord(string S, string StringToReplace, string StringToReplaceTo, bool matchcase);
    string ReplaceWord(string StringToReplace, string StringToReplaceTo, bool matchcase);
    static string RemovePunctuation(string S);
    string RemovePunctuation();
};

#endif