#include <iostream>
#include <iomanip>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class DateTime
{
    private:
        double MainValue; int second, minute, hour, day, month, year;
    public:
        DateTime() {MainValue = 0; second = 0; minute = 0; hour = 0; day = 0; month = 0; year = 1900;};
        void Date(char *x);
        void Time(char *x);
        void DateAndTime(char *x);
        DateTime operator+(int);
        DateTime operator-(int);
        DateTime operator+(DateTime);
        DateTime operator-(DateTime);
        DateTime operator+(char *x);
        DateTime operator-(char *x);
        string ShowDate();
        string ShowTime();
        string ShowDateAndTime();
        void SetCurrentDate(int d, int m, int y);
        void SetCurrentTime(int h, int m, int s);
        void FractionalToTime();
        void TimeToFractional();
        void WholeToDate();
        void DateToWhole();
        void Normalizer();
};
void DateTime :: Normalizer()
{
    double StockValue = MainValue;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // FOR SECONDS, MINUTES AND HOURS
    int TimeValue = ((MainValue - floor(MainValue)) * double(86400.0));
    second = TimeValue % 60;
    minute += second / 60;
    minute = TimeValue % 3600 / 60;
    hour += minute / 60;
    hour = TimeValue / 3600;
    MainValue += hour / 24;
    // FOR DAYS, MONTHS AND YEARS
    int VariableYear = 365;
    year = 1900, month = 1, day = 1;
    while(int(MainValue) >= VariableYear)
    {
        if(year != 1900 && year % 4 == 0)
        {
            MainValue -= 366;
            year++;
            VariableYear = 365;
            continue;
        }
        if(year % 4 != 0 || year == 1900)
        {
            MainValue -= 365;
            year++;
        }
        VariableYear = year != 1900 && year % 4 == 0 ? 366 : 365;
    }
    allmonth[1] = year != 1900 && year % 4 == 0 ? 29 : 28;
    int o = 0;
    bool aha = false; aha = int(MainValue) == 59 && year != 1900 && year % 4 == 0 ? true : false;
    day = MainValue + 1;
    while(day > allmonth[o])
    {
        MainValue -= allmonth[o++];
        day = MainValue + 1;
        month++;
        if(month > 11) break;
    }
    if(aha) day = 29, month = 2;
    MainValue = StockValue;
}

void DateTime :: Date(char *x)
{
    char *p = x;
    MainValue += atoi(p) - 1;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    month = 0, day = atoi(p);
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        month = atoi(p);
        for(int i = 0; i < atoi(p) - 1; i++) MainValue += allmonth[i];
    }
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        year = atoi(p);
        int year1 = atoi(p);
        MainValue += year > 1903 && year % 4 == 0 && (month > 2) ? 1 : 0;
        for(int i = 1900; i < year; i++) MainValue += i != 1900 && i % 4 == 0 ? 366 : 365;
        if((year1 == 1900) && month == 1 && day == 1) MainValue = 0;
    }
    Normalizer();
}

void DateTime :: Time(char *x)
{
    int TimeValue = 0;
    char *p = x;
    TimeValue += atoi(p) * 3600;
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        TimeValue += atoi(p) * 60;
    }

    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        TimeValue += atoi(p);
    }
    MainValue += double(TimeValue) / double(86400.0);
    Normalizer();
}

void DateTime :: DateAndTime(char *x)
{
    Date(x);
    while (*x != '|') x++; x++;
    Time(x);
}

DateTime DateTime :: operator+(int x)
{
    DateTime a;
    MainValue += double(x) / double(86400.0);
    Normalizer();
    a.MainValue = MainValue;
    return a;
}

DateTime DateTime :: operator-(int x)
{
    DateTime a;
    MainValue -= double(x) / double(86400.0);
    Normalizer();
    a.MainValue = MainValue;
    return a;
}

DateTime DateTime :: operator+(DateTime x)
{
    DateTime a;
    MainValue += x.MainValue;
    Normalizer();
    a.MainValue = MainValue;
    return a;
}

DateTime DateTime :: operator-(DateTime x)
{
    DateTime a;
    MainValue -= x.MainValue;
    Normalizer();
    a.MainValue = MainValue;
    return a;
}

DateTime DateTime :: operator+(char *x)
{
    DateTime a;
    double InitialValue = MainValue;
    MainValue = 0;
    DateAndTime(x);
    MainValue += InitialValue;
    Normalizer();
    a.MainValue = MainValue;
    return a;
}

DateTime DateTime :: operator-(char *x)
{
    DateTime a;
    double InitialValue = MainValue;
    MainValue = 0;
    DateAndTime(x);
    // SuperfluousSecond();
    InitialValue -= MainValue;
    a.MainValue = InitialValue;
    return a;
}

string DateTime :: ShowDate()
{
    stringstream x;
    Normalizer();
    x << setfill('0') << fixed << setw(2) << day << '/';
    x << setfill('0') << fixed << setw(2) << month << '/';
    x << setfill('0') << fixed << setw(4) << year;
    return x.str();
}

string DateTime :: ShowTime()
{
    stringstream x;
    Normalizer();
    x << setfill('0') << fixed << setw(2)  << hour << ':' << setfill('0') << fixed << setw(2) << minute  << ':' << setfill('0') << fixed << setw(2) << second;
    return x.str();
}

string DateTime :: ShowDateAndTime()
{
    stringstream x;
    x << ShowDate() << '|' << ShowTime() << '\n';
    return x.str();
}

void DateTime :: SetCurrentDate(int d, int m, int y)
{
    MainValue = MainValue - floor(MainValue);
    for(int i = 1900; i < y; i++)
    {
        MainValue += i != 1900 && i % 4 == 0 ? 366 : 365;
    }
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int o = 0; allmonth[1] = y != 1900 && y % 4 == 0 ? 29 : 28;
    for(int i = 0; i < m - 1; i++)
    {
        MainValue += allmonth[o++];
    }
    MainValue += d - 1;
    day = d;
    month = m;
    year = y;
}

void DateTime :: SetCurrentTime(int h, int m, int s)
{
    MainValue = floor(MainValue);
    MainValue += double(s) / 86400.0;
    MainValue += double(m*60) / 86400.0;
    MainValue += double(h*3600) / 86400.0;
    second = s, minute = m, hour = h;
}

void DateTime :: FractionalToTime()
{
    cout << "Fractional To Time: " << "Fractional Part: " <<  MainValue - floor(MainValue) << " -> " << ShowTime() << '\n';
}

void DateTime :: TimeToFractional()
{
    cout << "Time To Fractional: " << "Time: " << ShowTime() << " -> " << MainValue - floor(MainValue) << '\n';
}

void DateTime :: WholeToDate()
{
    cout << "Whole to Date: " << int(MainValue) << " -> " << "Date: " << ShowDate() << '\n';
}

void DateTime :: DateToWhole()
{
    cout << "Date to Whole: " << ShowDate() << " -> " << "Quantity of the Days: " << int(MainValue) << '\n';
}

int main()
{
    DateTime a, b;
    a.DateAndTime("29:02:1908|5:56:00");

    // a.SetCurrentDate(29,2,1904);
    // a.SetCurrentTime(10, 20, 30);
    // a.FractionalToTime();
    // a.TimeToFractional();
    // a.WholeToDate();
    // a.DateToWhole();
    b.Time("0:0:5");
    a - b;

    string s = a.ShowDateAndTime();
    cout << s;
}
