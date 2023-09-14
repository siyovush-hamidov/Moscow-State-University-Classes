#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	int a[100], n = 0, x;
	ifstream input("a.txt");
	while (input >> x) {
		a[n] = x;
		n++;
	}
}