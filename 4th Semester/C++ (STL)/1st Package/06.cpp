#include <iostream>

using namespace std;

template <class T>

void SimpleSort(T *a, int n)
{
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int min = a[0];

    for(int i = 0; i < n; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
        cout << a[i] << ' ';
    }
}

int main()
{
    int n;
    cin >> n;

    double arr[n];

    SimpleSort(arr, n);
}