#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

int func(char *s, int res = 0){
	cin.get(s,256);
	while(*s != '\0'){
		while((*s < '0' || *s > '9') && *s != '.'){
			cout << 0;
			return 0;
		}
		if (*s == '.') res++;
		s++;
	}
	if (res > 1) cout << 0;
	else if(res == 1) cout << 2;
	else cout << 1;
	
	}

int main(int argc, char const *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int res = 0;
	char s[256];
	func(s,res); 
}

