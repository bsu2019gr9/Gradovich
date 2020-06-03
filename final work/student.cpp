#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include <fstream>
using namespace std;


Student::Student() :surname(new (nothrow) char[30]), name(new (nothrow) char[30]), patronymic(new (nothrow) char[30]), course(0), group(0), averageMark(0),
scholarship(0), status(0), satisfaction(0) {
	strcpy(surname, "NULL");
	strcpy(name, "NULL");
	strcpy(patronymic, "NULL");
	for (int i = 0; i < 10; ++i) {
		marks[i] = 0;
	}
}

Student::Student(const char _surname[30], const char _name[30], const char _patronymic[30],
	const int _course, const int _group, const int _marks[10], const float _averageMark, const float _scholarship, const int _status, const int _satisfaction) :
	surname(new (nothrow) char[strlen(_surname) + 1]), name(new (nothrow) char[strlen(_name) + 1]), patronymic(new (nothrow) char[strlen(_patronymic) + 1])
{
	strcpy(surname, _surname);
	strcpy(name, _name);
	strcpy(patronymic, _patronymic);
	course = _course;
	group = _group;
	for (int i = 0; i < 10; ++i) {
		marks[i] = _marks[i];
	}
	averageMark = _averageMark;
	scholarship = _scholarship;
	status = _status;
	satisfaction = _satisfaction;
}

Student::Student(const Student& other) :
	surname(new (nothrow) char[strlen(other.surname) + 1]),
	name(new (nothrow) char[strlen(other.name) + 1]),
	patronymic(new (nothrow) char[strlen(other.patronymic) + 1]),
	course(other.course),
	group(other.group),
	averageMark(other.averageMark),
	scholarship(other.scholarship),
	status(other.status),
	satisfaction(other.satisfaction)
{
	strcpy(surname, other.surname);
	strcpy(name, other.name);
	strcpy(patronymic, other.patronymic);
	for (int j = 0; j < 10; j++) {
		marks[j] = other.marks[j];
	}
}

const Student& Student::operator=(const Student& A) {

	if (this == &A)
		return *this;

	if(surname)
	delete[] surname;
	surname = new (nothrow) char[strlen(A.surname) + 1];
	strcpy(surname, A.surname);

	if (name)
	delete[] name;
	name = new (nothrow) char[strlen(A.name) + 1];
	strcpy(name, A.name);

	if (patronymic)
	delete[] patronymic;
	patronymic = new (nothrow) char[strlen(A.patronymic) + 1];
	strcpy(patronymic, A.patronymic);

	course = A.course;
	group = A.group;
	for (int j = 0; j < 10; j++) {
		marks[j] = A.marks[j];
	}
	averageMark = A.averageMark;
	scholarship = A.scholarship;
	status = A.status;
	satisfaction = A.satisfaction;

	return *this;
}

ostream& operator<<(ostream& out, const Student& A) {
	out << "Surname: " << A.surname << "\n";
	out << "Name: " << A.name << "\n";
	out << "Patronymic: " << A.patronymic << "\n";
	out << "Course: " << A.course << "\n";
	out << "Group: " << A.group << "\n";
	out << "Marks: ";
	for (int i = 0; i < 10; ++i) {
		if (A.marks[i] != 0)
			out << A.marks[i] << " ";
	}
	out << "\n";
	out << "Average mark: " << A.averageMark << "\n";
	out << "Scholarship: " << A.scholarship << "\n";
	return out;
}

istream& operator>>(istream& in, Student& A) {
	char buf[30];
	int tmp;
	float temp;
	in.getline(buf, 30);
	A.setSurname(buf);
	in.getline(buf, 30);
	A.setName(buf);
	in.getline(buf, 30);
	A.setPatronymic(buf);
	in >> tmp;
	A.setCourse(tmp);
	in >> tmp;
	A.setGroup(tmp);
	for (int i = 0; i < 10; ++i) {
		in >> tmp;
		if (tmp != 0)
			A.marks[i] = tmp;
		else i = 10;
	}
	in >> temp;
	A.setScholarship(temp);
	return in;
}



void Student::setSurname(const char* surname) {
	strcpy(this->surname, surname);
}

void Student::setName(const char* name) {
	strcpy(this->name, name);
}

void Student::setPatronymic(const char* patronymic) {
	strcpy(this->patronymic, patronymic);
}

