#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, a[100], *p = a, min = 0, max = 0;
	while(cin >> *p++){
		n++;
		min = a[0];
		max = a[0];
	}
//	p = a;
	for(int i = 0; i< n; i++){
		if(*(a+i) <= min){
			min = *(a+i);
		}
	}
	for(int i = 0; i<n; i++){
		if(*(a+i) >= max){
			max = *(a+i);
		}
	}
	for(int q = 0; q < 2; q++){
		for(int i = 0; i<n; i++){
			if(*(a+i) == min){
				swap(*(a+i),*(a+i+1));
			}
		}
	}
	for(int q = 0; q < 2; q++){
		for(int i = 0; i<n; i++){
			if(*(a+i) == max){
				swap(*(a+i),*(a+i+1));
			}
		}
	}
	
	p = a;
	for(int i = 0; i<n; i++){
		if(*(a+i) > min && *(a+i) < max){
			cout << *p++ << " ";
		}
	}
}