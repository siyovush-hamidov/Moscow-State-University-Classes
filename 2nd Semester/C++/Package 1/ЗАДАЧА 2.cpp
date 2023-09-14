#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[100], n = 0, *p = a;
    while(cin >> *p++) n++;
    p = a;
    for(int i=0; i<n/2; i++){
        swap(*(a+i), *(a+n-1-i));
    }
    p = a;
    for(int i=0; i<n; i++){
        cout << *p++ << ' ';
    }
}