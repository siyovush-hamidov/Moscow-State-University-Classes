#include <iostream>

int function(int a, int b, int* p){
	
	while(a != 0 && b != 0){
		if(a>b){
			a = a % b;
		}
		else{
			if(b > a){
				b = b % a;
			}
		}
	}
	*p = a + b;
	std:: cout << *p;
}

int main(int argc, char const *argv[])
{
	int a, b, p;
	std:: cin >> a >> b;
	function(a, b, &p);
}