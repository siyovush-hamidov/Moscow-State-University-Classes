#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    int m = 0;
    for(int i=0; i<n; i++){
        bool check = true;
        for(int j=i+1; j<n; j++){
            if(*(a+i)==*(a+j)) check = false;
        }
        if(check) m++;
    }
    cout << m;
	}
	