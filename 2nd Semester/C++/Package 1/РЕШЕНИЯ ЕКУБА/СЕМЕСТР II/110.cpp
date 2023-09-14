#include <iostream>
using namespace std;
int main()
{
    int a[100], n = 0, *p = a, x;
    cin >> x;
    while(cin >> *p++) n++;
    int l = 0, r = n;
    int m = (l+r)/2;
    while(l<=r){ 
        m = (l+r)/2;
        if(*(a+m)==x) break;
        if(*(a+m)<x) l = m+1;
        else r = m-1;
    }
    cout << m << endl;
    p = a+n;
    for(int i=0; i<n-m; i++){
        *p = *(p-1);
        p--;
    }
    *p = x;
    p = a;
    for(int i=0; i<=n; i++) cout << *p++ << ' ';
}