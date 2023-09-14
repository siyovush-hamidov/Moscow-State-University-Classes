#include <iostream>

int function(int n, int *p,int r, int *p1, int q = 0){
	*p = n;
	*p1 = r;
	while(*p > 1){
		*p1 = *p % 2;
		if(*p1 == 1) q++;
		*p = *p / 2;	
	}
	if((q+1) % 2 == 0) std::cout << "EVEN";
	else std::cout << "ODD";
	}
	
int main(int argc, char const *argv[])
{
	int n, r, q, *p = &n, *p1 = &r;
	std::cin >> *p;
	function(n,p,r,p1,q);
}