#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <cctype>
using namespace std;

void func1(char *s, int q = 0, int i = 0){
	cin.getline(s,256);
	
	while(s[i]){
		if((*(s+i) >= 65 && *(s+i) < 91) || (*(s+i) >= 97 && *(s+i) < 122)){
			q+=1;
		}
		i++;
	}
	cout << q;
}

int main(int argc, char const *argv[])
{
	int q = 0, i = 0;
	char s[256];
	func1(s,q,i);
}
