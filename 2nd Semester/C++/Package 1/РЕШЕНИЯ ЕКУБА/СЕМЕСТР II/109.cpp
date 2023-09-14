#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *a = new int[50], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(*(p+i)==*(p+j)){
                cout << *(p+i);
                return 0;
            }
        }
    }
    delete[] a;
    return 0;
}