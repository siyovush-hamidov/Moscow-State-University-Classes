#include <iostream>
using namespace std;
void gcd(int a, int b, int* g){
    while(b != 0){
        int temp = a;
        *g = b;
        a = b;
        b = temp % b; 
    }
}

int main()
{
    int a, b, g;
    cin >> a >> b;
    gcd(a, b, &g);
    cout << g << '\n';
}