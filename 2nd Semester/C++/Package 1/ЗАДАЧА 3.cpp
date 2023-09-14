#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, a[100], *p = a, quantity = 0;
	while(cin >> *p++){
		n++;
	}
	p=a;
	for(int i = 0; i<n; i++){
		if(*(a+i) < 0) {
			quantity+=1;
		}
	}
	for(int q = 0; q<=quantity; q++){
		for(int i = 0; i<n; i++){
			if(*(a+i) < 0) { 
			swap(*(a+i), *(a+i+1));
			}
		}
	}
	for(int i = 0; i<n; i++){
			if(*(a+i) > 0){
				cout << *p++ << " ";
			}
		}
	}