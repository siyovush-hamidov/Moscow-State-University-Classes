#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int a[100], b[100], n = 0, m = 0, x, y;
	bool aha = false;
	ifstream inputa("a.txt"), inputb("b.txt");
	while (inputa >> x) {
		a[n] = x;
		n++;
	}
	while (inputb >> y) {
		b[m] = y;
		m++;
	}

	ofstream output("result.txt");
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				aha = true;
			}
			else if(a[0] >= b[0] && a[n] <= b[m]) {
				aha = false;
			}
		}
	}
	
	if (aha) {
		output << "A = B";
	}
	else output << "A c B";
}