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
void initRandomArray(int* beg, int* end, const int m, const int M) {
	int d = (M - m + 1);
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + m;
}

//инициализация массива 
void initArray(int* beg, int* end, const int m = 0) {
	for (int* p = beg; p < end; ++p)
		*p = m;
}


//вывод массива 
void printArray(int* beg, int* end) {
	for (int* p = beg; p < end; ++p)
		cout << setw(3) << *p << ";";
	cout << '\n';
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

//глупая сортировка
void stupidSort(int* beg, int* end)
{
	for (int* p = beg; p + 1 < end; ++p) if (*p > *(p+1))
	{
		swap(*p, *(p+1));
		if (p) p -= 2;
	}
}

//количество повторяющихся элементов
void countRepeatingElements(int* beg, int* end)
{
	int cnt = 0;
	for (int* p = beg; p < end; ++p) {
		for (int* q = p+1; q < end; ++q) {
			if (*q == *p) {
				cnt+=1;
				break;
			}
		}
	}
	cout << '\n' << cnt <<'\n';
}


//количество одинаковых подряд
void countRepeatingInARow(int* beg, int* end) {
	int cnt = 0;
	for (int* p = beg; p < end; ++p) {
		if (*(p - 1) == *p) {
			cnt++;
			for (int* q = p; q < end; ++q) {
				if (*q == *p) {
					cnt+=1;
					continue;
				}
				else break;
			}
		}
	}
	cout << '\n' << cnt << '\n';
}


int main() {
	srand(time(NULL));
    int n=0;
	cin >> n;
	int* dest = nullptr;
	return 0;
}	