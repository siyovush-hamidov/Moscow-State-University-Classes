#include <iostream>
using namespace std;

bool is_prime(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void print_prime(int* k, int p){
    if(is_prime(p)){
        *k += 1;
        cout << p << ' ';
    } 
}

int main()
{
    int n;
    cin >> n;
    int k = 0;
    int p = 2;
    while(k < n){
        print_prime(&k, p);
        p++;
    }
}