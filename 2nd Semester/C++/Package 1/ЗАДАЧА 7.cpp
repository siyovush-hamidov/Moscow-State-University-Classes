#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, a[100], *p = a, max = 0, fir = 69, sec = 96, z = 0;
	while(cin >> *p++){
		n++;
		max = a[0];
	}
	p = a;

	for(int i = 0; i < n; i++){
		if(*(a+i) > max) {
			z = i;
			max = *(a+i);
		}
	}
	//СЛЕВА
	for(int i = n + 2; i >= z; i--){
		*(a+i) = *(a+i-1);
	}
	//CПРАВА
	for(int i = n + 2; i > z+2; i--){
		*(a+i) = *(a+i-1);
	}
	//НАЗНАЧЕНИЕ
	*(a+(z)) = fir;
	*(a+(z+2)) = sec;

	cout << "position " << z << endl;
	cout << max << " " << "MAX" << endl;
	for(int i = 0; i < n+2; i++){
		cout << *p++ << " ";
	}

}