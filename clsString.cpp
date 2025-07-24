#include "clsString.h"

clsString::clsString(string Value) {
    _Value = Value;
}
clsString::clsString() {
    _Value = "";
}


void clsString::SetValue(string Value) {
    _Value = Value;
}

string clsString::Value() {
    return _Value;
}

short clsString::length(string S) {
    return S.length();
}

short clsString::length() {
    return _Value.length();
}

short clsString::CountWords(string S) {
    string Sword = "";
    short Counter = 0;
    short Pos = 0;
    string delim = " ";
    while ((Pos = S.find(delim)) != string::npos) {
        Sword = S.substr(0, Pos);
        if (Sword != "") Counter++;
        S.erase(0, Pos + delim.length());
    }
    if (S != "") Counter++;
    return Counter;
}

short clsString::CountWords() {
    return CountWords(_Value);
}

string clsString::UpperFirstLettersOfEachWord(string S) {
    bool IsFirstLetter = true;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ' ' && IsFirstLetter) {
            S[i] = toupper(S[i]);
        }
        IsFirstLetter = (S[i] == ' ' ? true : false);
    }
    return S;
}

string clsString::UpperFirstLettersOfEachWord() {
    return UpperFirstLettersOfEachWord(_Value);
}

string clsString::LowerFirstLettersOfEachWord(string S) {
    bool IsFirstLetter = true;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ' ' && IsFirstLetter) {
            S[i] = tolower(S[i]);
        }
        IsFirstLetter = (S[i] == ' ' ? true : false);
    }
    return S;
}

string clsString::LowerFirstLettersOfEachWord() {
    return LowerFirstLettersOfEachWord(_Value);
}

string clsString::UpperAllString(string S) {
    for (int i = 0; i < S.length(); i++) {
        S[i] = toupper(S[i]);
    }
    return S;
}

string clsString::UpperAllString() {
    return UpperAllString(_Value);
}

string clsString::LowerAllString(string S) {
    for (int i = 0; i < S.length(); i++) {
        S[i] = tolower(S[i]);
    }
    return S;
}

string clsString::LowerAllString() {
    return LowerAllString(_Value);
}

string clsString::InvertAllLettersCase(string S) {
    for (int i = 0; i < S.length(); i++) {
        S[i] = isupper(S[i]) ? tolower(S[i]) : toupper(S[i]);
    }
    return S;
}

string clsString::InvertAllLettersCase() {
    return InvertAllLettersCase(_Value);
}

short clsString::CountCapitalLetters(string S) {
    short Count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (isupper(S[i])) Count++;
    }
    return Count;
}

short clsString::CountCapitalLetters() {
    return CountCapitalLetters(_Value);
}

short clsString::CountSmallLetters(string S) {
    short Count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (islower(S[i])) Count++;
    }
    return Count;
}

short clsString::CountSmallLetters() {
    return CountSmallLetters(_Value);
}

short clsString::CountSpecifiecLetter(string S, char C, bool matchcase) {
    short Count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (matchcase) {
            if (S[i] == C) Count++;
        } else {
            if (tolower(S[i]) == tolower(C)) Count++;
        }
    }
    return Count;
}

short clsString::CountSpecifiecLetter(char C, bool matchcase) {
    return CountSpecifiecLetter(_Value, C, matchcase);
}

bool clsString::IsVowel(char C) {
    C = tolower(C);
    return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u');
}

short clsString::CountVowels(string S) {
    short Count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (IsVowel(S[i])) Count++;
    }
    return Count;
}

short clsString::CountVowels() {
    return CountVowels(_Value);
}

vector<string> clsString::Split(string S, string delim) {
    vector<string> vS;
    short pos = 0;
    string Sword;
    while ((pos = S.find(delim)) != string::npos) {
        Sword = S.substr(0, pos);
         vS.push_back(Sword);
        S.erase(0, pos + delim.length());
    }
    if (S != "") vS.push_back(S);
    return vS;
}

vector<string> clsString::Split(string delim) {
    return Split(_Value, delim);
}

string clsString::TrimLeft(string S) {
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ' ') return S.substr(i, S.length() - i);
    }
    return "";
}

string clsString::TrimLeft() {
    return TrimLeft(_Value);
}

string clsString::TrimRight(string S) {
    for (int i = S.length() - 1; i >= 0; i--) {
        if (S[i] != ' ') return S.substr(0, i + 1);
    }
    return "";
}

string clsString::TrimRight() {
    return TrimRight(_Value);
}

string clsString::Trim(string S) {
    return TrimLeft(TrimRight(S));
}

string clsString::Trim() {
    return Trim(_Value);
}

string clsString::JoinString(vector<string> vS, string delim) {
    string S = "";
    for (string &s : vS) S += s + delim;
    return S.substr(0, S.length() - delim.length());
}

string clsString::JoinString(string arrstring[], short length, string delim) {
    string S = "";
    for (int i = 0; i < length; i++) S += arrstring[i] + delim;
    return S.substr(0, S.length() - delim.length());
}

string clsString::ReverseWords(string S) {
    vector<string> vS = Split(S, " ");
    string S2 = "";
    vector<string>::iterator iter = vS.end();
    while (iter != vS.begin()) {
        --iter;
        S2 += *iter + " ";
    }
    return S2.substr(0, S2.length() - 1);
}

string clsString::ReverseWords() {
    return ReverseWords(_Value);
}

string clsString::ReplaceWord(string S, string StringToReplace, string StringToReplaceTo, bool matchcase) {
    vector<string> vS = Split(S, " ");
    for (string &s : vS) {
        if (matchcase) {
            if (s == StringToReplace) s = StringToReplaceTo;
        } else {
            if (LowerAllString(s) == LowerAllString(StringToReplace)) s = StringToReplaceTo;
        }
    }
    return JoinString(vS, " ");
}

string clsString::ReplaceWord(string StringToReplace, string StringToReplaceTo, bool matchcase) {
    return ReplaceWord(_Value, StringToReplace, StringToReplaceTo, matchcase);
}

string clsString::RemovePunctuation(string S) {
    string S2 = "";
    for (int i = 0; i < S.length(); i++) {
        if (!ispunct(S[i])) S2 += S[i];
    }
    return S2;
}

string clsString::RemovePunctuation() {
    return RemovePunctuation(_Value);
}