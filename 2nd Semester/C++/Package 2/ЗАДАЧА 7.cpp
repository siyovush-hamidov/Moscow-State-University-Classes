#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char s[256];
	cin.getline(s,256);
	char *p = s;
	int blank = 0;
	bool aha = true;

	for(int i = 0; i < strlen(s); i++){
		if(*(s+i) == ' ') blank = i;
	}
	
	for(int i = 0; i < blank; i++){
		aha = true;
		for(int k = blank+1; k < strlen(s); k++){
			if(*(s+i) == *(s+k)){
				aha = false;
				break;
			}
		}
		if(aha) cout << *(s+i) << " ";
	}
	for(int i = blank+1; i <strlen(s) ; i++){
		aha = true;
		for(int k = 0; k < blank ; k++){
			if(*(s+i) == *(s+k)){
				aha = false;
				break;
			}
		}
		if(aha) cout << *(s+i) << " ";
	}
}

