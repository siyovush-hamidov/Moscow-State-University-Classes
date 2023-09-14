#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a[100], n = 0, x, k = 37;
	ifstream input("a.txt");
	while (input >> x) {
		a[n] = x;
		n++;
	}
	ofstream output("a1.txt");
	int mid = 0 + (n-1) / 2;
	if(x == a[mid])
}
