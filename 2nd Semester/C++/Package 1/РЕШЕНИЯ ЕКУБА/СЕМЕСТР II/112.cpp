#include <iostream>
using namespace std;
int main()
    /// n = 13
{   /// 1 1 2 1 3 4 2 0 0 3 1 8 8
    int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    for(int i = n-2; i > 0; i--){
        if(*(p+i)>*(p+i+1) && *(p+i)>*(p+i-1)){
            for(int j=0; j<i-1; j++){
                cout << *(p+j) << ' ';
            }
            break;
        }
    }
}