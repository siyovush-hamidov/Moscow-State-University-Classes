#include <iostream>
using namespace std;
int main()
{
    int c, r;
    cin >> r >> c;
    int m[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> m[i][j];
        }
    }
    int mn = m[0][0], rmn = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(m[i][j]<mn) rmn = i+1;
        }
    }
    cout << rmn;
    return 0;    
}