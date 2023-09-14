#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100], b[100], *p = a, *q = b, sa = 0, sb = 0;
    while(cin >> *p++) sa++;
    cin.clear();
    cin.ignore();
    while(cin >> *q++) sb++;
    int c[100], *r = c;
    p = a;
    q = b;
    for(int i=0; i<sa; i++) *r++ = *p++;
    for(int i=sa; i<sa+sb; i++) *r++ = *q++;
    r = c;
    sort(r, r+sa+sb);
    for(int i=0; i<sa+sb; i++) cout << *r++ << ' ';
}