#include <iostream>
using namespace std;

void power(int a, int b, int* res){
    while(b > 0){
        if(b % 2 == 0){
            a *= a;
            b /= 2;
        }
        else{   
            *res = *res * a;
            b -= 1;
        }
    }
}

int main()
{
    int x, n, result = 1;
    cin >> x >> n;
    power(x, n, &result);
    cout << result;
}