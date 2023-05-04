#include <iostream>

using namespace std;

template <class T>

void ReplaceLocalMinimums(T **arr, int n, int m)
{   
    int **temp;
    temp = arr;

    if(arr[0][0]<arr[0][1] && arr[0][0]<arr[1][1] && arr[0][0]<arr[1][0]) temp[0][0] = 0;

    if(arr[0][m-1]<arr[0][m-2] && arr[0][m-1]<arr[1][m-2] && arr[0][m-1]<arr[1][m-1]) temp[0][m-1] = 0;

    if(arr[n-1][0]<arr[n-2][0] && arr[n-1][0]<arr[n-2][1] && arr[n-1][0]<arr[n-1][1]) temp[n-1][0] = 0;

    if(arr[n-1][m-1]<arr[n-1][m-2] && arr[n-1][m-1]<arr[n-2][m-2] && arr[n-1][m-1]<arr[n-2][m-1]) temp[n-1][m-1] = 0;

    for(int i = 1; i < n-2; i++)
    {
        if(arr[i][0]<arr[i-1][0] && arr[i][0]<arr[i-1][1] && arr[i][0]<arr[i][1] && arr[i][0]<arr[i+1][1] && arr[i][0]<arr[i+1][0]) temp[i][0] = 0;
        
        if(arr[i][m-1]<arr[i-1][m-1] && arr[i][m-1]<arr[i-1][m-2] && arr[i][m-1]<arr[i][m-2] && arr[i][m-1]<arr[i+1][m-2] && arr[i][m-1]<arr[i+1][m-1]) temp[i][m-1] = 0;
    }
    for(int i = 1; i < m - 2; i++)
    {
        if(arr[0][i] < arr[0][i-1] && arr[0][i] < arr[1][i-1] && arr[0][i] < arr[1][i] && arr[0][i] < arr[1][i+1] && arr[0][i] < arr[0][i+1]) temp[0][i] = 0;

        if(arr[n-1][i] < arr[n-1][i-1] && arr[n-1][i] < arr[n-2][i-1] && arr[n-1][i] < arr[n-2][i] && arr[n-1][i] < arr[n-2][i+1] && arr[n-1][i] < arr[n-1][i+1]) temp[n-1][i] = 0;
    }

    for(int i = 1; i < n-1; i++)
    {
        for(int j = 1; j < m-1; j++)
        {
            if(arr[i][j] < arr[i][j-1] && arr[i][j] < arr[i-1][j-1] && arr[i][j] < arr[i-1][j] && arr[i][j] < arr[i-1][j+1] && arr[i][j] < arr[i][j+1] && arr[i][j] < arr[i+1][j+1] && arr[i][j] < arr[i+1][j] && arr[i][j] < arr[i+1][j-1]) temp[i][j] = 0;
        }
    }

    arr = temp;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    int **arr;
    arr = new int*[n];
    for(int i = 0; i < n; i++) arr[i] = new int [m];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
    cout << endl;
    ReplaceLocalMinimums(arr, n, m);
}