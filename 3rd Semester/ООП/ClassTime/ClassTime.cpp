#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

class TIME
{
    private:
    int h,m,s;
    public:
    TIME();
    TIME(int);
    TIME(int,int);
    TIME(int,int,int);
    TIME(char*);
    void Show();
    void Input();
    void Output();
    void setH(int);
    void setM(int);
    void setS(int);
    int getH();
    int getM();
    int getS();
    string TimeToStr();
    TIME operator+(TIME);
    TIME operator-(TIME);
};

TIME::TIME() {h = 0; m = 0; s = 0;}
TIME::TIME(int x ) {h = x; m = 0; s = 0;}
TIME::TIME(int x, int y) {h = x; m = y; s = 0;}
TIME::TIME(int x, int y, int z) {h = x; m = y; s = z;}
TIME::TIME(char* x)
{
    char *p = x;
    h = atoi(p);
    while(*p && *p!=':')p++;
    if(*p)
    {
        p++;
        m = atoi(p);
    }
    while(*p && *p!=':')p++;
    if(*p)
    {
        p++;
        s = atoi(p);
    }
};

void TIME::Input()
{
    cin >> this->h; cin.ignore(1);
    cin >> this->m; cin.ignore(1);
    cin >> this->s;
}

void TIME::setH(int x)
{
    this->h = x;
}

void TIME::setM(int x)
{
    this->m = x;
}

void TIME::setS(int x)
{
    this->s = x;
}

int TIME::getH()
{
    return this->h;
}

int TIME::getM()
{
    return this->m;
}

int TIME::getS()
{
    return this->s;
}

string TIME::TimeToStr()
{
    stringstream x;
    x << setfill('0') << fixed << setw(2)  << this->h  << ':' << setfill('0') << fixed << setw(2) << this->m  << ':' << setfill('0') << fixed << setw(2) << this->s;
    return x.str(); 
}

TIME TIME::operator+(TIME x)
{
    TIME sum;
    sum.h = this->h + x.h;
    sum.m = this->m + x.m;
    sum.s = this->s + x.s;

    sum.m += sum.s / 60;
    sum.s %= 60;
    sum.h += sum.m / 60;
    sum.m %= 60;

    return sum;
}

TIME TIME::operator-(TIME x)
{
    TIME dis;
    dis.h = this->h - x.h;
    dis.m = this->m - x.m;
    dis.s = this->s - x.s;

    dis.m += dis.s / 60;
    dis.s %= 60;
    dis.m -= dis.s < 0 ? 1 : 0;
    dis.s += dis.s < 0 ? 60 : 0;
    dis.h += dis.m / 60;
    dis.m %= 60;
    dis.h -= dis.m < 0 ? 1 : 0;
    dis.m += dis.m < 0 ? 60 : 0;
    dis.h += dis.h < 0 ? 24 * (dis.h / (-24) + 1) : 0;

    return dis;
}

void TIME::Show()
{
    cout << h << ' ' << m << ' ' << s << '\n';
}

int main()
{
    TIME a, b, sum, dis;
    a.Input();
    b.Input();

    sum = a.operator+(b);
    dis = a.operator-(b);

    string x = sum.TimeToStr(), y = dis.TimeToStr();
    cout << x << '\n' << y;
}