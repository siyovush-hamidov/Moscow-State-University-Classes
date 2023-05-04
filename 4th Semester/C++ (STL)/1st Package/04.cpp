#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <class T>

void FindGreat(T **arr, int n, int m)
{
    T b[n+1];
    T temp; 
    T ansmin = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ansmin += sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]));    
        }
    }

    int ansindex = 0;

    for(int i = 0; i < n; i++)
    {
        temp = 0;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                temp += sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]));              
            }  
        }
            if(ansmin > temp)
            {
                ansmin = temp;
                ansindex = i;
            } 
    }

    cout << arr[ansindex][0] <<","<<arr[ansindex][1] << "\n" << ansmin;
}

int main()
{
    int n;
    cin >> n;

    double **arr;
    arr = new double*[n];
    for(int i = 0; i < n; i++) arr[i] = new double [2];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << '\n';

    FindGreat(arr, n,2);
}