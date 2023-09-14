#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, x, a[100];
	while(cin >> x){
		n++;
		a[n] = x;
	}
	int *p = a;
	
	for(int i = 0; i < n/2; i+=1){
//		cout << *((p+1) + i) << " "<< *(p+n-i) << endl;
		if(*((p+1) + i) != *(p+n-i)) return 0;
	}
	cout << "yes";
}