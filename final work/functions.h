#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <iostream>
#include <fstream>
using namespace std;


void getListOfStudents(Student*);//������� ������ ���������
void getListOfStudentsOfGroup(Student*, int);
void getListOfStudentsOfCourse(Student*, int);

void showStudentsWithGoodMarks(Student*);//�������� ��������� � "��������" ��������
void showStudentsWithWellMarks(Student*);//�������� ��������� � "���������" ��������
void showStudentsWithSatisfactoryMarks(Student*);//�������� ��������� � �������������� ��������
void showStudentsWithUnsatisfactoryMarks(Student*);//�������� ��������� � �������������� ��������

int countStudentsWithUnsatisfactoryMarksForGroup(Student*, int);//������� ���������� ��������� � ������������������ �������� ��� ������
int countStudentsWithUnsatisfactoryMarksForCourse(Student*, int);//������� ���������� ��������� � ������������������ �������� ��� �����

void appointScholarship(Student*);//���������� ��������� ������������ �������� �����

void sortArrayRegardingAverageMark(Student*);//���������� �� �������� ������������ �������� �����
void sortArrayRegardingCourse(Student*);//���������� ������������ �����
void sortArrayRegardingScholarship(Student*);//���������� ������������ ���������
void sortArrayByCourseAndScholarship(Student*);//���������� ������������ ����� � ���������

void sortArrayInAlphabeticalOrderRegardingToWellStatus(Student*);//���������� � ���������� �������
void showListOfWellStudents(Student*);//����� ����������
float countPercentOfWellStudentsForCourse(Student*, int);//������� �������� ���������� ��� ����� ����� ����� ��������� ����������

void writeToFile(const char[100], Student*&);//������ � ����
void readFromFile(const char[100], Student*&);//������ �� �����

void task1(Student*, int);
void task2(Student*);
void task3(Student*);
void task7(Student*);

void menu(Student*);//����