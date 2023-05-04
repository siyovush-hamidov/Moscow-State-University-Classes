#include <iostream>

using namespace std;

template <class T>

int QuantityOfDifferentRows(T **arr, int n, int m)
{
    int ans = n; bool bans;
    for(int i = 0; i < n; i++)
    {
        bans = false;
        for(int j = 0; j < m - 1; j++)
        {
            for(int k = j + 1; k < m; k++)
            if(arr[i][j] == arr[i][k])
            {
                bans = true;
                break;
            }
            if(bans) break;
        }
        if(bans) ans--;
    }
    return ans; 
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    int **arr;
    arr = new int*[n];
    for(int i = 0; i < n; i++) arr[i] = new int [m];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];

    int ans = QuantityOfDifferentRows(arr, n, m);

    cout << ans;
}