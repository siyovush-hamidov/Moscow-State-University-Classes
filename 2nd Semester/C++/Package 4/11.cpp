#include <iostream>
using namespace std;

void func(char *s, int i = 0, int res = 0){
	cin.getline(s,256);
	while(s[i]){
		if(*(s+i) >= '0' && *(s+i) <= '9'){
			res += *(s+i) - 48;
		}
		i++;
	}
	for(int i = 1; i < strlen(s); i++){
		if(*(s+i) == '-'){
			res -= (*(s+i+1) - 48) * 2;
		}
	}
	cout << res;
}

int main(int argc, char const *argv[])
{
	int res = 0, i = 0;
	char s[256];
	func(s,i,res);
}




