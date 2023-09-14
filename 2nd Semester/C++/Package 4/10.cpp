#include <iostream>
using namespace std;

void func(char *s, int i = 0, int sum = 0){
	cin.getline(s,256);
	while(s[i]){
		if(*(s+i) >= '0' && *(s+i) <= '9'){
			sum += *(s+i) - 48;
		}
		i++;
	}
	cout << sum;
}

int main(int argc, char const *argv[])
{
	int sum = 0, i = 0;
	char s[256];
	func(s,i,sum);
}




