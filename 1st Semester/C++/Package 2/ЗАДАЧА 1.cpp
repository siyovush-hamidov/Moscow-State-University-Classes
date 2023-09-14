#include <iostream>
#include <fstream>
using namespace std;

bool symmetric(double a[], int s) {
    int length = s / 2;
    for (int i = 0; i < s; i++) {
        if (a[i] != a[s - 1 - i]) {
            return false;
        }
    }
    return true;
}

//main function:
int main()
{
    int n = 0;
    double arr[50], x;
    ifstream inp("a.txt");
    while (inp >> x) {
        arr[n] = x;
        n++;
    }
    cout << symmetric(arr, n);
    return 0;
}
