#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a[100], n = 0, x, k = 3;
	ifstream input("a.txt");
	while (input >> x) {
		a[n] = x;
		n++;
	}
	ofstream output("a1.txt");
	for (int j = n - k; j < n; j++) {
		output << a[j] << " ";
	}
	for (int i = 0; i < n - k; i++) {
		output << a[i] << " ";
	}
}