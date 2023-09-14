#include <fstream>
#include <iostream>
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
	output << a[n - 1] << " ";
	for (int i = -1; i < n - 2; i++) {
		output << a[i + 1] << " ";
	}
}