void Student::setCourse(int course) {
	this->course = course;
}

void Student::setGroup(int group) {
	this->group = group;
}

void Student::setMarks(int* marks) {
	for (int i = 0; i < 10; ++i) {
		this->marks[i] = marks[i];
	}
}

void Student::setScholarship(float scholarship) {
	this->scholarship = scholarship;
}

void Student::setStudent(const char* surname, const char* name, const char* patronymic, int course, int group, int* marks, float scholarship) {
	setSurname(surname);
	setName(name);
	setPatronymic(patronymic);
	setCourse(course);
	setGroup(group);
	setMarks(marks);
	setScholarship(scholarship);
}

void Student::setStudent() {
	char tmpsurname[30], tmpname[30], tmppatronymic[30];
	char* surname = nullptr, * name = nullptr, * patronymic = nullptr;
	surname = new (nothrow) char[30];
	name = new (nothrow) char[30];
	patronymic = new (nothrow) char[30];
	int course = 0, group = 0, marks[10], tmp = 0;
	float scholarship = 0;
	cout << "Surname: "; cin >> tmpsurname; strcpy(surname, tmpsurname);
	cout << "Name: "; cin >> tmpname; strcpy(name, tmpname);
	cout << "Patronymic: "; cin >> tmppatronymic; strcpy(patronymic, tmppatronymic);
	cout << "Course: "; cin >> course;
	cout << "Group: "; cin >> group;
	cout << "Marks: ";
	for (int i = 0; i < 10; ++i) {
		cin >> tmp;
		if (tmp != 0)
			marks[i] = tmp;
		else i = 10;
	}
	cout << "Scholarship: "; cin >> scholarship;
	setSurname(surname);
	setName(name);
	setPatronymic(patronymic);
	setCourse(course);
	setGroup(group);
	setMarks(marks);
	setScholarship(scholarship);
	delete[] surname; surname = nullptr;
	delete[] name; name = nullptr;
	delete[] patronymic; patronymic = nullptr;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

void Student::editSurname(const char* surname) {
	setSurname(surname);
}

void Student::editName(const char* name) {
	setName(name);
}

void Student::editPatronymic(const char* patronymic) {
	setPatronymic(patronymic);
}

void Student::editCourse(int course) {
	setCourse(course);
}

void Student::editGroup(int group) {
	setGroup(group);
}

void Student::editMarks(int* marks) {
	setMarks(marks);
}

void Student::editScholarship(float scholarship) {
	setScholarship(scholarship);
}

void Student::editStudent(const char* surname, const char* name, const char* patronymic, int course, int group, int* marks, float scholarship) {
	setStudent(surname, name, patronymic, course, group, marks, scholarship);
}

void Student::editStudent() {
	char* surname = nullptr, * name = nullptr, * patronymic = nullptr;
	int course = 0, group = 0, marks[10], tmp = 0;
	float scholarship = 0;
	cout << "Surname:"; cin >> surname;
	cout << "Name:"; cin >> name;
	cout << "Patronymic:"; cin >> patronymic;
	cout << "Course:"; cin >> course;
	cout << "Group:"; cin >> group;
	cout << "Marks:";
	for (int i = 0; i < 10; ++i) {
		cin >> tmp;
		if (tmp != 0)
			marks[i] = tmp;
		else i = 10;
	}
	cout << "Scholarship:"; cin >> scholarship;
	editSurname(surname);
	editName(name);
	editPatronymic(patronymic);
	editCourse(course);
	editGroup(group);
	editMarks(marks);
	editScholarship(scholarship);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

void Student::deleteSurname() {
	if (this->surname) {
		delete[] this->surname;
		this->surname = nullptr;
	}
}

void Student::deleteName() {
	if (this->name) {
		delete[] this->name;
		this->name = nullptr;
	}
}

void Student::deletePatronymic() {
	if (this->patronymic) {
		delete[] this->patronymic;
		this->patronymic = nullptr;
	}
}

void Student::deleteCourse() {
	this->course = 0;
}

void Student::deleteGroup() {
	this->group = 0;
}

void Student::deleteMarks() {
	for (int i = 0; i < 10; ++i) {
		this->marks[i] = 0;
	}
}

void Student::deleteScholarship() {
	scholarship = 0;
}

void Student::deleteStudent() {
	deleteSurname();
	deleteName();
	deletePatronymic();
	deleteCourse();
	deleteGroup();
	deleteMarks();
	deleteScholarship();
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

void Student::getSurname() {
	if (this->surname)  cout << this->surname << "\n"; else cout << "NULL\n";
}

void Student::getName() {
	if (this->name)  cout << this->name << "\n"; else cout << "NULL\n";
}

void Student::getPatronymic() {
	if (this->patronymic)  cout << this->patronymic << "\n"; else cout << "NULL\n";
}

void Student::getCourse() {
	if (this->course)  cout << this->course << "\n"; else cout << "NULL\n";
}

void Student::getGroup() {
	if (this->group)  cout << this->group << "\n"; else cout << "NULL\n";
}

void Student::getMarks() {
	if (this->marks) {
		for (int i = 0; i < 10; ++i) {
			if (this->marks[i] != 0)
				cout << this->marks[i] << " ";
		}
		cout << "\n";
	}
	else cout << "NULL\n";
}

void Student::getAverageMark() {
	countAverageMark(this->marks);
	if (this->averageMark)  cout << this->averageMark << "\n"; else cout << "NULL\n";
}

void Student::getScholarship() {
	if (this->scholarship)  cout << this->scholarship << "\n"; else cout << "NULL\n";
}

void Student::getStudent() {
	if (strcmp(this->surname, "NULL") != 0 || strcmp(this->name, "NULL") != 0 || strcmp(this->patronymic, "NULL") != 0 || this->course || this->group || this->scholarship) {
		cout.width(12);
		if (this->surname)  cout << this->surname << " "; else cout << "NULL ";
		cout.width(12);
		if (this->name)  cout << this->name << " "; else cout << "NULL ";
		cout.width(12);
		if (this->patronymic)  cout << this->patronymic << " "; else cout << "NULL ";
		cout.width(5);
		if (this->course)  cout << this->course << " course "; else cout << "NULL ";
		cout.width(5);
		if (this->group)  cout << this->group << " group "; else cout << "NULL ";
		countAverageMark(this->marks);
		cout.width(5);
		if (this->averageMark)  cout << this->averageMark << " "; else cout << "NULL ";
		cout.width(5);
		if (this->scholarship)  cout << this->scholarship << "BYN "; else cout << "NULL ";
		cout << "\n";
	}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

void Student::countAverageMark(int* marks) {
	int sum = 0, k = 0;
	for (int i = 0; i < 10; ++i) {
		sum += marks[i];
		if (marks[i] > 0) k++;
	}
	if (k) this->averageMark = (float)sum / k;
}

void Student::determineStudentStatus() {
	int good = 0, well = 0, m = 0, s = 0;
	for (int i = 0; i < 10; ++i) {
		if (this->marks[i] == 0) m++;
		if (this->marks[i] < 9 && this->marks[i] != 0) well++;
		if (this->marks[i] < 8 && this->marks[i] != 0) good++;
		if (this->marks[i] <= 4 && this->marks[i] != 0) s++;
	}
	if (m == 10) goto end;
	if (!good) { this->status = 1; }//good
	if (!well) { this->status = 2; }//well
	if (!s) this->satisfaction = 1;//satisfactory
	else this->satisfaction = 2;
end: {}
}

void Student::showStudentWithGoodStatus() {
	determineStudentStatus();
	if (this->status == 1 || this->status == 2) getStudent();
}

void Student::showStudentWithWellStatus() {
	determineStudentStatus();
	if (this->status == 2) getStudent();
}

void Student::showStudentWithSatisfactoryMarks() {
	determineStudentStatus();
	if (this->satisfaction == 1) getStudent();
}

void Student::showStudentWithUnsatisfactoryMarks() {
	determineStudentStatus();
	if (this->satisfaction == 2) getStudent();
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int Student::getIntGroup() const {
	return group;
}

int Student::getIntCourse() const {
	return course;
}

int Student::getIntSatisfaction() const {
	return satisfaction;
}

int Student::getIntStatus() {
	determineStudentStatus();
	return status;
}

float Student::getFloatAverageMark() {
	countAverageMark(marks);
	return averageMark;
}

float Student::getFloatScholarship() const {
	return scholarship;
}

char* Student::getCharSurname() const {
	return surname;
}