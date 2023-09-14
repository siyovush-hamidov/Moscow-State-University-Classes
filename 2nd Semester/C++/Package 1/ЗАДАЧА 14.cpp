#include <iostream>
#include <ctime>

using namespace std;
int main(int argc, char const *argv[])
{
	const int ROWS = 3;
	const int COLS = 4;
	double a[ROWS][COLS], b[ROWS];;

	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			a[i][j] = rand() % 100;
		}
	}
	for(int i = 0; i < ROWS; i++){
    	for(int j = 0; j < COLS; j++){
    		cout << a[i][j] << "\t";
    	}
    	cout << endl;
}
	
	for(int i = 0; i < ROWS; i++){	
		for(int k = 0; k < COLS; k++){
				b[i] += a[i][k];
			}
	} 
	cout << endl;
	for(int i = 0; i < ROWS; i++){
		cout << b[i] << " ";
	}
	int q = 0;
	int minrow = b[0];
	b[3] = 142;
	for(int i = 0; i < 4; i++){
		if(minrow > b[i]) {		
			cout <<  i + 1 << " ";
			} 
		}
		cout << endl;
		for(int i = 0; i < 4; i++){
		if(minrow >= b[i]) {		
			minrow = i + 1;
			} 
		}
		cout << minrow;
}

