#include <iostream>
#include <time.h>
#include <iomanip>
#include "functionsArrayGradovich.h"
using namespace std;


void mkArrOfInt(int n, int*& p) {
	p = new (nothrow) int[n];
	if (!p) exit(404);
}

void freeMemory(int*& p) { delete[] p;  p = nullptr; };


//ввод массива с клавы
void inputArray(int* beg, int* end ) {
	int tmp;
	for (int* p = beg; p < end; ++p)
	{
		cin >> tmp;
		*p = tmp;
	}
}

//инициализация массива псевдослучайным числами
void initRandomArray(int* beg, int* end, const int m = -10, const int M = 10) {
	int d = (M - m + 1);
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + m;
}

//вывод массива 
void printArray(int* beg, int* end) {
	for (int* p = beg; p < end; ++p)
		cout << setw(3) << *p << ";";
	cout << '\n';
}

//инициализация массива 
void initArray(int* beg, int* end, const int m = 0) {
	for (int* p = beg; p < end; ++p)
		*p = m;
}

//максимум
int findMax(int* beg, int* end) {
	int max = *beg;
	for (int* p = beg; p < end; ++p)
	{
		(*p > max) ? max = *p : 1;
	}
	return max;
}

//минимум
int findMin(int* beg, int* end) {
	int min = *beg;
	for (int* p = beg; p < end; ++p)
	{
		(*p < min) ? min = *p : 1;
	}
	return min;
}

//сумма
int sumArray(int* beg, int* end) {
	int sum = *beg;
	for (int* p = beg; p < end; ++p)
	{
		sum += *p;
	}
	return sum;
}

//перевернутый
void reverse(int* beg, int* end) {

	for (int* p = beg, *q = end - 1; p < q; ++p, --q) {swap(*p, *q);}
}

//сдвиг вправо на одну единицу
void shiftArrayRight(int* beg, int* end) {
	for (int* p = end - 1; p > beg; --p) {swap(*p, *(p - 1));}
}

//сдвиг влево на одну единицу
void shiftArrayLeft(int* beg, int* end) {
	for (int* p = beg; p < end - 1; ++p) {swap(*p, *(p + 1));}
}

void divArray(int* beg, int* end, int pos[], int neg[])
{

	for (int i = 0, j = 0, *p = beg; p < end; ++p) {
		if (*p > 0) { 
			pos[j] = *p;
			j++; 
		}
		if (*p < 0) { 
			neg[i] = *p;
			i++;
		}
	}

}

//пузырьковая сортировка
void bubbleSort(int* beg, int* end) {
	for (int* p = beg; p < end; ++p) {
		for (int* q = beg; q < end - 1; q++) {
			if (*q > * (q + 1)) {
				int tmp = *q;
					*q = *(q + 1);
					*(q + 1) = tmp;
			}
		}
	}
}



/*---
//шейкерная сортировка
void shakerSort(int* beg, int* end) {
	for (int l = *beg, r = *end - 1; l < r;) {
		for (int* p = beg; p < end -1; ++p) {
			if (*(p+ 1) < *p) {
				swap(*p, *(p+1));
			}
		}
		--end;
		for (int* p = end; p > beg; --p) {
			if (*(p-1) > *p) {
				swap(*(p - 1), *p);
			}
		}
		++beg;
	}
} --*/

//глупая сортировка
void stupidSort(int* beg, int* end)
{
	for (int* p = beg; p + 1 < end; ++p) if (*p > *(p+1))
	{
		swap(*p, *(p+1));
		if (p) p -= 2;
	}
}



/*-  
//сортировка Шелла
void ShellSort(int* beg, int* end)
{
	for (int step = *end / 2; step > *beg; step /= 2) {
		for (int i = step; i < *end; i++) {
			for (int j = i - step; j >= 0 && j > (j + step); j -= step)
			{
				int tmp = j;
				j += step;
				j = tmp - step;
			}
		}
	}
} -*/



/*
//сортировка выбором
void selectionSort(int* beg, int* end) {
	for (int*p = beg; p < end - 1; p++) {
	int* min = p;
		for (int* q = p + 1; q < end; q++) {
			if (*q < *min) {
				min = q;
			}
		}

		if (min != p) {
			swap(p, min);
			min = p;
		}
	}
}  */


int main() {
    int n = 10;
	int* dest = nullptr;
	mkArrOfInt(n, dest);
	inputArray(dest, dest+n);
	printArray(dest, dest + n);

	return 0;
}