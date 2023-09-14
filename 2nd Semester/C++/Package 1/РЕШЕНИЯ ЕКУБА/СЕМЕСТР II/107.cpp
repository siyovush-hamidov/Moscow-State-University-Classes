#include <iostream>
using namespace std;
int main()
{
    int a[100], n = 0, *p = a, mxi = 0;
    int f, s;
    cin >> f >> s;
    while(cin >> *p){
        if(*p>*(a+mxi)){
            mxi = n;
        }
        n++;
        p++;
    }
    cout << mxi << endl;
    cout << *(a+mxi) << endl;
    p = a+n+1;
    while(*(p-2)!=*(a+mxi)){
        *p = *(p-2);
        p--; 
    }  
    *p = f;
    *--p = *(a+mxi);
    *--p = s;
    p = a;
    for(int i=0; i<n+2; i++) cout << *p++ << ' ';
}