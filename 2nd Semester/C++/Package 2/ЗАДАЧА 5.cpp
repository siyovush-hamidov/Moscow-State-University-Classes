#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	
	char s[256];
	cin.getline(s,256);
	char *p = s;
	int first, second, q = 0;
	bool aha = false;
	setlocale(LC_ALL,"Russian");
	
	for(int i = 0; i < strlen(s); i++){
		for(int j = i+1; j < strlen(s); j++){
			if(*(s+i) == *(s+j)){
				q++;
				aha = true;
				first = *(s+i);
				second = *(s+j);
			}
			if(q > 2) aha = false;
		}
	}
	if(aha) cout << (char)first << " " << (char)second;
	else cout << "ERROR";
}