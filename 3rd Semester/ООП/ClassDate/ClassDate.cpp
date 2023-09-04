#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace std;

class DATE
{
    private:
    int DateValue;
    public:
    DATE();
    DATE(int);
    DATE(char*);
    DATE encodeDate(int, int, int);
    void decodeDate(int&, int&, int&);
    int DateToInt();
    DATE IntToDate(int);
    int StrToDate(char*);
    string DateToStr();
    DATE CurrentDate();
    int operator+(DATE);
    int operator-(DATE);
    DATE operator+(int);
    DATE operator-(int);
    void ShowDate();
    int DatenMonth(char *x);
};

DATE::DATE() {DateValue = 0;}

DATE::DATE(int x)
{
    DateValue = x;
}

DATE::DATE(char *x)
{   
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
}

DATE DATE::encodeDate(int d, int m, int y)
{   
    DATE x;
    
    for(int i = 1900; i < y; i++) DateValue += i != 1900 && i % 4 == 0 ? 366 : 365;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int o = 0; allmonth[1] = y != 1900 && y % 4 == 0 ? 29 : 28;
    for(int i = 0; i < m; i++) DateValue += allmonth[o++];
    x.DateValue += d;

    return x;
}

void DATE::decodeDate(int &d, int &m, int &y)
{
    DateValue = 0;
    for(int i = 1900; i < *&y; i++) DateValue += i != 1900 && i % 4 == 0 ? 366 : 365;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int o = 0; allmonth[1] = *&y != 1900 && *&y % 4 == 0 ? 29 : 28;
    for(int i = 0; i < *&m; i++) DateValue += allmonth[o++];
    DateValue += *&d;
}

int DATE::DateToInt()
{
    return DateValue;
}

DATE DATE::IntToDate(int x)
{
    DATE y;
    y.DateValue = x;
    return y;
}

int DATE::StrToDate(char *x)
{
    DateValue = 0;
    char *p = x;
    int m = 0;
    DateValue += atoi(p) - 1;
    while(*p && *p!=':')p++;
    if(*p)
    {
        p++;
        m = atoi(p);
        DateValue += (atoi(p) - 1) * 30;
        DateValue -= atoi(p) > 2 ? 2 : 0; 
        DateValue += (atoi(p) / 2);
    }

     while(*p && *p!=':')p++;
    if(*p)
    {
        p++;
        DateValue += DateValue > 58 && atoi(p) % 4 == 0 && atoi(p) != 1900 && m > 2 ? 1 : 0;
        for(int i = 1900; i < atoi(p); i++) DateValue += 365;
    }
    return DateValue;
}

string DATE::DateToStr()
{
    stringstream x;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, y = 1900, m = 1, d = 1, VariableYear = 365;
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
    x << setfill('0') << fixed << setw(4) << to_string(y) << '\n';

    return x.str();
}

DATE DATE::CurrentDate()
{   
    time_t t = time(0);
    tm* now = localtime(&t);

    DATE x;
    for(int i = 1900; i < (now->tm_year + 1900); i++)
    {   if(i % 4 == 0 && i != 1900) x.DateValue++;
        x.DateValue += 365;
    }
    x.DateValue += 30 * now->tm_mon;
    x.DateValue -= (now->tm_mon + 1) > 2 ? 2 : 0; 
    x.DateValue += ((now->tm_mon + 1) / 2);
    x.DateValue += now->tm_mday - 1;

    return x;
}

int DATE::operator+(DATE x)
{
    int ans = 0;
    ans += DateValue + x.DateValue;
    return ans;
}

int DATE::operator-(DATE x)
{
    int ans = 0;
    ans = DateValue - x.DateValue;
    return ans;
}

DATE DATE::operator+(int x)
{   
    DATE y;
    DateValue += x; y.DateValue = DateValue;
    return y;
}

DATE DATE::operator-(int x)
{   
    DATE y;
    DateValue -= x; y.DateValue = DateValue;
    return y;
}

int DATE::DatenMonth(char *x)
{
    int a = 0;
    char *p = x;
    a += atoi(p) - 1;
    int allmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        for(int i = 0; i < atoi(p) - 1; i++) a += allmonth[i];
    }
    
    while(*p && *p!=':') p++;
    if(*p)
    {
        p++;
        int year = atoi(p);
        a += a > 59 && year % 4 == 0 && year != 1900 ? 1 : 0;
    }
    return a;
}

void DATE::ShowDate()
{
    cout << DateValue << '\n';
}

int main()
{  
    char c[12] = "31:12:1904";

    DATE x(c);
    x.ShowDate();
    string a;

    a = x.DateToStr();
    cout << a;
}
