#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a[100], n = 0, x = 5, y, q = 0 , k = 0;
	ifstream input("a.txt");
	while (input >> y) {
		a[n] = y;
		n++;
	}
	ofstream output("a1.txt");

	a[n] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			q++;
		}
		else q -= q;
		cout << q << " ";
	}
	cout << endl;
	if (q != 0) {
		k+=q;
	}
	else k -= k;
	cout << k << " ";
}
