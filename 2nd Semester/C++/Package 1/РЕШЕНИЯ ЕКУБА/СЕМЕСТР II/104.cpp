#include <bits/stdc++.h>
using namespace std;
/// 1 4 2 0 3 6 7 5 
int main()
{
    int a[100], n = 1, *p = a;
    cin >> *p;
    int mn = *p, mx = *p;
    p++;
    while(cin >> *p){
        if(*p>mx) mx = *p;
        if(*p<mn) mn = *p;
        n++;
        p++;
    }
    p = a;   
    for(int i=0; i<n-1; i++){
        if(*p++==mn) swap(*p, *(p-1));
    } 
    n--;
    p = a;
    for(int i=0; i<n-1; i++){
        if(*p++==mx) swap(*p, *(p-1));
    } 
    n--;
    p = a;
    for(int i=0; i<n; i++){
        cout << *p++ << ' ';
    }
}