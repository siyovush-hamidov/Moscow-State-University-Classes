#include <iostream>
#include <cstring>
using namespace std;
void func(char *s, int i = 0, int v = 0, string res = 0){
	cin.getline(s,256);
		while(s[i]){
			if(*(s+i) >= '1' && *(s+i) <= '9'){
			v = 0;
            while(*(s+i)>='0' && *(s+i)<='9'){
                v = 10*v + (*(s+i) - 48);
			i++;
		}
	}
}
    while(v > 0){
        if(v % 2 == 0) res += '0';
        else res += '1';
        v/=2;
    }
    reverse(res.begin(), res.end());
    cout << res;
}

int main(int argc, char const *argv[])
{
	int i = 0, v = 0;
	string res = 0;
	char s[256];
	func(s,i,v,res);
}




