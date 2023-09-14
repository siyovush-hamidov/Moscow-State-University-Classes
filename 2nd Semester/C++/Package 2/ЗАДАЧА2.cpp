#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int i = 0, sum = 0, max = 0, v = 0;
	char s[256];
	cin.getline(s, 256);
	char *p = s;

	while(s[i]){
		if(*(s+i) >= '1' && *(s+i) <= '9'){
			v = 0;
            while(*(s+i)>='0' && *(s+i)<='9'){
                v = 10*v + (*(s+i) - 48);
                if(max < v) max = v;
                i++;
            }
            sum += v;
            }
            i++;
		}

	cout << sum;
	cout << endl;
	cout << max;
}

