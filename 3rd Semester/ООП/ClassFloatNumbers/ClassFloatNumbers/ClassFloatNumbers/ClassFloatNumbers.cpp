#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

class FNUM
{
public:

    struct FN
    {
        long numer;
        long denom;
    };

    void Input(FN *a)
    {
        cin >> a->numer >> a->denom;
    }

    int LCM(FN a, FN b)
    {
        int max;
        max = (a.denom > b.denom)? a.denom : b.denom;
        do
    {
        if (max % a.denom == 0 && max % b.denom == 0)
        {
            // cout << "LCM = " << max;
            break;
        }
        else
            ++max;
    } while (true);

    return max;
    }
    
    int HCD(FN a)
    {
        int hcf;
        if(a.numer > a.denom){
            int temp = a.numer;
            a.numer = a.denom;
            a.denom = temp;
        }
        for (int i = 1; i <=  a.denom; ++i) {
            if (a.numer % i == 0 && a.denom % i ==0) {
                hcf = i;
            }
        }
        return hcf;
    }

    void separator()
    {
        cout << "===============================\n";
    }

    void Output(FN a)
    {
        if(a.denom/HCD(a) == 1){
            cout << a.numer/HCD(a) << "\n";
        }
        else{
            cout << a.numer/HCD(a) << '/' << a.denom/HCD(a) << "\n";
        }
    }
 
    FN SUM(FN a, FN b)
    {
        FN x;

        x.denom = LCM(a,b);
        a.numer *= (LCM(a,b) / a.denom);
        b.numer *= (LCM(a,b) / b.denom);

        x.numer = a.numer + b.numer;
        return(x);
    }

    FN SUB(FN a, FN b)
    {
        FN x;
        x.denom = LCM(a,b);
        a.numer *= (LCM(a,b) / a.denom);
        b.numer *= (LCM(a,b) / b.denom);

        x.numer = a.numer - b.numer;
        return(x);
    }

    FN MUL(FN a, FN b)
    {
        FN x;
        x.numer = a.numer * b.numer;
        x.denom = a.denom * b.denom;
        return(x);
    }

    FN DIV(FN a, FN b)
    {
        FN x;
        x.numer = a.numer * b.denom;
        x.denom = a.denom * b.numer;
        return x;
    }

    FN SQ(FN a, int p)
    {
        a.numer = pow(a.numer, p);
        a.denom = pow(a.denom, p);
        return a;
    }

    FN SQF(FN a, FN b)
    {
        FN x;
        double n;
        n = double(b.numer) / double(b.denom);
        x.numer = pow(a.numer, n);
        x.denom = pow(a.denom, n);
        cout << x.numer << "/" << x.denom;
        return x;
    }
};


int main()
{
    FNUM z;
    FNUM :: FN x;
    FNUM :: FN y;

    // cin >> x.numer >> x.denom >> y.numer >> y.denom;
    z.Input(&x);
    z.Input(&y);
    z.separator();

    if(x.denom == 0){
        string ans;
        cout << "ERROR: Denominator of x = 0. The programm will be terminated. Would you like to reset x.denom? [Y/n] ";
        cin >> ans;
        if(ans == "y" || ans == "Y"){
            cout << "Enter a denominator for X: ";
            cin >> x.denom;
        }
        else
        {
            cout << "The programm is terminated.";
            return 0;
        }
        z.separator();
    }
    if(y.denom == 0){
        string ans;
        cout << "ERROR: Denominator of y = 0. The programm will be terminated. Would you like to reset y.denom? [Y/n] ";
        cin >> ans;
        if(ans == "y" || ans == "Y"){
            cout << "Enter a denominator for Y: ";
            cin >> y.denom;
        }
        else
        {
            cout << "The programm is terminated.";
            return 0;
        }
        z.separator();
    }

    cout << "x = "; z.Output(x);
    cout << "y = "; z.Output(y);
    z.separator();
    int p;
    cout << "Enter The Power: ";
    cin >> p;
    z.separator();

    

    cout << "SUM: "; z.Output(z.SUM(x,y));
    cout << "SUB: "; z.Output(z.SUB(x,y));
    cout << "MUL: "; z.Output(z.MUL(x,y));
    cout << "DIV: "; z.Output(z.DIV(x,y));
    z.separator();
    cout << "ToInt: "; z.Output(z.SQ(x,p));
    cout << "ToFloat: "; z.SQF(x,y);
}
