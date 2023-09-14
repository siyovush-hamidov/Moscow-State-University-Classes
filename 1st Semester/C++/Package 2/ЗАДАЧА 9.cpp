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
	for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				output << a[i] << " ";
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			output << a[i] << " ";
		}
	}

}