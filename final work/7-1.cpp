/*Определить объект, содержащий информацию о студенте факультета с полями ФИО, курс, группа, оценки в текущую сессию, размер стипендии. 
Создать массив объектов. Разработать функции:
a) Создания/удаления/редактирования студента;
b) Определения студентов, сдавших сессию на "отлично", на "хорошо" и "отлично", получивших удовлетворительные оценки,
получивших неудовлетворительные оценки;
c) Определения количества студентов, получивших неудовлетворительные оценки для каждой группы и каждого курса;
d) Для каждого студента назначить размер стипендии, выбрав самостоятельно какой-нибудь критерий;
e) Сортировки массива в порядке убывания среднего балла;
f) Сортировки массива по курсам, внутри курса - по полученной стипендии;
g) Для каждого курса вывести список отличников в алфавитном порядке и долю (процент) их от общего числа отличников.*/

#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "functions.h"
#include <iostream>
#include <fstream>
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	Student* bsu = new (nothrow) Student[M];
	int marks[10] = {8,8,9,7,7,7};
	int marks1[10] = {9,9,10,10,9};
	int marks2[10] = { 9,9,10,7,6,4};
	int marks3[10] = { 9,9,10,8,9,10 };
	bsu[0].setStudent("Антонович", "Daria", "Alexeevna", 1, 9, marks1, 1000);
	bsu[1].setStudent("Аыщващыоащыоач", "Daria", "Alexeevna", 5, 11, marks3, 10);
	bsu[2].setStudent("Фвщоащвоащч", "Daria", "Alexeevna", 5, 10, marks3, 1000);
	bsu[3].setStudent("Sarnatskaya", "Darya", "Lexdrovna", 2, 2, marks1, 1);
	bsu[4].setStudent("Filinkova", "Daria", "Rexeevna", 1, 5, marks1, 10);
	bsu[5].setStudent("Архипов", "Daria", "Alexef", 1, 8, marks1, 10);
	bsu[6].setStudent("Анищенко", "Daria", "Alexeeyufff", 1, 15, marks, 1200);
	bsu[7].setStudent("Акулич", "Daria", "Alexea", 2, 7, marks, 1400);
	bsu[8].setStudent("Бабицкая", "Liza", "Alereeevna", 4, 9, marks2, 10500);
	bsu[9].setStudent("Бабицкий", "Misha", "Alexeeythvna", 4, 9, marks2, 100);
	bsu[10].setStudent("Белоусов", "Nikita", "Pdfgdgna", 4, 9, marks3, 1000);
	bsu[11].setStudent("Барташевич", "Oak", "Pfgdkgeevna", 3, 7, marks, 1000);
	bsu[12].setStudent("Витковский", "File", "Rodofgdovna", 1, 7, marks3, 400);
	bsu[13].setStudent("Pen", "Type", "Alexeevna", 3, 17, marks3, 50);
	bsu[14].setStudent("File", "Asofd", "Alexeevna", 2, 15, marks2, 100);
	bsu[15].setStudent("Table", "Vova", "Alexeevna", 3, 15, marks2, 1700);
	bsu[16].setStudent("Соболевский", "Daria", "Alexeevna", 2, 9, marks1, 1000);
	bsu[17].setStudent("Саевич", "Pal", "Alexeevna", 1, 8, marks1, 1600);
	bsu[18].setStudent("Dog", "Daria", "Alexeevna", 2, 4, marks1, 1000);
	bsu[19].setStudent("Surname", "Daria", "Alexeevna", 4, 5, marks, 1000);
	bsu[20].setStudent("Dfsfsf", "Polina", "Alexeevna", 3, 2, marks3, 1000);
	bsu[21].setStudent("Resydf", "Daria", "Alexeevna", 1, 1, marks1, 130);
	bsu[22].setStudent("Пимкова", "Daria", "Ddhdhoevna", 1, 1, marks3, 120);
	bsu[23].setStudent("Pdfopsfo", "Arrow", "Alexeevna", 3, 17, marks2, 10);
	bsu[24].setStudent("Bode", "Daria", "Alexeevna", 3, 9, marks2, 10);
	bsu[25].setStudent("Stick", "Daria", "Alexeevna", 2, 15, marks3, 1000);
	bsu[26].setStudent("Potato", "Daria", "Alexeevna", 2, 15, marks, 1000);
	bsu[27].setStudent("Cat", "Daria", "Alexeevna", 1, 9, marks2, 1000);
	bsu[28].setStudent("Градович", "Daria", "Alexeevna", 1, 17, marks1, 1000);
	bsu[29].setStudent("Антонович", "Daria", "Alexeevna", 1, 9, marks1, 1000);
	bsu[30].setStudent("Аыщващыоащыоач", "Daria", "Alexeevna", 5, 11, marks3, 10);
	bsu[31].setStudent("Фвщоащвоащч", "Daria", "Alexeevna", 5, 10, marks3, 1000);
	bsu[32].setStudent("Sarnatskaya", "Darya", "Lexdrovna", 2, 2, marks1, 1);
	bsu[33].setStudent("Filinkova", "Daria", "Rexeevna", 1, 5, marks1, 10);
	bsu[34].setStudent("Архипов", "Daria", "Alexef", 1, 8, marks1, 10);
	bsu[35].setStudent("Анищенко", "Daria", "Alexeeyufff", 1, 15, marks, 1200);
	bsu[36].setStudent("Акулич", "Daria", "Alexea", 2, 7, marks, 1400);
	bsu[37].setStudent("Бабицкая", "Liza", "Alereeevna", 4, 9, marks2, 10500);
	bsu[38].setStudent("Бабицкий", "Misha", "Alexeeythvna", 4, 9, marks2, 100);
	bsu[39].setStudent("Белоусов", "Nikita", "Pdfgdgna", 4, 9, marks3, 1000);
	bsu[40].setStudent("Барташевич", "Oak", "Pfgdkgeevna", 3, 7, marks, 1000);
	bsu[41].setStudent("Витковский", "File", "Rodofgdovna", 1, 7, marks3, 400);
	bsu[42].setStudent("Pen", "Type", "Alexeevna", 3, 17, marks3, 50);
	bsu[43].setStudent("File", "Asofd", "Alexeevna", 2, 15, marks2, 100);
	bsu[44].setStudent("Table", "Vova", "Alexeevna", 3, 15, marks2, 1700);
	bsu[45].setStudent("Соболевский", "Daria", "Alexeevna", 2, 9, marks1, 1000);
	bsu[46].setStudent("Саевич", "Pal", "Alexeevna", 1, 8, marks1, 1600);
	bsu[47].setStudent("Dog", "Daria", "Alexeevna", 2, 4, marks1, 1000);
	bsu[48].setStudent("Surname", "Daria", "Alexeevna", 4, 5, marks, 1000);
	bsu[49].setStudent("Dfsfsf", "Polina", "Alexeevna", 3, 2, marks3, 1000);
	bsu[50].setStudent("Resydf", "Daria", "Alexeevna", 1, 1, marks1, 130);
	bsu[51].setStudent("Пимкова", "Daria", "Ddhdhoevna", 1, 1, marks3, 120);
	bsu[52].setStudent("Pdfopsfo", "Arrow", "Alexeevna", 3, 17, marks2, 10);
	bsu[53].setStudent("Bode", "Daria", "Alexeevna", 3, 9, marks2, 10);
	bsu[54].setStudent("Stick", "Daria", "Alexeevna", 2, 15, marks3, 1000);
	bsu[55].setStudent("Potato", "Daria", "Alexeevna", 2, 15, marks, 1000);
	bsu[56].setStudent("Cat", "Daria", "Alexeevna", 1, 9, marks2, 1000);
	bsu[57].setStudent("Градович", "Daria", "Alexeevna", 1, 17, marks1, 1000);
	bsu[58].setStudent("Фвщоащвоащч", "Daria", "Alexeevna", 5, 10, marks3, 1000);
	bsu[59].setStudent("Sarnatskaya", "Darya", "Lexdrovna", 2, 2, marks1, 1);
	bsu[60].setStudent("Filinkova", "Daria", "Rexeevna", 1, 5, marks1, 10);
	bsu[61].setStudent("Витковский", "File", "Rodofgdovna", 1, 7, marks3, 400);
	bsu[62].setStudent("Pen", "Type", "Alexeevna", 3, 17, marks3, 50);
	bsu[63].setStudent("File", "Asofd", "Alexeevna", 2, 15, marks2, 100);
	bsu[64].setStudent("Архипов", "Daria", "Alexef", 1, 8, marks1, 10);
	bsu[65].setStudent("Анищенко", "Daria", "Alexeeyufff", 1, 15, marks, 1200);
	bsu[66].setStudent("Акулич", "Daria", "Alexea", 2, 7, marks, 1400);
	bsu[67].setStudent("Бабицкая", "Liza", "Alereeevna", 4, 9, marks2, 10500);
	bsu[68].setStudent("Бабицкий", "Misha", "Alexeeythvna", 4, 9, marks2, 100);
	bsu[69].setStudent("Белоусов", "Nikita", "Pdfgdgna", 4, 9, marks3, 1000);
	bsu[70].setStudent("Барташевич", "Oak", "Pfgdkgeevna", 3, 7, marks, 1000);
	bsu[71].setStudent("Витковский", "File", "Rodofgdovna", 1, 7, marks3, 400);
	bsu[72].setStudent("Pen", "Type", "Alexeevna", 3, 17, marks3, 50);
	bsu[73].setStudent("File", "Asofd", "Alexeevna", 2, 15, marks2, 100);
	bsu[74].setStudent("Table", "Vova", "Alexeevna", 3, 15, marks2, 1700);
	bsu[75].setStudent("Соболевский", "Daria", "Alexeevna", 2, 9, marks1, 1000);
	bsu[76].setStudent("Саевич", "Pal", "Alexeevna", 1, 8, marks1, 1600);
	bsu[77].setStudent("Dog", "Daria", "Alexeevna", 2, 4, marks1, 1000);
	bsu[78].setStudent("Surname", "Daria", "Alexeevna", 4, 5, marks, 1000);
	bsu[79].setStudent("Dfsfsf", "Polina", "Alexeevna", 3, 2, marks3, 1000);
	bsu[80].setStudent("Resydf", "Daria", "Alexeevna", 1, 1, marks1, 130);
	bsu[81].setStudent("Пимкова", "Daria", "Ddhdhoevna", 1, 1, marks3, 120);
	bsu[82].setStudent("Pdfopsfo", "Arrow", "Alexeevna", 3, 17, marks2, 10);
	bsu[83].setStudent("Bode", "Daria", "Alexeevna", 3, 9, marks2, 10);
	bsu[84].setStudent("Stick", "Daria", "Alexeevna", 2, 15, marks3, 1000);
	bsu[85].setStudent("Potato", "Daria", "Alexeevna", 2, 15, marks, 1000);
	bsu[86].setStudent("Cat", "Daria", "Alexeevna", 1, 9, marks2, 1000);
	bsu[87].setStudent("Градович", "Daria", "Alexeevna", 1, 17, marks1, 1000);
	bsu[88].setStudent("Бабицкий", "Misha", "Alexeeythvna", 4, 9, marks2, 100);
	bsu[89].setStudent("Белоусов", "Nikita", "Pdfgdgna", 4, 9, marks3, 1000);
	bsu[90].setStudent("Барташевич", "Oak", "Pfgdkgeevna", 3, 7, marks, 1000);
	bsu[91].setStudent("Витковский", "File", "Rodofgdovna", 1, 7, marks3, 400);
	bsu[92].setStudent("Pen", "Type", "Alexeevna", 3, 17, marks3, 50);
	bsu[93].setStudent("File", "Asofd", "Alexeevna", 2, 15, marks2, 100);
	bsu[94].setStudent("Table", "Vova", "Alexeevna", 3, 15, marks2, 1700);
	bsu[95].setStudent("Соболевский", "Daria", "Alexeevna", 2, 9, marks1, 1000);
	bsu[96].setStudent("Саевич", "Pal", "Alexeevna", 1, 8, marks1, 1600);
	bsu[97].setStudent("Dog", "Daria", "Alexeevna", 2, 4, marks1, 1000);
	bsu[98].setStudent("Surname", "Daria", "Alexeevna", 4, 5, marks, 1000);

	getListOfStudents(bsu);
	bsu[3].getMarks();

	Student* bspu = new (nothrow) Student[M];
	writeToFile("d:\\running.rez", bsu);
	readFromFile("d:\\running.rez", bspu);
	cout << bspu[20];
	
	menu(bsu);

	
	delete[] bsu;
	bsu = nullptr;
	delete[] bspu;
	bspu = nullptr;
}
