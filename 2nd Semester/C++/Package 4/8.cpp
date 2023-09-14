#include <iostream>
#include <windows.h>
using namespace std;

void func(char *s, int i = 0){
	
	cin.getline(s,256);
	while(s[i]){
		cout << *(s+i) - 48 << " ";
		
		i++;
	}
}
	


int main(int argc, char const *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i = 0;
	char s[256];
	func(s,i); 
}