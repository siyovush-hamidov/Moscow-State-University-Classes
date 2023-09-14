#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100], n = 0;
    while(cin >> a[n]) n++;
    for(int i=0; i<n/2; i++){
        if(*(a+i) != *(a+n-1-i)){
            cout << "Not symmetric\n";
            return 0;
        }
    }
    cout << "Symmetric\n";
    return 0;
}