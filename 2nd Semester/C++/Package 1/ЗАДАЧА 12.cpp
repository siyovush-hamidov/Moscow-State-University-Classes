#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[100], n = 0, *p = a, b = 0;
	bool aha = false;
	while( cin >> *p++){
		n++;
	}
	p = a;
	
	for(int i = 1; i < n-1; i++){
		if(*(a+i) > *(a+i-1) && *(a+i) > *(a+i+1)){
			aha = true;
		}
	}
	if(aha){
		for(int i = 1; i < n-1; i++){
		if(*(a+i) > *(a+i-1) && *(a+i) < *(a+i+1)){
//			cout << *(a+i-1) << " " << *(a+i) << " " << *(a+i+1);
			b = i;		}
	}
	for(int i  = 0; i < b; i++){
		cout << *p++ << " " ;
	}
}
}