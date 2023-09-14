#include <iostream>

bool function(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
	int n, *p = &n;
	std:: cin >> *p;
	
	for(int i = 1; i < *p; i++){
		for(int k = 1; k < *p/2; k++){
			if(function(i) && function(k)){
				if(i * k == *p){
					std:: cout << i << " * " << k << " = " << *p << '\n'; 
				}
			}
		}
	}
}
	
	
