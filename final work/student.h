#pragma once
#include <iostream>
#include <fstream>
using namespace std;
const int M = 100;

class Student {
private:
	char* surname;
	char* name;
	char* patronymic;
	int course;
	int group;
	int marks[10] = { 0 };
	float averageMark;
	float scholarship;
	int status;
	int satisfaction;
public:

	Student();//конструктор без параметров
	//конструктор с параметрами
	Student(const char[30], const char[30], const char[30], const int, const int, const int[10], const float, const float, const int, const int);
	//~Student();//декструктор

	Student(const Student&);//конструктор копирования
	const Student& operator=(const Student&);//оператор присваивания

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);

	void setSurname(const char*);//задать фамилию
	void setName(const char*);//задать имя
	void setPatronymic(const char*);//задать отчество
	void setCourse(int);//задать курс
	void setGroup(int);//задать группу
	void setMarks(int*);//задать оценки
	void setScholarship(float);//задать стипендию
	void setStudent(const char*, const char*, const char*, int, int, int*, float);//задать студента
	void setStudent();//задать студента без параметров

	void editSurname(const char*);//редактировать фамилию
	void editName(const char*);//редактировать имя
	void editPatronymic(const char*);//редактировать отчество
	void editCourse(int);//редактировать курс
	void editGroup(int);//редактировать группу
	void editMarks(int*);//редактировать оценки
	void editScholarship(float);//редактировать стипендию
	void editStudent(const char*, const char*, const char*, int, int, int*, float);//редактировать студента
	void editStudent();//редактировать студента без параметров

	void deleteSurname();//удалить фамилию
	void deleteName();//удалить имя
	void deletePatronymic();//удалить отчество
	void deleteCourse();//удалить курс
	void deleteGroup();//удалить группу
	void deleteMarks();//удалить оценки
	void deleteScholarship();//удалить стипендию
	void deleteStudent();//удалить студента

	void getSurname();//вывести фамилию
	void getName();//вывести имя
	void getPatronymic();//вывести отчество
	void getCourse();//вывести курс
	void getGroup();//вывести группу
	void getMarks();//вывести оценки
	void getAverageMark();//вывести среднюю оценку
	void getScholarship();//вывести стипендию
	void getStudent();//вывести информацию о студенте

	void countAverageMark(int*);//посчитать среднюю оценку

	void determineStudentStatus();//определить статус студента
	void showStudentWithGoodStatus();//показать студента с "хорошими" оценками
	void showStudentWithWellStatus();//показать студента с "отличными" оценками
	void showStudentWithSatisfactoryMarks();//показать студента с "удовлетворительными" оценками
	void showStudentWithUnsatisfactoryMarks();//показать студента с "неудовлетворительными" оценками

	int getIntGroup() const;//геттер номера группы
	int getIntCourse() const;//геттер номера курса
	int getIntSatisfaction() const;//геттер статуса удовлетворительности оценок
	int getIntStatus();//геттер статуса оценок для стипендии
	float getFloatAverageMark();//геттер средней оценки
	float getFloatScholarship() const;//геттер стипендии
	char* getCharSurname() const;//геттер фамилии
};