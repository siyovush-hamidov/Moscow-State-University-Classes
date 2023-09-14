#include <iostream>
using namespace std;

void digits(int n, int* a, int* b, int* c){
    *c = n % 10;
    *b = (n / 10) % 10;
    *a = n / 100;
}
string ones(int n){

    switch(n){
        case 1:
            return "odin";
            break;
        case 2: 
            return "dva";
            break;
        case 3:
            return "tri";
            break;
        case 4:
            return "chetire";
            break;
        case 5:
            return "pyat";
            break;
        case 6:
            return "shest";
            break;
        case 7:
            return "sem";
            break;
        case 8:
            return "vosem";
            break;
        case 9:
            return "devyat";
            break;
        default:
            return "";
            break;
    }
}

string tens(int n, int m){
    switch(n){
        case 1:
            switch (m)
            {
            case 1:
                return "odinnadsat ";
                break;
            case 2:
                return "dvenadsat ";
                break;
            case 3:
                return "trinadsat ";
                break;
            case 4:
                return "chetirnadsat ";
                break;
            case 5:
                return "pyatnadsat ";
                break;
            case 6:
                return "shestnadsat ";
                break;
            case 7:
                return "semnadsat ";
                break;
            case 8:
                return "vosemnadsat ";
                break;
            case 9:
                return "devyatnadsat ";
                break;
            default:
                return "desyat";
                break;
            }
        case 2:
            return "dvadsat ";
            break;
        case 3:
            return "tridsat ";
            break;
        case 4:
            return "sorok ";
            break;
        case 5:
            return "pyatdesyat ";
            break;
        case 6:
            return "shestdesyat ";
            break;
        case 7:
            return "semdesyat ";
            break;
        case 8:
            return "vosemdesyat ";
            break;
        case 9:
            return "devyanosto ";
            break;
        default:
            return "";
            break;
    }
}

string hundreds(int n){
    switch(n){
        case 1:
            return "sto ";
            break;
        case 2:
            return "dvesti ";
            break;
        case 3:
            return "trista ";
            break;
        case 4:
            return "chetiresta ";
            break;
        case 5:
            return "pyatsot ";
            break;
        case 6:
            return "shestsot ";
            break;
        case 7:
            return "semsot ";
            break;
        case 8:
            return "vosemsot ";
            break;
        case 9:
            return "devyatsot ";
            break;
        default:
            return "";
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    int a, b, c; 
    digits(n, &a, &b, &c);
    if(b==1){
        cout << hundreds(a) + tens(b, c)<< '\n';
    }
    else cout << hundreds(a) + tens(b, c) + ones(c) << '\n';
}