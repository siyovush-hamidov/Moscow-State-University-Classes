#include <iostream>
using namespace std;
int main(){
    int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    bool check = true;
    while(check){
        check = false;
        for(int i=0; i<n-1; i++){
            if(*(a+i)<0 && *(a+i+1)>=0){
                swap(*(a+i), *(a+i+1));
                check = true;
            } 
        }
        if(*(a+n-1)<0) n--;
    }
    for(int i=0; i<n; i++) cout << *p++ << ' ';
}
