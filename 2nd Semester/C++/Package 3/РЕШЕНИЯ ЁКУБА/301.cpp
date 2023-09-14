#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int visited[n]{0}, d[200]{0}, i = 1;
    m *= 10;
    int r = m % n;
    while(visited[r] == 0 || m / n != d[visited[r]]){
        visited[r] = i;
        d[i++] = m / n;
        m = 10 * r;
        r = m % n;
    } 
    int l_period = i - visited[r];    
    if(d[i-1]==0 && l_period == 1){
        i--;
        l_period--;
    }          
    //cout << l_period << '\n';
    //for(int j = 1; j < i; j++) cout << d[j] << ' ';
    string res = "0.";
    for(int j = 1; j < i; j++){
        if(j == i - l_period) res += '(';
        res += (d[j] + '0');
    }
    if(l_period > 0) res += ')';
    cout << res << '\n';
}
