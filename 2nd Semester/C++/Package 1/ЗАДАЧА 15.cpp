#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  int n =4;
  int m = n;
  int a[n][n], value = 1;
  

  	for(int i = 0; i < n; i++){
  	a[n-m][i] = value++;
  }
  	for(int i = n-(n-1); i < n; i++){
  	a[i][n-1] = value++;
  }
  	for(int i = n-2; i > n-(n+1); i--){
  	a[n-1][i] = value++;
  }
  	for(int i = n-2; i > n-n; i--){
  	a[i][n-n] = value++;
  }
  
  m=n-2;
  
  if(value > n * n) return 0;
		  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
  
}





//  
//  }
//  for(int i = N - (N - 1); i < N; i++){
//    a[i][N-1] = (value)++;
//  }
//  for(int i = N-2; i >= 0; i--){
//    a[N-1][i] = value++;
//  }
//  for(int i = N-2; i >= 1; i--){
//    a[i][N-N] = value++;
//  }
//  for(int j = N-(N-1); j < N-1; j++){
//    a[N-(N-1)][j] = value++;
//  }
//  for(int i = N - (N-2); i < N - 1; i++)
//  {
//    a[i][N-2] = value++;
//  }
//  for(int i = N - (N-3); i <= N - 2; i++){
////  	a[]
//  }
//  