#include <iostream>
#include <iomanip>

using namespace std;

class DateTime
{
    private:
        double MainValue; int second, minute, hour, day, month, year;
    public:
        DateTime() {MainValue = 0;};
        void Date(char *x);
        void Time(char *x);
        void DateAndTime(char *x);
        void Output();
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
};

// void DateTime :: Output()
// {
//     if(TimeValue >= 86400)
//     {
//         DateValue += TimeValue / 86400;
//         TimeValue %= 86400;
//     }
    
//     MainValue = DateValue + double(TimeValue) / 86400;

//     cout << "\nDAYS: " << DateValue << "\nSECONDS: " << TimeValue << "\nMAIN VALUE: " << setprecision(14) << MainValue << '\n';
// }

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
        // if(year1 > 1904 && year1 % 4 == 0 && (m < 2 || (m < 2 && d < 30))) DateValue--;
        if((year1 == 1900) && month == 1 && day == 1) MainValue = 0;
    }
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
    MainValue += TimeValue / 86400.0;
}

void DateTime :: DateAndTime(char *x)
{
    Date(x);
    while (*x != ' ') x++;
    x++;
    Time(x);
}

DateTime DateTime :: operator+(int x)
{
    DateTime a;
    a.MainValue += double(x) / double(86400);
    return a;
}

DateTime DateTime :: operator-(int x)
{
    DateTime a;
    a.MainValue -= double(x) / double(86400);
    return a;
}

DateTime DateTime :: operator+(DateTime x)
{
    DateTime a;
    a.MainValue += x.MainValue;
    return a;
}

DateTime DateTime :: operator-(DateTime x)
{
    MainValue -= x.MainValue;
}

DateTime DateTime :: operator+(char *x)
{
    int InitialValue = MainValue;
    MainValue = 0;
    char *p = x;
    MainValue += atoi(p) - 1;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, m = 0, d = atoi(p);
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        m = atoi(p);
        for(int i = 0; i < atoi(p) - 1; i++) DateValue += allmonth[i];
    }
    
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        int year = atoi(p), year1 = atoi(p);
        DateValue += year > 1903 && year % 4 == 0 && (m > 2) ? 1 : 0; 
        for(int i = 1900; i < year; i++) DateValue += i != 1900 && i % 4 == 0 ? 366 : 365;
        // if(year1 > 1904 && year1 % 4 == 0 && (m < 2 || (m < 2 && d < 30))) DateValue--;
        if((year1 == 1900) && m == 1 && d == 1) DateValue = 0;
    }
    
    int InitialTimeValue = TimeValue;
    TimeValue = 0;

    while(*p && *p!='|') p++;
    if(*p)
    {
        p++;
        TimeValue += atoi(p) * 3600;
    }
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
    DateValue += InitialDateValue;
    TimeValue += InitialTimeValue;
}

DateTime DateTime :: operator-(char *x)
{
    int InitialDateValue = DateValue;
    DateValue = 0;
    char *p = x;
    DateValue += atoi(p) - 1;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, m = 0, d = atoi(p);
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        m = atoi(p);
        for(int i = 0; i < atoi(p) - 1; i++) DateValue += allmonth[i];
    }
    
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        int year = atoi(p), year1 = atoi(p);
        DateValue += year > 1903 && year % 4 == 0 && (m > 2) ? 1 : 0; 
        for(int i = 1900; i < year; i++) DateValue += i != 1900 && i % 4 == 0 ? 366 : 365;
        // if(year1 > 1904 && year1 % 4 == 0 && (m < 2 || (m < 2 && d < 30))) DateValue--;
        if((year1 == 1900) && m == 1 && d == 1) DateValue = 0;
    }
    
    int InitialTimeValue = TimeValue;
    TimeValue = 0;

    while(*p && *p!='|') p++;
    if(*p)
    {
        p++;
        TimeValue += atoi(p) * 3600;
    }
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
    DateValue = InitialDateValue - DateValue;
    TimeValue = InitialTimeValue - TimeValue;
}

string DateTime :: ShowDate()
{
    stringstream x;
    int StockDateValue = DateValue;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, y = 1900, m = 1, d = 1, VariableYear = 365;
    DateValue += TimeValue / 3600 >= 24 ? TimeValue / 3600 / 24 : 0;
    while(DateValue >= VariableYear)
    {
        if(y != 1900 && y % 4 == 0)
        {
            DateValue -= 366;
            y++;
            VariableYear = 365;
            continue;
        }

        if(y % 4 != 0 || y == 1900)
        {
            DateValue -= 365;
            y++;
        }
        VariableYear = y != 1900 && y % 4 == 0 ? 366 : 365;
    }

    allmonth[1] = y != 1900 && y % 4 == 0 ? 29 : 28;
    int o = 0;
    bool aha = false; aha = DateValue == 59 && y != 1900 && y % 4 == 0 ? true : false;

    d = DateValue + 1;
    while(d > allmonth[o])
    {
        DateValue -= allmonth[o++];
        d = DateValue + 1;
        m++;
        if(m > 11) break;
    }

    if(aha) d = 29, m = 2;

    x << setfill('0') << fixed << setw(2) << to_string(d) << '/';
    x << setfill('0') << fixed << setw(2) << to_string(m) << '/';
    x << setfill('0') << fixed << setw(4) << to_string(y);

    DateValue = StockDateValue;

    return x.str();
}

