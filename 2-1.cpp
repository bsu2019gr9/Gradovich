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
			cin >> p[i][j];
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
			cout << p[i][j] << ";";
		cout << '\n';
	}
}

void freeArr(int*& p) { delete[] p;  p = nullptr; };

int removeZeroRows(int** p, int N, int M)
{
	int f = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			if (p[i][j] == 0) {
				f++;
			}
		}

		if (f == M && i != N - 1) {
			--N;
			int* tmp = p[i];
			for (int j = i; j < N; j++)
				p[j] = p[j + 1];
			p[N] = nullptr; 
			delete[] tmp;
			tmp = nullptr; 
			i--;
		}

		else if (f == M && i == N - 1) {
			--N;
			int* tmp = p[i];
			p[i] = nullptr;
			delete[] tmp;
			tmp = nullptr;
			i--;
		}
		f = 0;
	}
	return N;
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
	int newN = removeZeroRows(dest, N, M);
	cout << newN;
	printArray(dest, newN, M);
	freeMemory(dest, newN);
}
