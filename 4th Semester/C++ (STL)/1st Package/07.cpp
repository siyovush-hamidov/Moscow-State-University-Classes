#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class T>

void Inputer(T *a, int n)
{
    for(int i = 0; i < n; i++) cin >> a[i];

    int max = a[0], min = a[0], indexes[2];
    indexes[0] = 0; indexes[1] = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
            indexes[0] = i;
        }
        if(a[i] > max)
        {
            max = a[i];
            indexes[1] = i;
        }
    }

    for(int i = n; i < n + 2; i++) a[i] = 0;

    for(int i = 0; i < 2; i++)
    {
        for(int j = n + 1; j > indexes[i] + i; j--)
        {
            swap(a[j],a[j-1]);
        }
    }
    
    if(indexes[0] < indexes[1]) swap(a[indexes[1] + 1], a[indexes[1] + 2]);
    if(indexes[0] > indexes[1]) swap(a[indexes[1]], a[indexes[1] + 1]);
    
    for(int i = 0; i < n + 2; i++) cout << a[i] << ' ';
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    Inputer(arr, n);
}