#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    int m = 0;
    for(int i=0; i<n; i++){
        bool check = true;
        for(int j=i+1; j<n; j++){
            if(*(p+i)==*(p+j)) check = false;
        }
        if(check) m++;
    }
    cout << m;
}