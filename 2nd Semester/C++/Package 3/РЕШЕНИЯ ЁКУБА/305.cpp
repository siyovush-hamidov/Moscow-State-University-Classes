#include <iostream>
using namespace std;

bool isprime(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void degree_of_p(int n, int p, int* c){
    while(n % p == 0){
        *c += 1;
        n /= p;
    }
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++){
        if(isprime(i)){
            int c = 0;
            degree_of_p(n, i, &c);
            if(c > 0) cout << i << ' ' << c << " ";
        }
    }
}