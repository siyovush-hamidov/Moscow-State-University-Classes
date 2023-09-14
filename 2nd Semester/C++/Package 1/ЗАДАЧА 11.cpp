#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int A[100], B[100], C[100], n = 0, k = 0, m = 0, *p = A, *q = B, *z = C;
	
	{
		cout << "A: ";
	while(cin >> *p++) n++;
	cin.clear();
    cin.ignore();
    cout << "B: ";
	while(cin >> *q++) k++;
	
	p = A;   
	q = B;
	z = C;
	m = n + k;
	
	for(int i = 0; i < n; i++){
		*(C+i) = *(A+i);
	}
	for(int i = 0; i < k; i++){
			*(C+i+n) = *(B+i);
	}
}

	{
	for(int i = 0; i < m; i++){
		for(int k = 0; k < m; k++){
			if(*(z+i) < *(z+k)){
				swap(*(z+i),*(z+k));
			}
		}
	}
}
	
	{
			int r = 0;
	for(int i = 0; i < m; i++){
	bool check = true;
	for(int j = 0; j < m; j++){	
	}
			for(int j = 0; j < i; j++){
			if(*(z+i) == *(z+j)) check = false;
		}
		if(check){
			*(z + r) = *(z + i);
			r++;
		}
	}
		cout << "C = { " ;	
	for(int i = 0; i < r; i++){
		cout << *z++ << " ";
	}
	cout << " }";
	}

}
                                               