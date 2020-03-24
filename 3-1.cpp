//В строке в каждой паре слов поменять слова местами, если длины слов совпадают, иначе заменить их звёздочками
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <cstring> 
using namespace std;
const int MAX = 255;
int num = 0; 

void freeMemory(char**& arr, int k)
{
	for (int i = 0; i < k; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}

int findWords(char* str, char** arr)
{
	char* p = str;
	char str1[] = ".,:;`-()!?/ \t";
	for (int i = 0; *p; i++)
	{
		p += strspn(p, str1);
		int length = strcspn(p, str1);
		if (length == 0) break;
		arr[i] = new(nothrow) char[length + 1];
		if (!arr)
		{  cout << "No memory";
		   exit(404); }
		strncpy(arr[i], p, length);
		arr[i][length] = '\0';
		num++;
		p += length;
	}
	return num;
}

void printModifiedString(char** word) {
	cout << "\nWords and *:\n\n";
	for (int i = 0; i < num; i += 2)
	{
		if (word[i] == word[num - 1])
		{
			cout << word[i];
			break;
		}

		if (strlen(word[i]) == strlen(word[i + 1]))
		{
			swap(word[i], word[i + 1]);
			cout << word[i] << ' ';
			cout << word[i + 1] << ' ';
		}
		else
		{
			for (int k = 0; k < strlen(word[i]); ++k) {
				cout << "*";
			}
			cout << ' ';
			for (int k = 0; k < strlen(word[i+1]); ++k) {
				cout << "*";
			}
			cout << ' ';
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	const int N(100);
	char tmp[MAX];
	char* word[N];
	cout << "Enter the string\n";
	cin.getline(tmp, MAX);
	char* str = new(nothrow) char[strlen(tmp) + 1];
	if (!str)
	{
		cout << "No memory";
		exit(404);
	}
	strcpy(str, tmp);
	findWords(str, word);
	printModifiedString(word);
	delete[] str;
	str = nullptr;
	return 0;
}
