#include <iostream>
#include <math.h>
#include <cstdlib>
#include <complex>
#include <string>

using namespace std;

struct Complex
{
    double Re, Im;
};

void Output(Complex a)
{
    cout << a.Re << ((a.Im < 0) ? "-" : "+") << "i" << fabs(a.Im) << '\n';
}

Complex Sum(Complex a, Complex b)
{
    Complex s;
    s.Re = a.Re + b.Re;
    s.Im = a.Im + b.Im;
    return s;
}

Complex Dis(Complex a, Complex b)
{
    Complex s;
    s.Re = a.Re - b.Re;
    s.Im = a.Im - b.Im;
    return s;
}

Complex Mult(Complex a, Complex b)
{
    Complex s;
    s.Re = (a.Re * b.Re) - (a.Im * b.Im);
    s.Im = (a.Re * b.Im) + (b.Re * a.Im);
    return s;
}

Complex Div(Complex a, Complex b)
{
    Complex s;
    s.Re = ((a.Re * b.Re) + (a.Im * b.Im)) / (pow(b.Re, 2) + pow(b.Im, 2));
    s.Im = ((b.Re * a.Im) - (a.Re * b.Im)) / (pow(b.Re, 2) + pow(b.Im, 2));
    return s;
}

double Abs(Complex a)
{
    return pow(pow(a.Re, 2) + pow(a.Im, 2), 0.5);
}

double Arg(Complex a)
{
    return asin(a.Im / Abs(a)) * 180 / 3.14;
}

Complex Sin(Complex a)
{
    Complex sine;
    sine.Re = sin(a.Re) * cosh(a.Im);
    sine.Im = cos(a.Re) * sinh(a.Im);
    return sine;
}

Complex Cos(Complex a)
{
    Complex cosine;
    cosine.Re = cos(a.Re) * cosh(a.Im);
    cosine.Im = sin(a.Re) * sinh(a.Im);
    return cosine;
}

Complex Tan(Complex a)
{
    Complex tangent;
    tangent.Re = sin(2 * a.Re) / (cos(2 * a.Re) + cosh(2 * a.Im));
    tangent.Im = sinh(2 * a.Im) / (cos(2 * a.Re) + cosh(2 * a.Im));
    return tangent;
}

Complex Ctg(Complex a)
{
    return Div(Cos(a), Sin(a));
}

Complex Log(Complex a)
{
    Complex loga;
    loga.Re = log(10) / 2;
    loga.Im = atan(a.Im/a.Re);
    return loga;
}

Complex Exp(Complex a)
{
    double e = 2.7182818284;
    Complex expo;
    expo.Re = pow(e, 3) * cos(a.Im);
    expo.Im = pow(e, 3) * sin(a.Im);
    return expo;
}

Complex Pow(Complex a, int poww)
{
    Complex power;
    power.Re = pow(Abs(a), poww) * (cos(poww * Arg(a)));
    power.Im = pow(Abs(a), poww) * (sin(poww * Arg(a)));
    return power;
}

void Transfering(Complex a)
{
    cout << "TO TRIGONOMETRY: " << Abs(a) << "(cos(" << Arg(a) << ") + isin(" << Arg(a) << "))" << '\n';
    cout << "EXPONENTIAL FUNCTION: " << Abs(a) << "e^^(i*" << Arg(a) << ")";
}

int main()
{
    Complex x;
    Complex y;
    cin >> x.Re >> x.Im;
    cin >> y.Re >> y.Im;
    int power;
    cout << "POWER: ";
    cin >> power;

    cout << "SUMM: "; Output(Sum(x, y));
    cout << "DIST: "; Output(Dis(x, y));
    cout << "PROD: "; Output(Mult(x, y));
    cout << "DIV: ";  Output(Div(x, y));
    cout << "SIN: "; Output(Sin(x));
    cout << "COS: "; Output(Cos(x));
    cout << "TAN: "; Output(Tan(x));
    cout << "CTG: "; Output(Ctg(x));
    cout << "LOG: "; Output(Log(x));
    cout << "EXP: "; Output(Exp(x));
    cout << "POW: "; Output(Pow(x,power));

    cout << "ABS: " << Abs(x) << '\n';
    cout << "ARG: " << Arg(x) << '\n';
    Transfering(x);

    ////Использование Шаблона <complex> и Библиотеки <cstdlib>
    
    /*complex<double> c1(x.Re, x.Im);*/
    /*cout << "SIN: " << sin(c1) << "\n";
    cout << "COS: " << cos(c1) << "\n";*/
    //cout << "TAN: " << tan(c1) << "\n";
    //cout << "CTG: " << cos(c1)/sin(c1) << "\n";
    //cout << "EXP: " << exp(c1) << "\n";
    //cout << "LOG: " << log(c1) << "\n";
    /*cout << "POW: " << pow(c1, power) << "\n";*/
    //cout << "ABS: " << abs(c1) << "\n";
    /*cout << "ARG & FI:" << arg(c1) << '\n';*/
    
}
