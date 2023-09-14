#include <iostream>
#include <windows.h>
using namespace std;

void func1(char *s, int q = 0, int i = 0){
	cin.getline(s,256);
	
	while(s[i]){
		if(*(s+i) >= 'a' && *(s+i) <= 'z'){
			*(s+i) -= 32;
		}
		// else {
		// if(*(s+i) >= char('а') && *(s+i) <= char('я')){
		// *(s+i) -= 32;
// }
// }
		cout << *(s+i);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int q = 0, i = 0;
	char s[256];
	func1(s,q,i); 
}
