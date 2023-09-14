#include <iostream>
#include <clocale>
using namespace std;

int main(int argc, char const *argv[]){
	setlocale(LC_ALL, "rus");  
	char a[256], b[256], c[256];
	cout << "ENTER 1: ";
	cin.get(a,256);
	cin.clear();		
	cin.ignore();	
	cout << "ENTER 2: "; 
	cin.get(b,256);			
	char *x = a, *y = b, *z = c;
	int n = strlen(a), temp = 0;
	
	
	for(int i = n-1; i >= 0; i--){
		
			*(c+i) = (*(a+i) + *(b+i)) + temp - 48;	
			if(*(c+i) > '9'){
			*(c+i) -= 10;
			temp = 1;
		}
		else temp = 0;
		}
		cout << temp << " ";
		for(int i = 0; i < n+1; i++){
			cout << *(c+i) << " ";
	}
		
}