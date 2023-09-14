#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char s[256], c[256][256];
	cin.getline(s,256);
	char *p = s;
	int k = 0, r = 0;
	
	while(*p != '\0') { 
	if(*p == ' '){
		*(*(c+k)+r) = '\0';
		k++;
		r = 0;
	}
	else{
		*(*(c+k)+r) = *p;
		r++;
	}
	p++;
	}
	*(*(c+k)+r) = '\0';
	
//	for(int i = 0; i <= k; i++){
//		if(c[i] > c[i+1]) swap(c[i],c[i+1]);
//	}	
	
	for(int i = k; i >= 0; i--) cout << c[i] << '\n';
}

