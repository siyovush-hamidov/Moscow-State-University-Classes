#include <iostream>
#include <windows.h>

using namespace std;

void func1(char *s, int q = 0, int i = 0){

	cin.getline(s,256);
	while(s[i]){
		if((*(s+i) >= char('а') && *(s+i) <= char('я')) || (*(s+i) >= 'a' && *(s+i) < 'z')){
			q+=1;
		}
		i++;
	}
	cout << q;
}

int main(int argc, char const *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int q = 0, i = 0;
	char s[256];
	func1(s,q,i);
}
