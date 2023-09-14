#include <iostream>

int function(int n, int *p, int *p1, int k, int q){

	*p = n;
	*p1 = k;
	if(*p1 > 9){ std::cout << "ERROR ( k > 9)"; return 0; } 
	if(*p1 <= *p % 10) q+=1;
	if(*p1 < *p / 10) { for(int i = 0; i < 9; i++) q++;}
	if(*p1 == *p / 10) { for(int i = 0; i < *p % 10; i++) q++;}
	for(int i = 10; i <= *p; i += 10) q++; 

	std::cout << q;
}

int main(int argc, char const *argv[])
{
	int n, k, q = 0, *p = &n, *p1 = &k;
	std:: cout << "N: ";
	std::cin >> *p;
	std:: cout << "K: ";
	std:: cin >> *p1 ; 
	std:: cout << "Q = ";
	function(n,p,p1,k,q);
}