#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <iomanip>
#include <string>

using namespace std;

class Complex
{
private:
	double Re, Im;
public:
	Complex() { Re = 0; Im = 0; };

	Complex(double r)
	  {
		  Re = r;
		  Im = 0;
	  }

	Complex(double r, double i)
	  {
		  Re = r;
		  Im = i;
	  }

	void Output(Complex a)
	  {
		  cout << a.Re << ((a.Im < 0) ? "-" : "+") << fabs(a.Im) << 'i' << '\n';
	  }

	void Input(Complex a)
	{
		cin >> a.Re >> a.Im;
	}

	void SetRe(double a)
	{
		Re = a;
	}

	void SetIm(double a)
	{
		Im = a;
	}

	double Abs(Complex a)
	  {
		  return pow(pow(a.Re, 2) + pow(a.Im, 2), 0.5);
	  }

	double Arg(Complex a)
	  {
		  return asin(a.Im / Abs(a)) * 180 / M_PI;
	  }

	double getRe()
	{
		return Re;
	}

	double getIm()
	{
		return Im;
	}

	string AlgebraicToTrig()
	{
		double a, b;
		cout << "\nENTER Real: ";
		cin >> a;
		cout << "ENTER Imaginary: ";
		cin >> b;
		Complex e;
		SetRe(a);
		SetIm(b);
		e.Re = Re;
		e.Im = Im;
		string s;
		s = to_string(Abs(e)) + "(cos(" + to_string(Arg(e)) + ") + isin(" + to_string(Arg(e)) + "))\n";
		cout << s;
		return s;
	}

