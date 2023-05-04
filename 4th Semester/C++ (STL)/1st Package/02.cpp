#include <iostream>

using namespace std;

template <class T>

int QuantityOfAscendingRows(T **arr, int n, int m)
{
    int ans = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m-1; j++)
        {
            if(arr[i][j] >= arr[i][j + 1])
            {
                ans--;
                break;
            }
        }
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

    int ans = QuantityOfAscendingRows(arr, n, m);

    cout << ans;
}