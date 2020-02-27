// В массиве А(N,М) часть строк состоит из нулей. удалить нулевые строки.
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


int** mkArrOfInt(int N, int M) {
	int** p = new (nothrow) int* [N];
	if (!p) exit(404);
	for (size_t i = 0; i < N; i++) {
		p[i] = new (nothrow) int[M];
		if (!p[i]) exit(404);
	}
	return p;
}

void inputArray(int** p, int N, int M) {
	cout << "\nEnter elements\n";
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			int a;
			cin >> a;
			p[i][j] = a;
		}
	}
}

void freeMemory(int**& p, int N) {
	for (size_t i = 0; i < N; i++) delete[] p[i];
	delete[] p;
	p = nullptr;
}

void printArray(int** p, int N, int M) {
	cout << '\n';
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++)
			cout << setw(3) << p[i][j] << ";";
		cout << '\n';
	}
}

void removeZeroRows(int** a, int N, int M)
{
	int cnt = 0, 
		k = -1,
		p;

	for (int i = 0; i < N; i++)
	{ p = 0;
		for (int j = 0; j < M; j++)
			if (a[i][j] != 0.0) p++;
		if (p == 0) cnt++;
	}

	int** b = mkArrOfInt(N - cnt, M);

	for (int i = 0; i < N; i++)
	{ p = 0;
		for (int j = 0; j < M; j++)
			if (a[i][j] != 0.0) p++;
		if (p != 0)
		{
			k++;
			for (int j = 0; j < M; j++)
				b[k][j] = a[i][j];
		}
	}

	freeMemory(a, N);
	a = b;
	printArray(a, N - cnt, M);
	freeMemory(b, N - cnt);
}



int main() {
	srand(time(0));
	int N;
	int M;
	cout << "Enter N,M\n";
	cin >> N;
	cin >> M;
	int** dest = mkArrOfInt(N, M);
	inputArray(dest, N, M);
	printArray(dest, N, M);
	cout << "\nArray without zero rows \n";
	removeZeroRows(dest, N, M);
}