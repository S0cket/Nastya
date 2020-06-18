#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main(void) {
	srand(time(NULL));
	int n, m;
	cin >> n >> m;

	cout << "old:\n";
	int** matr = new int*[n];
	for (int i = 0; i < n; ++ i) {
		matr[i] = new int[m];
		for (int j = 0; j < m; ++ j) {
			matr[i][j] = rand() % 100;
			cout << setw(4) << matr[i][j] << " ";
		}
		cout << endl;
	}

	int* p = matr[0];
	for (int i = 1; i < n; ++ i)
		matr[i - 1] = matr[i];
	matr[n - 1] = p;

	cout << "\n\nnew:\n";
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j)
			cout << setw(4) << matr[i][j] << " ";
		cout << endl;
	}

//------------------------------------------------------

	if (n < 3 || m < 2)
		cout << "\nNo answer\n";
	else {
		int row = 2, col = 1, mx = -1000000, mn = 1000000;
		for (int i = 0; i < m; ++ i) {
			if (matr[row][i] > mx)
				mx = matr[row][i];
		}
		for (int i = 0; i < n; ++ i) {
			if (matr[i][col] < mn)
				mn = matr[i][col];
		}
		cout << "\nAnswer = " << (mx - mn) << endl;
	}


	for (int i = 0; i < n; ++ i)
		delete [] matr[i];
	delete [] matr;
	return 0;
}