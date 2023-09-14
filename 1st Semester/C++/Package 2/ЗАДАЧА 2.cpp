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
	for (int i = n - 1; i >= 0; i--) {	
		output << a[i] << " ";
	}
}