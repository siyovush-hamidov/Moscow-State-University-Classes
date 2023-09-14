#include <iostream>
using namespace std;
int main()
{
    int a[100], *p = a, n = 0;
    while(cin >> *p++) n++;
    p = a;
    int m = 0;
    for(int i=0; i<n; i++){
        bool check = true;
        for(int j=0; j<i; j++){
            if(*(p+i)==*(p+j)) check = false;
        }
        if(check){
            *(p+m) = *(p+i);
            m++;
        }
    }
    for(int i=0; i<m; i++) cout << *p++ << ' ';
}