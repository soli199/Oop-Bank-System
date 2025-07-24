#ifndef CLSDATE_H
#define CLSDATE_H
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include<iomanip>

#include "clsString.h"
#include <string>

class clsDate {
private:
    short _day;
    short _month;
    short _year;

public:
    clsDate(short Day, short Month, short Year);
    clsDate();
clsDate(string Date);
clsDate(short DateOrderInYear,short Year);
void SetDay(short Day);
short Day();
void SetMonth(short Month);
short Month();
void SetYear(short Year);
short Year();
static string DateToString(clsDate Date);
string DateToString ();
void Print();
static clsDate GetSystemDate();
static bool IsValid(clsDate Date);
bool IsValid();
static bool IsLeapYear(short Year);
bool IsLeapYear();
static int NumberOfDaysInAYear(short Year);
int NumberOfDaysInAYear();
static int NumberOfHoursInAYear(short Year);
int NumberOfHoursInAYear();
static int NumberOfMinutesInAYear(short Year);
int NumberOfMinutesInAYear();
static int NumberOfSecondsInAYear(short Year);
int NumberOfSecondsInAYear();
static int NumberOfDaysInAMonth(short Month,short Year);
int NumberOfDaysInAMonth();
static int NumberOfHoursInAMonth(short Month,short Year);
int NumberOfHoursInAMonth ();
static int NumberOfMinutesInAMonth(short Month,short Year);
int NumberOfMinutesInAMonth();
static int NumberOfSecondsInAMonth(short Month,short Year);
int NumberOfSecondsInAMonth();
static short DayOfWeekOrder(short Day,short Month,short Year);
short DayOfWeekOrder();
static string DayShortName(short DayOfWeekOrder);
static string DayShortName(short Day,short Month,short Year);
string DayShortName();
static string MonthShortName(short MonthNumber);
string MonthShortName();
static void PrintMonthCalendar(short Month,short Year);
void PrintMonthCalendar();
static void PrintYearCalendar(short Year);
static string GetSystemDateTimeString();
void PrintYearCalendar();
static short DaysFromBeginingOfYear(short Day,short Month,short Year);
short DaysFromBeginingOfYear();
static clsDate GetDateFromDayOrderInYear(short DayOrder,short Year);
clsDate GetDateFromDayOrderInYear(short DayOrder);
void AddDays(short Days);
static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2);
bool IsDateBeforeDate2(clsDate Date2);
static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2);
bool IsDateEqualDate2(clsDate Date2);
static bool IsLastDayInMonth(clsDate Date);
bool IsLastDayInMonth();
static bool IsLastMonthInYear(short Month);
static clsDate AddOneDay(clsDate Date);
void AddOneDay();
static void  SwapDates(clsDate & Date1, clsDate & Date2);
static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false);
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false);
static short CalculateMyAgeInDays(clsDate DateOfBirth);
static clsDate IncreaseDateByOneWeek(clsDate &Date);
void IncreaseDateByOneWeek();
clsDate IncreaseDateByXWeeks(short Weeks, clsDate &Date);
void IncreaseDateByXWeeks(short Weeks) ;

clsDate IncreaseDateByOneMonth(clsDate &Date);
void IncreaseDateByOneMonth() ;
clsDate IncreaseDateByXDays(short Days, clsDate &Date);
void IncreaseDateByXDays(short Days);
clsDate IncreaseDateByXMonths(short Months, clsDate &Date);
void IncreaseDateByXMonths(short Months);
static clsDate IncreaseDateByOneYear(clsDate &Date);

void IncreaseDateByOneYear() ;
clsDate IncreaseDateByXYears(short Years, clsDate &Date) ;
void IncreaseDateByXYears(short Years);
clsDate IncreaseDateByOneDecade(clsDate &Date);
void IncreaseDateByOneDecade();
clsDate IncreaseDateByXDecades(short Decade, clsDate &Date);
void IncreaseDateByXDecades(short Decade);
clsDate IncreaseDateByOneCentury(clsDate &Date) ;
void IncreaseDateByOneCentury();
clsDate IncreaseDateByOneMillennium(clsDate &Date) ;
clsDate IncreaseDateByOneMillennium();
static clsDate DecreaseDateByOneDay(clsDate Date);
void DecreaseDateByOneDay();
static clsDate DecreaseDateByOneWeek(clsDate &Date) ;
void DecreaseDateByOneWeek();
static clsDate DecreaseDateByXWeeks(short Weeks, clsDate &Date);
void DecreaseDateByXWeeks(short Weeks) ;
static clsDate DecreaseDateByOneMonth(clsDate &Date);
void DecreaseDateByOneMonth();
static clsDate DecreaseDateByXDays(short Days, clsDate &Date);
void DecreaseDateByXDays(short Days);
static clsDate DecreaseDateByXMonths(short Months, clsDate &Date);
void DecreaseDateByXMonths(short Months);
static clsDate DecreaseDateByOneYear(clsDate &Date) ;
void DecreaseDateByOneYear();
static clsDate DecreaseDateByXYears(short Years, clsDate &Date);
void DecreaseDateByXYears(short Years) ;
static clsDate DecreaseDateByOneDecade(clsDate &Date) ;
void DecreaseDateByOneDecade();
static clsDate DecreaseDateByXDecades(short Decades, clsDate &Date) ;
void DecreaseDateByXDecades(short Decades);
static clsDate DecreaseDateByOneCentury(clsDate &Date);
void DecreaseDateByOneCentury();
static clsDate DecreaseDateByOneMillennium(clsDate &Date) ;
void DecreaseDateByOneMillennium();
static short IsEndOfWeek(clsDate Date) ;
short IsEndOfWeek() ;
static bool IsWeekEnd(clsDate Date);
bool IsWeekEnd() ;
static bool IsBusinessDay(clsDate Date) ;
bool IsBusinessDay();
static short DaysUntilTheEndOfWeek(clsDate Date);
short DaysUntilTheEndOfWeek();
static short DaysUntilTheEndOfMonth(clsDate Date1);
short DaysUntilTheEndOfMonth() ;
static short DaysUntilTheEndOfYear(clsDate Date1);
short DaysUntilTheEndOfYear() ;
static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) ;
static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) ;
static clsDate CalculateVacationReturnDate(clsDate DateFrom,short VacationDays);
static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2);
bool IsDateAfterDate2(clsDate Date2);
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
static enDateCompare CompareDates(clsDate Date1, clsDate Date2);
enDateCompare CompareDates(clsDate Date2);
};

#endif