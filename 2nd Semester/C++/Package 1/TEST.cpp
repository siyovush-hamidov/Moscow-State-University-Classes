#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input("a.txt");
	ofstream output("a1.txt");

	int a[100], n = 0, x;
	while(input >> x){
		a[n] = x;
		n++;
	}
	for(int i = n-1; i >= 0; i--){
		output << a[i] << " ";
	}
}
		