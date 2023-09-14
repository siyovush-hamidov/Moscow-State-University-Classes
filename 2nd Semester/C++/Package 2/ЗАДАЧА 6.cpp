#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char s[256];
	cin.getline(s,256);
	char *p = s;
	int blank = 0;
	bool aha = false;

	for(int i = 0; i < strlen(s); i++){
		if(*(s+i) == ' ') blank = i;
	}
	
	for(int i = 0; i < blank; i++){
		aha = false;
		for(int k = blank+1; k < strlen(s); k++){
			if(*(s+i) == *(s+k)){
				aha = true;
				break;
			}
		}
		if(aha) cout << "YES" << " ";
		else cout << "NO" << " ";
	}
}

