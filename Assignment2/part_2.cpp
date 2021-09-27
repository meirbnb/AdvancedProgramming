#include <bits/stdc++.h>

using namespace std;

int sum_ij, sum_ji;

int main(){
	int Array2D[3][3] = {{1, 2, 3},
 			     {4, 5, 6},
			     {7, 8, 9}};
	auto start1 = chrono::system_clock::now();
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			sum_ij += Array2D[i][j] * Array2D[i][j] * Array2D[i][j];
	auto end1 = chrono::system_clock::now();
	cout << "Sum = " << sum_ij << ", Execution time = " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << " ms\n";
	auto start2 = chrono::system_clock::now();
	for (int j=0; j<3; j++)
		for (int i=0; i<3; i++)
			sum_ji += Array2D[i][j] * Array2D[i][j] * Array2D[i][j];
	auto end2 = chrono::system_clock::now();
	cout << "Sum = " << sum_ij << ", Execution time = " << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " ms\n";
	return 0;
}