	string AlgebraicToExpo()
	{
		double a, b;
		cout << "\nENTER Real: ";
		cin >> a;
		cout << "ENTER Imaginary: ";
		cin >> b;
		Complex e;
		SetRe(a);
		SetIm(b);
		e.Re = Re;
		e.Im = Im;
		string s;
		s = to_string(Abs(e)) + "(e^^(i*" + to_string(Arg(e)) + "))\n";
		cout << s;
		return s;
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

	Complex Ln(Complex a)
	  {
		  Complex loga;
		  loga.Re = log(10) / 2;
		  loga.Im = atan(a.Im / a.Re);
		  return loga;
	  }

	Complex Lg(Complex a)
	{
		Complex lg, lg2, EmptyComplex;
		EmptyComplex.Re = log10(M_E);
		EmptyComplex.Im = 0;
		lg2 = Mult(EmptyComplex, Ln(a));
		lg.Re = log10(sqrt(a.Re * a.Re + a.Im * a.Im));
		lg.Im = lg2.Im;
		return lg;

	}

	Complex Log(Complex a)
	{
		Complex lg, lg2, EmptyComplex;
		EmptyComplex.Re = log2(M_E);
		EmptyComplex.Im = 0;
		lg2 = Mult(EmptyComplex, Ln(a));
		lg.Re = log2(sqrt(a.Re * a.Re + a.Im * a.Im));
		lg.Im = lg2.Im;
		return lg;
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

	Complex Conj(Complex a)
	{
		Complex b;
		b.Re = a.Re;
		b.Im = a.Im * (-1);
		return b;
	}

	Complex TrigToExpo(Complex a)
	{
		double s1, s2;
		cout << "ENTER A TRIGONOMETRIC TYPE. \nFOR EXAMPLE: 5(cos(180) + isin(180))\n";
		cout << "ENTER THE ABSOLUTE VALUE(MODULE): ";
		cin >> s1;
		cout << "ENTER THE FI ANGLE(e.g. 180): ";
		cin >> s2;
		cout << "\nYOU ENTERED: " << setprecision(2) << s1 << "(cos(" << setprecision(4) << s2 << ") + isin(" << s2 << "))\n";
		cout << "\nEXPONENTIAL FORM OF THE NUMBER: " <<s1 << "(e^^(i(" << s2 << ")))\n";
		return a;
	}

	Complex TrigToAlgebra(Complex a)
	{
	    double s1, s2;
		cout << "ENTER A TRIGONOMETRIC TYPE. \nFOR EXAMPLE: 5(cos(180) + isin(180))\n";
		cout << "ENTER THE ABSOLUTE VALUE(MODULE): ";
		cin >> s1;
		cout << "ENTER THE FI ANGLE(e.g. 180): ";
		cin >> s2;
		cout << "\nYOU ENTERED: " << setprecision(2) << s1 << "(cos(" << setprecision(4) << s2 << ") + isin(" << s2 << "))\n";
		a.Re = sin(s2*3.14/180)*s1;
		a.Im = cos(s2*3.14/180)*s1;
		cout << "\nALGEBRAIC FORM OF THE NUMBER: "; Output(a);
	    return a;
	}

	Complex ExpoToAlgebra(Complex a)
	{
	    double s1, s2;
		cout << "ENTER AN EXPONENTIAL TYPE. \nFOR EXAMPLE: 5(e^^(i*180))\n";
		cout << "ENTER THE ABSOLUTE VALUE(MODULE): ";
		cin >> s1;
		cout << "ENTER THE FI ANGLE(e.g. 180): ";
		cin >> s2;
		cout << "\nYOU ENTERED: " << setprecision(2) << s1 << "(e^^(i(" << setprecision(4) << s2 << ")))\n";
		a.Re = sin(s2*3.14/180)*s1;
		a.Im = cos(s2*3.14/180)*s1;
		cout << "\nALGEBRAIC FORM OF THE NUMBER: "; Output(a);
		return a;
	}

	Complex ExpoToTrig(Complex a)
	{
		double s1, s2;
		cout << "ENTER AN EXPONENTIAL TYPE. \nFOR EXAMPLE: 5(e^^(i*180))\n";
		cout << "ENTER THE ABSOLUTE VALUE(MODULE): ";
		cin >> s1;
		cout << "ENTER THE FI ANGLE(e.g. 180): ";
		cin >> s2;
		cout << "\nYOU ENTERED: " << setprecision(2) << s1 << "(e^^(i(" << setprecision(4) << s2 << ")))\n";
		cout << "\nTRIGONOMETRIC FORM OF THE NUMBER: " << s1 << "(cos(" << s2 << ") + isin(" << s2 << "))\n";
		return a;
	}

	~Complex() {};
};



int main()
{
	Complex a, x(3,1), y(2,4), temporar;
	int power;
	double re = 0, im = 0;
	cout << "X: "; x.Output(x);
	cout << "Y: "; y.Output(y);
	cout << "=============================\n";
	cout << "POWER: "; cin >> power;
	cout << "POW: "; a.Output(x.Pow(x, power));
	cout << "=============================\n";
	cout << "SUM: "; a.Output(x.Sum(x, y));
	cout << "DIS: "; a.Output(x.Dis(x, y));
	cout << "MUL: "; a.Output(x.Mult(x, y));
	cout << "DIV: "; a.Output(x.Div(x, y));
	cout << "=============================\n";
	cout << "ABS: "; a.Output(x.Abs(x));
	cout << "ARG: "; a.Output(x.Arg(x));
	cout << "SIN: "; a.Output(x.Sin(x));
	cout << "COS: "; a.Output(x.Cos(x));
	cout << "TAN: "; a.Output(x.Tan(x));
	cout << "CTG: "; a.Output(x.Ctg(x));
	cout << "LNE: "; a.Output(x.Ln(x));
	cout << "LGG: "; a.Output(x.Lg(x));
	cout << "LOG: "; a.Output(x.Log(x));
	cout << "CON: "; a.Output(x.Conj(x));
	cout << "=============================\n";
	cout << "SETRE FOR Y: "; cin >> re; y.SetRe(re);
	cout << "SETIM FOR Y: "; cin >> im; y.SetIm(im);
	cout << "GETRE OF Y: "; cout << y.getRe();
	cout << "\nGETIM OF Y: "; cout << y.getIm();
	cout << "\n=============================\n";
	cout << "ALGEBRAIC TO TRIGONOMETRIC: "; y.AlgebraicToTrig();
	cout << "=============================\n";
	cout << "ALGEBRAIC TO EXPONENTIAL: "; y.AlgebraicToExpo();
	cout << "=============================\n";
	cout << "TRIGONOMETRIC TO EXPONENTIAL: "; x.TrigToExpo(temporar);
	cout << "=============================\n";
    cout << "TRIGONOMETRIC TO ALGEBRAIC: "; x.TrigToAlgebra(temporar);
	cout << "=============================\n";
	cout << "EXPONENTIAL TO TRIGONOMETRIC: "; x.ExpoToTrig(temporar);
	cout << "=============================\n";
	cout << "EXPONENTIAL TO ALGEBRAIC: "; x.ExpoToAlgebra(temporar);
	cout << "=============================\n";

	/*
	int power;
	cout << "POWER: ";
	cin >> power;*/

	//cout << "SUMM: "; Output(Sum(x, y));
	//cout << "DIST: "; Output(Dis(x, y));
	//cout << "PROD: "; Output(Mult(x, y));
	//cout << "DIV: ";  Output(Div(x, y));
	//cout << "SIN: "; Output(Sin(x));
	//cout << "COS: "; Output(Cos(x));
	//cout << "TAN: "; Output(Tan(x));
	//cout << "CTG: "; Output(Ctg(x));
	//cout << "LOG: "; Output(Log(x));
	//cout << "EXP: "; Output(Exp(x));
	//cout << "POW: "; Output(Pow(x, power));

	//cout << "ABS: " << Abs(x) << '\n';
	//cout << "ARG: " << Arg(x) << '\n';

}
