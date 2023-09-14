#include <iostream>

void function(int a, int b, int* result){
    while(b > 0){
        if(b % 2 == 0){
            a *= a;
            b /= 2;
        }
        else{   
            *result = *result * a;
            b -= 1;
        }
    }
}

int main()
{
    int x, n, result = 1;
    std::cin >> x >> n;
    function(x, n, &result);
    std::cout << result;
}