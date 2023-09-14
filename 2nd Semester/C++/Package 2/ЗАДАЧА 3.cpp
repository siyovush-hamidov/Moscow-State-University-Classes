#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char s[256];
	cin.getline(s,256);
	int i = 0, count = 1, q = 1;
	char *p = s;
	
	
	while(s[i]){
		count = 1;
		while(*(s+i) == *(s+i+1)){
			count++;
			i++;
		}
		q = max(count, q);
		i++;
	}
	q = max(count, q);
	cout << q;
}