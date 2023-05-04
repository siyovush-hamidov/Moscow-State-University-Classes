#include <iostream>

using namespace std;

template <class T>

void Inputer(T *a, int n)
{
    for(int i = 0; i < n; i++) cin >> a[i];

    bool checker = false; int quantity = 0, indexes[n / 2], iter = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] == a[i + 1])
        {
            if(checker == true) continue;

            quantity += 1;
            indexes[iter] = i;
            iter ++;

            checker = true;
        }
        else checker = false;
    }

    int num = n + quantity;

    for(int i = n; i <= num; i++) a[i] = 0;

    for(int i = 0; i < quantity; i++)
    {
        for(int j = num; j > indexes[i] + i; j--)
        {
            swap(a[j],a[j-1]);
        }
    }

    for(int i = 0; i < num; i++) cout << a[i] << ' ';

}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    Inputer(arr, n);
}