#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a[100], n = 0, x;
	ifstream input("a.txt");
	while (input >> x) {
		a[n] = x;
		n++;
	}
	ofstream output("a1.txt");
	output << a[0] << " ";
	for (int i = 1; i < n - 1; i++) {
		a[i] = (a[i - 1] + a[i + 1]) / 2;
		output << a[i] << " ";
	}
	output << a[n - 1];
}