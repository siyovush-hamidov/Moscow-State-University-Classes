#include <iostream>

bool aha(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void printer(int* a, int b){
    if(aha(b)){
        *a += 1;
        std::cout << b << ' ';
    } 
}

int main(int argc, char const *argv[])
{
	int n;
    std::cin >> n;
    int a = 0;
    int b = 2;
    while(a < n){
        printer(&a, b);
        b++;
    }
    return 0;
}