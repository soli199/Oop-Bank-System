#include "clsDate.h"
clsDate::clsDate() {
  time_t t = time(0);
  tm *now = localtime(&t);
  _day = now->tm_mday;
  _month = now->tm_mon + 1;
  _year = now->tm_year + 1900;
}
clsDate::clsDate(string Date) {
  vector<string> vDate = clsString::Split(Date, "/");
  _day = stoi(vDate[0]);
  _month = stoi(vDate[1]);
  _year = stoi(vDate[2]);
  if (!IsValid()) {
    _day = 0;
    _month = 0;
    _year = 0;
  }
}
clsDate::clsDate(short Day, short Month, short Year) {
  _day = Day;
  _month = Month;
  _year = Year;
}
clsDate::clsDate(short DateOrderInYear, short Year) {
  clsDate D = GetDateFromDayOrderInYear(DateOrderInYear, Year);
  _day = D._day;
  _month = D._month;
  _year = D._year;
}
void clsDate::SetDay(short Day) { _day = Day; }
short clsDate::Day() { return _day; }
void clsDate::SetMonth(short Month) { _month = Month; }
short clsDate::Month() { return _month; }
void clsDate::SetYear(short Year) { _year = Year; }
short clsDate::Year() { return _year; }
string clsDate::DateToString(clsDate Date) {
  return to_string(Date._day) + "/" + to_string(Date._month) + "/" +to_string(Date._year);
  
}
 string clsDate::GetSystemDateTimeString()
{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

string clsDate::DateToString() { return DateToString(*this); }
void clsDate::Print() { cout << DateToString(*this); 
cout<<endl;
                      }
clsDate clsDate::GetSystemDate() {
  clsDate D;
  time_t t = time(0);
  tm *now = localtime(&t);
  D._day = now->tm_mday;
  D._month = now->tm_mon + 1;
  D._year = now->tm_year + 1900;
  return D;
}
bool clsDate::IsValid(clsDate Date) {
  if (Date._day < 1 || Date._day > 31)
    return false;
  if (Date._month < 1 || Date._month > 12)
    return false;
  if (Date._year < 1)
    return false;
  if (Date._month == 2)
    if (Date._day > 29)
      return false;
  short MonthDays = NumberOfDaysInAMonth(Date._month, Date._year);
  if (Date._day > MonthDays)
    return false;
  return true;
}
bool clsDate::IsValid() { return IsValid(*this); }
bool clsDate::IsLeapYear(short Year) {
  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
bool clsDate::IsLeapYear() { return IsLeapYear(_year); }
int clsDate::NumberOfDaysInAYear(short Year) {
  return IsLeapYear(Year) ? 366 : 365;
}
int clsDate::NumberOfDaysInAYear() { return NumberOfDaysInAYear(_year); }
int clsDate::NumberOfHoursInAYear(short Year) {
  return NumberOfDaysInAYear(Year) * 24;
}
int clsDate::NumberOfHoursInAYear() { return NumberOfHoursInAYear(_year); }
int clsDate::NumberOfMinutesInAYear(short Year) {
  return NumberOfHoursInAYear(Year) * 60;
}
int clsDate::NumberOfMinutesInAYear() { return NumberOfMinutesInAYear(_year); }
int clsDate::NumberOfSecondsInAYear(short Year) {
  return NumberOfMinutesInAYear(Year) * 60;
}
int clsDate::NumberOfSecondsInAYear() { return NumberOfSecondsInAYear(_year); }
int clsDate::NumberOfDaysInAMonth(short Month, short Year) {
  int Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}
int clsDate::NumberOfDaysInAMonth() {
  return NumberOfDaysInAMonth(_month, _year);
}
int clsDate::NumberOfHoursInAMonth(short Month, short Year) {
  return NumberOfDaysInAMonth(Month, Year) * 24;
}
int clsDate::NumberOfHoursInAMonth() {
  return NumberOfHoursInAMonth(_month, _year);
}
int clsDate::NumberOfMinutesInAMonth(short Month, short Year) {
  return NumberOfHoursInAMonth(Month, Year) * 60;
}
int clsDate::NumberOfMinutesInAMonth() {
  return NumberOfMinutesInAMonth(_month, _year);
}
int clsDate::NumberOfSecondsInAMonth(short Month, short Year) {
  return NumberOfMinutesInAMonth(Month, Year) * 60;
}
int clsDate::NumberOfSecondsInAMonth() {
  return NumberOfSecondsInAMonth(_month, _year);
}
short clsDate::DayOfWeekOrder(short Day, short Month, short Year) {
  short a, y, m;
  a = (14 - Month) / 12;
  y = Year - a;
  m = Month + 12 * a - 2;
  return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short clsDate::DayOfWeekOrder() { return DayOfWeekOrder(_day, _month, _year); }
string clsDate::DayShortName(short DayOfWeekOrder) {
  string Days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return Days[DayOfWeekOrder];
}
string clsDate::DayShortName(short Day, short Month, short Year) {
  string Days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return Days[DayOfWeekOrder(Day, Month, Year)];
}
string clsDate::DayShortName() { return DayShortName(_day, _month, _year); }
string clsDate::MonthShortName(short MonthNumber) {
  string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  return Months[MonthNumber - 1];
}
string clsDate::MonthShortName() { return MonthShortName(_month); }
void clsDate::PrintMonthCalendar(short Month, short Year) {
  short current = DayOfWeekOrder(1, Month, Year);
  short end = NumberOfDaysInAMonth(Month, Year);
  cout << "____________" << MonthShortName(Month) << "____________" << endl;
  cout << "Sun  Mon  Tue. Wed. Thu. Fri  Sat" << endl;
  short i;
  for (i = 0; i < current; i++)
    cout << "     ";
  for (short j = 1; j <= end; j++) {
    cout << setw(5) << j;
    if (++i == 7) {
      i = 0;
      cout << endl;
    }
  }
}
void clsDate::PrintMonthCalendar() { PrintMonthCalendar(_month, _year); }
void clsDate::PrintYearCalendar(short Year) {
  cout << "____________" << Year << "____________" << endl;
  for (short i = 1; i <= 12; i++) {
    PrintMonthCalendar(i, Year);
    cout << endl;
  }
}
void clsDate::PrintYearCalendar() { PrintYearCalendar(_year); }
short clsDate::DaysFromBeginingOfYear(short Day, short Month, short Year) {
  short Days = 0;
  for (short i = 1; i < Month; i++)
    Days += NumberOfDaysInAMonth(i, Year);
  return Days + Day;
}
short clsDate::DaysFromBeginingOfYear() {
  return DaysFromBeginingOfYear(_day, _month, _year);
}
clsDate clsDate::GetDateFromDayOrderInYear(short DayOrder, short Year) {
  clsDate Date;
  short Month = 1;
  short MonthDays = 0;
  while (true) {
    MonthDays = NumberOfDaysInAMonth(Month, Year);

    if (DayOrder > MonthDays) {
      DayOrder -= MonthDays;
      Month++;
    } else {
      Date.SetDay(DayOrder);
      Date.SetMonth(Month);
      Date.SetYear(Year);
      break;
    }
  }
  return Date;
}
clsDate clsDate::GetDateFromDayOrderInYear(short DayOrder) {
  return GetDateFromDayOrderInYear(DayOrder, _year);
}

void clsDate::AddDays(short Days) {

  short RemainingDays = Days + DaysFromBeginingOfYear(_day, _month, _year);
  short MonthDays = 0;

  _month = 1;

  while (true) {
    MonthDays = NumberOfDaysInAMonth(_month, _year);

    if (RemainingDays > MonthDays) {
      RemainingDays -= MonthDays;
      _month++;

      if (_month > 12) {
        _month = 1;
        _year++;
      }
    } else {
      _day = RemainingDays;
      break;
    }
  }
}
bool clsDate::IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
  return (Date1.Year() < Date2.Year())
             ? true
             : ((Date1.Year() == Date2.Year())
                    ? (Date1.Month() < Date2.Month()
                           ? true
                           : (Date1.Month() == Date2.Month()
                                  ? Date1.Day() < Date2.Day()
                                  : false))
                    : false);
}

bool clsDate::IsDateBeforeDate2(clsDate Date2) {
  // note: *this sends the current object :-)
  return IsDate1BeforeDate2(*this, Date2);
}

bool clsDate::IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
  return (Date1.Year() == Date2.Year())
             ? ((Date1.Month() == Date2.Month())
                    ? ((Date1.Day() == Date2.Day()) ? true : false)
                    : false)
             : false;
}

bool clsDate::IsDateEqualDate2(clsDate Date2) {
  return IsDate1EqualDate2(*this, Date2);
}

bool clsDate::IsLastDayInMonth(clsDate Date) {

  return (Date.Day() == NumberOfDaysInAMonth(Date.Month(), Date.Year()));
}

bool clsDate::IsLastDayInMonth() { return IsLastDayInMonth(*this); }

bool clsDate::IsLastMonthInYear(short Month) { return (Month == 12); }

clsDate clsDate::AddOneDay(clsDate Date) {
  if (IsLastDayInMonth(Date)) {
    if (IsLastMonthInYear(Date.Month())) {
      Date.SetMonth(1);
      Date.SetDay(1);
      Date.SetYear(Date.Year() + 1);
    } else {
      Date.SetDay(1);
      Date.SetMonth(Date.Month() + 1);
    }
  } else {
    Date.SetDay(Date.Day() + 1);
  }

  return Date;
}

void clsDate::AddOneDay()

{
  *this = AddOneDay(*this);
}

void clsDate::SwapDates(clsDate &Date1, clsDate &Date2) {

  clsDate TempDate;
  TempDate = Date1;
  Date1 = Date2;
  Date2 = TempDate;
}

int clsDate::GetDifferenceInDays(clsDate Date1, clsDate Date2,
                                 bool IncludeEndDay ) {
  // this will take care of negative diff
  int Days = 0;
  short SawpFlagValue = 1;

  if (!IsDate1BeforeDate2(Date1, Date2)) {
    // Swap Dates
    SwapDates(Date1, Date2);
    SawpFlagValue = -1;
  }

  while (IsDate1BeforeDate2(Date1, Date2)) {
    Days++;
    Date1 = AddOneDay(Date1);
  }

  return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

int clsDate::GetDifferenceInDays(clsDate Date2, bool IncludeEndDay ) {
  return GetDifferenceInDays(*this, Date2, IncludeEndDay);
}

short clsDate:: CalculateMyAgeInDays(clsDate DateOfBirth) {
  return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
}
// above no need to have nonstatic function for the object because it does not
// depend on any data from it.

clsDate clsDate:: IncreaseDateByOneWeek(clsDate &Date) {

  for (int i = 1; i <= 7; i++) {
    Date = AddOneDay(Date);
  }

  return Date;
}

void clsDate:: IncreaseDateByOneWeek() { IncreaseDateByOneWeek(*this); }

clsDate clsDate::IncreaseDateByXWeeks(short Weeks, clsDate &Date) {

  for (short i = 1; i <= Weeks; i++) {
    Date = IncreaseDateByOneWeek(Date);
  }
  return Date;
}

void clsDate::IncreaseDateByXWeeks(short Weeks) { IncreaseDateByXWeeks(Weeks, *this); }

clsDate clsDate:: IncreaseDateByOneMonth(clsDate &Date) {

  if (Date.Month ()== 12) {
    Date.SetMonth (1);
    Date.SetYear(Date.Year()+1);
  } else {
    Date.SetMonth(Date.Month()+1);;
  }

  // last check day in date should not exceed max days in the current month
  //  example if date is 31/1/2022 increasing one month should not be 31/2/2022,
  //  it should be 28/2/2022
  short NumberOfDaysInCurrentMonth =
      NumberOfDaysInAMonth(Date.Month(), Date.Year());
  if (Date.Day() > NumberOfDaysInCurrentMonth) {
    Date.SetDay(NumberOfDaysInCurrentMonth);
  }

  return Date;
}

void clsDate::IncreaseDateByOneMonth() { IncreaseDateByOneMonth(*this); }

clsDate clsDate:: IncreaseDateByXDays(short Days, clsDate &Date) {

  for (short i = 1; i <= Days; i++) {
    Date = AddOneDay(Date);
  }
  return Date;
}

void clsDate:: IncreaseDateByXDays(short Days) { IncreaseDateByXDays(Days, *this); }

clsDate clsDate:: IncreaseDateByXMonths(short Months, clsDate &Date) {

  for (short i = 1; i <= Months; i++) {
    Date = IncreaseDateByOneMonth(Date);
  }
  return Date;
}

void clsDate::IncreaseDateByXMonths(short Months) {
  IncreaseDateByXMonths(Months, *this);
}

clsDate clsDate:: IncreaseDateByOneYear(clsDate &Date) {
  Date.SetYear(Date.Year()+1);
  return Date;
}

void clsDate::IncreaseDateByOneYear() { IncreaseDateByOneYear(*this); }

clsDate clsDate::IncreaseDateByXYears(short Years, clsDate &Date) {
  Date.SetYear(Date.Year()+Years);
  return Date;
}

void clsDate:: IncreaseDateByXYears(short Years) { IncreaseDateByXYears(Years,*this); }

clsDate clsDate::IncreaseDateByOneDecade(clsDate &Date) {
  // Period of 10 years
  Date.SetYear(Date.Year()+10);
  return Date;
}

void clsDate::IncreaseDateByOneDecade() { IncreaseDateByOneDecade(*this); }

clsDate clsDate::IncreaseDateByXDecades(short Decade, clsDate &Date) {
  Date.SetYear(Date.Year()+Decade*10);
  return Date;
}

void clsDate::IncreaseDateByXDecades(short Decade) {
  IncreaseDateByXDecades(Decade, *this);
}

clsDate clsDate:: IncreaseDateByOneCentury(clsDate &Date) {
  // Period of 100 years
  Date.SetYear(Date.Year() + 100);
  return Date;
}

void clsDate::IncreaseDateByOneCentury() { IncreaseDateByOneCentury(*this); }

clsDate clsDate::IncreaseDateByOneMillennium(clsDate &Date) {
  // Period of 1000 years
  Date.SetYear(Date.Year() + 1000);
  return Date;
}

clsDate clsDate::IncreaseDateByOneMillennium() { return IncreaseDateByOneMillennium(*this); }

clsDate clsDate ::DecreaseDateByOneDay(clsDate Date) {
  if (Date.Day ()== 1) {
    if (Date.Month ()== 1) {
      Date.SetMonth(12);
      Date.SetDay(31);
      Date.SetYear(Date.Year()-1);
    } else {

      Date.SetMonth(Date.Month()-1);
      Date.SetDay(NumberOfDaysInAMonth(Date.Month(), Date.Year()));
    }
  } else {
    Date.SetDay(Date.Day()-1);
  }

  return Date;
}

void clsDate::DecreaseDateByOneDay() { DecreaseDateByOneDay(*this); }

clsDate clsDate::DecreaseDateByOneWeek(clsDate &Date) {

  for (int i = 1; i <= 7; i++) {
    Date = DecreaseDateByOneDay(Date);
  }

  return Date;
}

void clsDate::DecreaseDateByOneWeek() { DecreaseDateByOneWeek(*this); }

clsDate clsDate:: DecreaseDateByXWeeks(short Weeks, clsDate &Date) {

  for (short i = 1; i <= Weeks; i++) {
    Date = DecreaseDateByOneWeek(Date);
  }
  return Date;
}

void clsDate::DecreaseDateByXWeeks(short Weeks) { DecreaseDateByXWeeks(Weeks, *this); }

clsDate clsDate ::DecreaseDateByOneMonth(clsDate &Date) {

  if (Date.Month() == 1) {
    Date.SetMonth(12);
    Date.SetYear(Date.Year()-1);
  } else
    Date.SetMonth(Date.Month()-1);

  // last check day in date should not exceed max days in the current month
  // example if date is 31/3/2022 decreasing one month should not be 31/2/2022,
  // it should be 28/2/2022
  short NumberOfDaysInCurrentMonth =
      NumberOfDaysInAMonth(Date.Month(), Date.Year());
  if (Date.Day() > NumberOfDaysInCurrentMonth) {
    Date.SetDay(NumberOfDaysInCurrentMonth);
  }

  return Date;
}

void clsDate:: DecreaseDateByOneMonth() { DecreaseDateByOneMonth(*this); }

clsDate clsDate:: DecreaseDateByXDays(short Days, clsDate &Date) {

  for (short i = 1; i <= Days; i++) {
    Date = DecreaseDateByOneDay(Date);
  }
  return Date;
}

void clsDate::DecreaseDateByXDays(short Days) { DecreaseDateByXDays(Days, *this); }

clsDate clsDate:: DecreaseDateByXMonths(short Months, clsDate &Date) {

  for (short i = 1; i <= Months; i++) {
    Date = DecreaseDateByOneMonth(Date);
  }
  return Date;
}

void clsDate::DecreaseDateByXMonths(short Months) {
  DecreaseDateByXMonths(Months, *this);
}

clsDate clsDate ::DecreaseDateByOneYear(clsDate &Date) {

  Date.SetYear(Date.Year()-1);
  return Date;
}

void clsDate::DecreaseDateByOneYear() { DecreaseDateByOneYear(*this); }

clsDate clsDate ::DecreaseDateByXYears(short Years, clsDate &Date) {

  Date.SetYear(Date.Year()-Years);
  return Date;
}

void clsDate::DecreaseDateByXYears(short Years) { DecreaseDateByXYears(Years, *this); }

clsDate clsDate::DecreaseDateByOneDecade(clsDate &Date) {
  // Period of 10 years
  Date.SetYear(Date.Year()-10);
  return Date;
}

void clsDate::DecreaseDateByOneDecade() { DecreaseDateByOneDecade(*this); }

clsDate clsDate:: DecreaseDateByXDecades(short Decades, clsDate &Date) {

  Date.SetYear(Date.Year()-Decades * 10);
  return Date;
}

void clsDate::DecreaseDateByXDecades(short Decades) {
  DecreaseDateByXDecades(Decades, *this);
}

clsDate clsDate ::DecreaseDateByOneCentury(clsDate &Date) {
  // Period of 100 years
  Date.SetYear(Date.Year()-100);
  return Date;
}

void clsDate::DecreaseDateByOneCentury() { DecreaseDateByOneCentury(*this); }

clsDate clsDate::DecreaseDateByOneMillennium(clsDate &Date) {
  // Period of 1000 years
  Date.SetYear(Date.Year()-1000);
  return Date;
}

void clsDate:: DecreaseDateByOneMillennium() { DecreaseDateByOneMillennium(*this); }

short clsDate::IsEndOfWeek(clsDate Date) {
  return DayOfWeekOrder(Date.Day(), Date.Month(), Date.Year()) == 6;
}

short clsDate:: IsEndOfWeek() { return IsEndOfWeek(*this); }

bool clsDate:: IsWeekEnd(clsDate Date) {
  // Weekends are Fri and Sat
  short DayIndex = DayOfWeekOrder(Date.Day(), Date.Month(), Date.Year());
  return (DayIndex == 5 || DayIndex == 6);
}

bool clsDate::IsWeekEnd() { return IsWeekEnd(*this); }

bool clsDate::IsBusinessDay(clsDate Date) {
  // Weekends are Sun,Mon,Tue,Wed and Thur

  /*
       short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
       return  (DayIndex >= 5 && DayIndex <= 4);
  */

  // shorter method is to invert the IsWeekEnd: this will save updating code.
  return !IsWeekEnd(Date);
}

bool clsDate:: IsBusinessDay() { return IsBusinessDay(*this); }

short clsDate:: DaysUntilTheEndOfWeek(clsDate Date) {
  return 6 - DayOfWeekOrder(Date.Day(), Date.Month(), Date.Year());
}

short clsDate::DaysUntilTheEndOfWeek() { return DaysUntilTheEndOfWeek(*this); }

short clsDate::DaysUntilTheEndOfMonth(clsDate Date1) {

  clsDate EndOfMontDate;
  EndOfMontDate.SetDay( NumberOfDaysInAMonth(Date1.Month(), Date1.Year()));
  EndOfMontDate.SetMonth(Date1.Month());
  EndOfMontDate.SetYear(Date1.Year());

  return GetDifferenceInDays(Date1, EndOfMontDate, true);
}

short clsDate::DaysUntilTheEndOfMonth() { return DaysUntilTheEndOfMonth(*this); }

short clsDate:: DaysUntilTheEndOfYear(clsDate Date1) {

  clsDate EndOfYearDate;
  EndOfYearDate.SetDay(31);
  EndOfYearDate.SetMonth(12);
  EndOfYearDate.SetYear(Date1.Year());

  return GetDifferenceInDays(Date1, EndOfYearDate, true);
}

short clsDate::DaysUntilTheEndOfYear() { return DaysUntilTheEndOfYear(*this); }

// i added this method to calculate business days between 2 days
short clsDate::CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {

  short Days = 0;
  while (IsDate1BeforeDate2(DateFrom, DateTo)) {
    if (IsBusinessDay(DateFrom))
      Days++;

    DateFrom = AddOneDay(DateFrom);
  }

  return Days;
}

short clsDate::CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {
  /*short Days = 0;
  while (IsDate1BeforeDate2(DateFrom, DateTo))
  {
          if (IsBusinessDay(DateFrom))
                  Days++;

          DateFrom = AddOneDay(DateFrom);
  }*/

  return CalculateBusinessDays(DateFrom, DateTo);
}
// above method is eough , no need to have method for the object

clsDate clsDate:: CalculateVacationReturnDate(clsDate DateFrom, short VacationDays) {

  short WeekEndCounter = 0;

  for (short i = 1; i <= VacationDays; i++) {

    if (IsWeekEnd(DateFrom))
      WeekEndCounter++;

    DateFrom = AddOneDay(DateFrom);
  }
  // to add weekends
  for (short i = 1; i <= WeekEndCounter; i++)
    DateFrom = AddOneDay(DateFrom);

  return DateFrom;
}

bool clsDate::IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
  return (!IsDate1BeforeDate2(Date1, Date2) &&
          !IsDate1EqualDate2(Date1, Date2));
}
bool clsDate::IsDateAfterDate2(clsDate Date2) { return IsDate1AfterDate2(*this, Date2); }
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
clsDate::enDateCompare clsDate::CompareDates(clsDate Date1, clsDate Date2) {
  if (IsDate1BeforeDate2(Date1, Date2))
    return clsDate::enDateCompare::Before;

  if (IsDate1EqualDate2(Date1, Date2))
    return clsDate::enDateCompare::Equal;

  /* if (IsDate1AfterDate2(Date1,Date2))
           return enDateCompare::After;*/

  // this is faster
  return clsDate::enDateCompare::After;
}

clsDate::enDateCompare clsDate::CompareDates(clsDate Date2) { return CompareDates(*this, Date2); }




