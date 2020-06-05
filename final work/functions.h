#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <iostream>
#include <fstream>
using namespace std;


void getListOfStudents(Student*);//вывести список студентов
void getListOfStudentsOfGroup(Student*, int);
void getListOfStudentsOfCourse(Student*, int);

void showStudentsWithGoodMarks(Student*);//показать студентов с "хорошими" оценками
void showStudentsWithWellMarks(Student*);//показать студентов с "отличными" оценками
void showStudentsWithSatisfactoryMarks(Student*);//показать студентов с положительными оценками
void showStudentsWithUnsatisfactoryMarks(Student*);//показать студентов с отрицательными оценками

int countStudentsWithUnsatisfactoryMarksForGroup(Student*, int);//подсчет количества студентов с неудотворительными оценками для группы
int countStudentsWithUnsatisfactoryMarksForCourse(Student*, int);//подсчет количества студентов с неудотворительными оценками для курса

void appointScholarship(Student*);//назначение стипендии относительно среднего балла

void sortArrayRegardingAverageMark(Student*);//сортировка по убыванию относительно среднего балла
void sortArrayRegardingCourse(Student*);//сортировка относительно курса
void sortArrayRegardingScholarship(Student*);//сортировка относительно стипендии
void sortArrayByCourseAndScholarship(Student*);//сортировка относительно курса и стипендии

void sortArrayInAlphabeticalOrderRegardingToWellStatus(Student*);//сортировка в алфавитном порядке
void showListOfWellStudents(Student*);//вывод отличников
float countPercentOfWellStudentsForCourse(Student*, int);//подсчет процента отличников для курса среди всего коичества отличников

void writeToFile(const char[100], Student*&);//запись в файл
void readFromFile(const char[100], Student*&);//чтение из файла

void task1(Student*, int);
void task2(Student*);
void task3(Student*);
void task7(Student*);

void menu(Student*);//меню
