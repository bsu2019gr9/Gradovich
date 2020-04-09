//Отсортировать все слова алфавитном порядке того предложения, в котором наибольшее количество слов, начинающихся на заданную букву.
#include <iostream>
#include <fstream>
using namespace std;
const int TMP_SIZE = 10000;
const int BUFF_SIZE = 10000;
const char* INPUT = "D:/inputs.txt";
const char* OUTPUT = "D:/result.txt";

void getMemory(char*& str, const int size)
{
	str = new (nothrow) char[size];
	if (!str)
	{
		cout << "Error!\n";
		exit(404);
	}
}

void getLetter(char& letter)
{
	cout << "Input the letter: ";
	cin >> letter;
}

void getPointer(char**& str, const int size)
{
	str = new (nothrow) char* [size];
	if (!str) {
		cout << "Error!\n";
		exit(404);
	}
}

void checkFileInput(ifstream& inp)
{
	if (!inp) {
		cout << "Error! Input file not found\n";
		exit(1);
	}
};

void checkFileOutput(ofstream& out)
{
	if (!out)
	{
		cout << "Error! Output file not found\n";
		exit(1);
	}
}

void putInArray(char*& orig, char** dest, int& pos)
{
	char* nexttok = NULL;
	char* word = strtok_s(orig, " ,.-()\t;/|\\\"'", &nexttok);
	while (word != NULL)
	{
		int wordSize = strlen(word);
		getMemory(*(dest + pos), wordSize + 1);
		strcpy_s(*(dest + pos), wordSize + 1, word);
		pos++;
		word = strtok_s(NULL, " ,.-()\t;/|\\\"'", &nexttok);
	}
}

void printArr(char**& str, const int size, ofstream& out) {
	for (int i = 0; i < size; i++) {
		out << *(str + i) << ' ';
	}
	out << endl;
}

void copyArr(char**& dest, char**& orig, const int size)
{
	for (int i = 0; i < size; i++)
	{
		getMemory(*(dest + i), strlen(orig[i]) + 1);
		strcpy_s(*(dest + i), (strlen(orig[i]) + 1), *(orig + i));
	}
}

void sortString(char** str, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1, k; j < size; j++)
		{
			k = 0;
			if (str[i] != str[j])
			{
				while (str[i][k] == str[j][k]) k++;
				if (toupper(str[i][k]) > toupper(str[j][k])) swap(str[i], str[j]);
			}
		}
	}
}

void countEquals(int& count, const int size, char**& str, char letter) {
	for (int i = 0; i < size; i++)
		if (toupper(**(str + i)) == toupper(letter)) 
			count++;
}

void delPointer(char**& str) {
	delete[] str;
	str = nullptr;
}

void delMemory(char*& str)
{
	delete[] str;
	str = nullptr;
}

void task(int& maxWords, int& maxPos, char**& cmp, char**& tmp, char*& buff, ifstream& input, ofstream& output, char letter)
{
	while (1)
	{
		
		int pos = 0;
		int count = 0;
		input.getline(buff, BUFF_SIZE, '.');
		putInArray(buff, tmp, pos);
		countEquals(count, pos, tmp, letter);
		if (count > maxWords)
		{
			for (int i = 0; i < maxPos; i++) {
				delMemory(*(cmp + i)); 
			}
			maxWords = count;
			maxPos = pos;
			copyArr(cmp, tmp, maxPos);
		}
		printArr(tmp, pos, output);
		for (int k = 0; k < pos; k++) { 
			delMemory(*(tmp + k)); }
		if (input.eof()) break;
		output << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char letter;
	char* buff;
	char** tmp;
	char** cmp;
	int maxPos = 0;
	int maxWords = 0;
	ifstream input;
	ofstream output;
	input.open(INPUT);
	output.open(OUTPUT);
	getMemory(buff, BUFF_SIZE);
	getPointer(tmp, TMP_SIZE);
	getPointer(cmp, TMP_SIZE);
	getLetter(letter);
	checkFileInput(input);
	checkFileOutput(output);
	task(maxWords, maxPos, cmp, tmp, buff, input, output, letter);
	sortString(cmp, maxPos);
	printArr(cmp, maxPos, output);
	delPointer(tmp);
	delPointer(cmp);
	delMemory(buff);
    input.close();
	output.close();
	cout << "done!";
	return 0;
}