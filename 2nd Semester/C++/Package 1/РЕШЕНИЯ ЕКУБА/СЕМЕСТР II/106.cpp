#include <iostream>
using namespace std;
int main()
{
    int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    bool check = true;
    while(check){
        p = a;
        check = false;
        for(int i=0; i<n-1; i++){
            if(*p<0 && *(p+1)>=0){
                swap(*p, *(p+1));
                check = true;
            } 
            p++;
        }
    }
    p = a;
    for(int i=0; i<n; i++) cout << *p++ << ' ';
    return 0;
}