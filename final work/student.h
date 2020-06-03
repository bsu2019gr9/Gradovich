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

	Student();//����������� ��� ����������
	//����������� � �����������
	Student(const char[30], const char[30], const char[30], const int, const int, const int[10], const float, const float, const int, const int);
	//~Student();//�����������

	Student(const Student&);//����������� �����������
	const Student& operator=(const Student&);//�������� ������������

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);

	void setSurname(const char*);//������ �������
	void setName(const char*);//������ ���
	void setPatronymic(const char*);//������ ��������
	void setCourse(int);//������ ����
	void setGroup(int);//������ ������
	void setMarks(int*);//������ ������
	void setScholarship(float);//������ ���������
	void setStudent(const char*, const char*, const char*, int, int, int*, float);//������ ��������
	void setStudent();//������ �������� ��� ����������

	void editSurname(const char*);//������������� �������
	void editName(const char*);//������������� ���
	void editPatronymic(const char*);//������������� ��������
	void editCourse(int);//������������� ����
	void editGroup(int);//������������� ������
	void editMarks(int*);//������������� ������
	void editScholarship(float);//������������� ���������
	void editStudent(const char*, const char*, const char*, int, int, int*, float);//������������� ��������
	void editStudent();//������������� �������� ��� ����������

	void deleteSurname();//������� �������
	void deleteName();//������� ���
	void deletePatronymic();//������� ��������
	void deleteCourse();//������� ����
	void deleteGroup();//������� ������
	void deleteMarks();//������� ������
	void deleteScholarship();//������� ���������
	void deleteStudent();//������� ��������

	void getSurname();//������� �������
	void getName();//������� ���
	void getPatronymic();//������� ��������
	void getCourse();//������� ����
	void getGroup();//������� ������
	void getMarks();//������� ������
	void getAverageMark();//������� ������� ������
	void getScholarship();//������� ���������
	void getStudent();//������� ���������� � ��������

	void countAverageMark(int*);//��������� ������� ������

	void determineStudentStatus();//���������� ������ ��������
	void showStudentWithGoodStatus();//�������� �������� � "��������" ��������
	void showStudentWithWellStatus();//�������� �������� � "���������" ��������
	void showStudentWithSatisfactoryMarks();//�������� �������� � "�������������������" ��������
	void showStudentWithUnsatisfactoryMarks();//�������� �������� � "���������������������" ��������

	int getIntGroup() const;//������ ������ ������
	int getIntCourse() const;//������ ������ �����
	int getIntSatisfaction() const;//������ ������� �������������������� ������
	int getIntStatus();//������ ������� ������ ��� ���������
	float getFloatAverageMark();//������ ������� ������
	float getFloatScholarship() const;//������ ���������
	char* getCharSurname() const;//������ �������
};