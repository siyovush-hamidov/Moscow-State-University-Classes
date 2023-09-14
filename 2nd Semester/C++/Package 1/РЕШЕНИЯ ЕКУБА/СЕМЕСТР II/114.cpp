#include <iostream>
using namespace std;
int main()
{
    int c, r;
    cin >> r >> c;
    int m[r][c], s = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> m[i][j];
        }
    }  
    for(int i=0; i<c; i++) s += m[0][i];
    int mnr = 1;
    for(int i=1; i<r; i++){
        int current = 0;
        for(int j=0; j<c; j++){
            current += m[i][j]; 
        }
        if(current < s){
            s = current;
            mnr = i + 1;
        }
    }
    cout << mnr;
    return 0;
}