#include <iostream>
using namespace std;

void count_1(int n, int* c){
    while(n > 0){
        if(n % 2 == 1) *c += 1;
        n /= 2;
    }
}

int main()
{
    int n;
    cin >> n;
    int c = 0;
    count_1(n, &c);
    cout << ((c % 2 == 0) ? "YES\n" : "NO\n");
}