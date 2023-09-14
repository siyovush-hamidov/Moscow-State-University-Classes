#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a[100], b[100], c[100], n = 0, m = 0, x, y;
	ifstream inputa("a.txt"), inputb("b.txt");
	while (inputa >> x) {
		a[n] = x;
		n++;
	}
	while (inputb >> y) {
		b[m] = y;
		m++;
	}

	ofstream output("c.txt");
	int k = n + m;
	for (int j = 0; j < n + m; j++) {
		for (int i = 0; i < m; i++) {
			c[i] = a[i];
		}
		for (int i = 0; i < m; i++) {
			c[n + i] = b[i];
		}
		cout << c[j] << " ";

	}
	cout << endl;

	for (int j = 0; j < k - 1; j++) {
		for (int p = 0; p < k - 1; p++) {
			if (c[p] > c[p + 1]) {
				swap(c[p], c[p + 1]);
				cout << c[p] << " ";
		}
		}
		

	}
}