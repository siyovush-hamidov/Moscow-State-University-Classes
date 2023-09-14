#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char const *argv[])
{
    const int ROWS = 3;
    const int COLS = 4;
    
    double array[ROWS][COLS],  answer = 1;
    
    for(int i = 0; i < ROWS; i++){
    	for(int j = 0; j < COLS; j++){
    			array[i][j] = rand();
			}
		}
	for(int i = 0; i < ROWS; i++){
    	for(int j = 0; j < COLS; j++){
    		cout << array[i][j] << "\t";
    	}
    	cout << endl;
    }
	
	int min = array[0][0];
	
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(min > array[i][j]){
				min = array[i][j];
			}
		}
	}
	for(int i = 0 ; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(array[i][j] == min){
				answer = i+1;
			}
		}
	}
			cout << endl << answer;	
		}
