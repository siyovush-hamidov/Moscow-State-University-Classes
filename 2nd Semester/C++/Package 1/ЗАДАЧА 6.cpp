#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, a[100], *p = a;
	while(cin >> *p++){
		n++;
	}
	int  q = 0;
	p = a;
	
		for(int k = 0; k < n; k++){
			if(*(a+k) < 0 ){
			q++;
}
}
	for(int i = 0; i < q; i++){
		for(int k = 0; k < n-1; k++){
			if(*(a+k) < 0 ){
			swap(*(a+k), *(a+k+1));
}
}
}
	for(int i = 0; i < n; i++){
		cout << *p++ << " ";
	}
	cout << endl;
	cout << q;
}