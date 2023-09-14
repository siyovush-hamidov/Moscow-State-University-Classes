#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    /*
    for(int i=0; i<n; i++){
        cout << p << ' ' << *p++ << ' ';
    }
    */
    for(int i=0; i<n/2; i++){
        swap(*(a+i), *(a+n-1-i));
    }
    //cout << endl;
    p = a;
    for(int i=0; i<n; i++){
        cout << p << ' ' << *p++ << ' ';
    }
}