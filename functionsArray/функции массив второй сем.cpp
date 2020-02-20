#include <iostream>
#include <time.h>
#include "functionsArrayGradovich.h"
using namespace std;


//ввод массива с клавы
void inputArray(int* A, const int N ) {
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
}

//вывод массива 
void printArray(int* A, const int N) {
	for (int i = 0; i < N; ++i)
	{
		cout << A[i];
	}
}

//инициализация массива 
void initArray(int* A, const int size, int beg, int end) {

	for (int i = 0; i < size; ++i)
	{
		A[i] = rand() % (end - beg + 1) + beg;
	}
}

//максимум
int findMax(int* A, const int N) {
	int max = A[0];
	for (int i = 0; i < N; i++)
	{
		(A[i] > max) ? max = A[i] : 1;
	}
	return max;
}

//минимум
int findMin(int* A, const int N) {
	int min = A[0];
	for (int i = 0; i < N; i++)
	{
		(A[i] < min) ? min = A[i] : 1;
	}
	return min;
}

//сумма
int sumArray(int* A, const int N) {
	int sum = A[0];
	for (int i = 0; i < N; i++)
	{
		sum += A[i];
	}
	return sum;
}

//перевернутый
void reverse(int* A, int* B, const int N) {
	for (int i = 0; i < N; i++)B[i] = A[N - 1 - i];
}

//половины массива
void halfArray(int* A, int& N) {
	int s = 10, k = 11;
	int B[11] = { 0 }; int C[10] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		if (i < k)B[i] = A[i];
		else C[i - k] = A[i];
	}
	printArray(B, k);
	cout << '\n';
	printArray(C,s);
}

//разделение массива
void divArray(int* A, const int N) {
	int pl = 0, m = 0;
	for (size_t i = 0; i < N; i++)
	{
		(A[i] >= 0) ? ++pl : ++m;
	};
	int* B = new int[pl];
	int* C = new int[m];
	for (int i = 0, k = 0, f = 0; i < N; i++)
	{
		if (A[i] >= 0) { B[k] = A[i]; ++k; }
		else {
			C[f] = A[i]; ++f;
		}
	};
	printArray(B, pl); printArray(C, m);
}

void shiftArrayRight(int* A, const int size) {
	int tmp;
	for (int i = size - 1; i > 0; --i) {
		tmp = A[(i + 1) % size];
		A[(i + 1) % size] = A[i];
		A[i] = tmp;
	}
}

void shiftArrayLeft(int* A, const int size) {
	int tmp;
	for (int i = 0; i < size - 1; ++i) {
		tmp = A[i];
		A[i] = A[(i + 1) % size];
		A[(i + 1) % size] = tmp;
	}
}
//пузырьковая сортировка
void bubbleSort(int* A, const int  size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (A[j] > A[j + 1]) {
				int b = A[j];
				A[j] = A[j + 1];
				A[j + 1] = b;
			}
		}
	}
}

//шейкерная сортировка
void shakerSort(int* A, const int size) {
	int l = 0, r = 0;
	for (int l = 0, r = size - 1; l < r;) {
		for (int i = l; i < r; ++i) {
			if (A[i + 1] < A[i]) {
				swap(A[i], A[i + 1]);
			}
		}
		--r;
		for (int i = r; i > l; --i) {
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
			}
		}
		++l;
	}
}

//глупая сортировка
void stupidSort(int* A, const int size)
{
	for (int i = 0; i + 1 < size; ++i) if (A[i] > A[i + 1])
	{
		swap(A[i], A[i + 1]);
		if (i != 0) i -= 2;
	}
}

//четно-нечетная сортировка
void oddEvenSort(int* A, const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = (i % 2) ? 0 : 1; j + 1 < size; j += 2) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
			}
		}
	}
}

//расстояние
int getNextGap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap < 1)
		return 1;
	return gap;
}

//сортировка расческой
void combSort(int* A, const int size) {
	int gap = size;
	bool swapped = true;
	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;
		for (int i = 0; i < size - gap; i++)
		{
			if (A[i] > A[i + gap])
			{
				swap(A[i], A[i + gap]);
				swapped = true;
			}
		}
	}
}

//сортировка Шелла
void ShellSort(int* A, const int size)
{
	int tmp;
	for (int step = size / 2; step > 0; step /= 2) {
		for (int i = step; i < size; i++) {
			for (int j = i - step; j >= 0 && A[j] > A[j + step]; j -= step)
			{
				tmp = A[j];
				A[j] = A[j + step];
				A[j + step] = tmp;
			}
		}
	}
}

//сортировка выбором
void selectionSort(int* A, const int size) {
	int min;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}

		if (min != i) {
			swap(A[i], A[min]);
			min = i;
		}
	}
}

void menuArr() {
	int beg, end, size;
	srand(time(NULL));
	cout << "Enter beg\n";
	cin >> beg;
	cout << "Enter end\n";
	cin >> end;
	size = end - beg;

}

int* giveMemory(int n){
	int* A = new int[n];
	A = {0};
	return A;
}

void freeMemory(int *A){
	if (!A)
	{
		cout << "array is free\n";
		return;
	}
	delete[] A;
}

int main() {
    int const N = 6;
	menuArr();
	return 0;
}