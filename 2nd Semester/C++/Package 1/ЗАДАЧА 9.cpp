#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, a[100], *p = a, aha = 1;
	while(cin >> *p++){
		n++;
	}
	for(int i = 0; i < n; i++){
		for(int k = i+1; k < n; k++){
			if(*(a+i) == *(a+k)){
				aha++;
				cout << *(a+i) << " " << *(a+k);
			} 
		}
	}
}