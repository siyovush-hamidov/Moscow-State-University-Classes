#include <iostream>
using namespace std;

void func(char *s, int i = 0, int res = 0){
	cin.getline(s,256);

	while(s[i]){
		if(*(s+i) == '1'){
			res = (res * 2) + 1;
		}
		else{
			if(*(s+i) == '0'){
			res *= 2;
		}
		}
		i++;
	}
	
	cout << res;
}

int main(int argc, char const *argv[])
{
	int res = 0, i = 0;
	char s[256];
	func(s,i,res);
}