string DateTime :: ShowTime()
{
    stringstream x;
    seconds = TimeValue % 60;
    minutes = TimeValue % 3600 / 60;
    hours = TimeValue / 3600;
    x << setfill('0') << fixed << setw(2)  << hours << ':' << setfill('0') << fixed << setw(2) << minutes  << ':' << setfill('0') << fixed << setw(2) << seconds;
    return x.str();
}

string DateTime :: ShowDateAndTime()
{
    stringstream x; 
    int StockDateValue = DateValue;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, y = 1900, m = 1, d = 1, VariableYear = 365;
    DateValue += TimeValue / 3600 >= 24 ? TimeValue / 3600 / 24 : 0;
    while(DateValue >= VariableYear)
    {
        if(y != 1900 && y % 4 == 0)
        {
            DateValue -= 366;
            y++;
            VariableYear = 365;
            continue;
        }

        if(y % 4 != 0 || y == 1900)
        {
            DateValue -= 365;
            y++;
        }
        VariableYear = y != 1900 && y % 4 == 0 ? 366 : 365;
    }

    allmonth[1] = y != 1900 && y % 4 == 0 ? 29 : 28;
    int o = 0;
    bool aha = false; aha = DateValue == 59 && y != 1900 && y % 4 == 0 ? true : false;

    d = DateValue + 1;
    while(d > allmonth[o])
    {
        DateValue -= allmonth[o++];
        d = DateValue + 1;
        m++;
        if(m > 11) break;
    }

    if(aha) d = 29, m = 2;

    x << setfill('0') << fixed << setw(2) << to_string(d) << '/';
    x << setfill('0') << fixed << setw(2) << to_string(m) << '/';
    x << setfill('0') << fixed << setw(4) << to_string(y) << " | ";
    seconds = TimeValue % 60;
    minutes = TimeValue % 3600 / 60;
    hours = TimeValue / 3600;
    hours %= 24;
    x << setfill('0') << fixed << setw(2)  << hours << ':' << setfill('0') << fixed << setw(2) << minutes  << ':' << setfill('0') << fixed << setw(2) << seconds;
    
    DateValue = StockDateValue;
    return x.str();
}

void DateTime :: SetCurrentDate(int d, int m, int y)
{
    DateValue = 0;
    for(int i = 1900; i < y; i++)
    {
        DateValue += i != 1900 && i % 4 == 0 ? 366 : 365;
    }
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int o = 0; allmonth[1] = y != 1900 && y % 4 == 0 ? 29 : 28;
    for(int i = 0; i < m - 1; i++)
    {
        DateValue += allmonth[o++];
    }
    DateValue += d - 1;
}

void DateTime :: SetCurrentTime(int h, int m, int s)
{
    TimeValue = 0;
    TimeValue += s;
    TimeValue += m * 60;
    TimeValue += h * 3600;
}

void DateTime :: FractionalToTime()
{
    cout << "Fractional To Time: " << "\nFractional Part: " << double(TimeValue) / 86400.0 << " -> " << "Quantity of seconds: " << TimeValue << " -> " << ShowTime() << '\n';
}

void DateTime :: TimeToFractional()
{
    cout << "Time To Fractional: " << "Time: " << ShowTime() << " -> " << double(TimeValue) / 86400.0 << '\n';
}

void DateTime :: WholeToDate()
{
    cout << "Whole to Date: " << DateValue + TimeValue / 86400 << " -> " << "Date: " << ShowDate() << '\n';
}

void DateTime :: DateToWhole()
{
    cout << "Date to Whole: " << ShowDate() << " -> " << "Quantity of the Days: " << DateValue + TimeValue / 86400 << '\n';
}

int main()
{   
    DateTime a, b;
    a.DateAndTime("1:01:1950|26:0:0");
    
    // a.SetCurrentDate(29,2,1904);
    // a.SetCurrentTime(49, 20, 30);
    // a.FractionalToTime();
    // a.TimeToFractional();
    // a.WholeToDate();
    // a.DateToWhole();
    // b.Time("0:0:1");
    // a + b;
    // a.Output();
    a.Output();
    
    string s = a.ShowDateAndTime();
    cout << s;
}