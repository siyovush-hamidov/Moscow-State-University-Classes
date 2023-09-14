#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char s[256];
	int i = 0, count = 0, q = 0;
	char *p = s;
	cin.getline(s,256);
	
	for(int i = 0; i < strlen(s); i++){
		bool check = true;
		for(int k = i+1; k < strlen(s); k++){
			if(*(s+i) == *(s+k)) check = false;	
		}
		if(check) q++;
	}
	cout << q;
}