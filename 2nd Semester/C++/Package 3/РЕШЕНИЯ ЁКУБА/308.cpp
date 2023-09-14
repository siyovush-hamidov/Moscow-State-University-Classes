#include <iostream>
using namespace std;

void count_k(int n, int k, int* c){
    while(n > 0){
        if(n % 10 == k) *c += 1;
        n /= 10;
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    int c = 0;
    for(int i = 1; i <= n; i++){
        count_k(i, k, &c);
    }
    cout << c << '\n';
    return 0;
}