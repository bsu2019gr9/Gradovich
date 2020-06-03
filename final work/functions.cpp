#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "functions.h"
#include <iostream>
#include <fstream>
using namespace std;


void getListOfStudents(Student* A) {
	for (int i = 0; i < M; ++i) {
		A[i].getStudent();
	}
}

void getListOfStudentsOfGroup(Student* A, int group) {
	for (int i = 0; i < M; ++i) {
		if (A[i].getIntGroup() == group)
			A[i].getStudent();
	}
}

void getListOfStudentsOfCourse(Student* A, int course) {
	for (int i = 0; i < M; ++i) {
		if (A[i].getIntCourse() == course)
			A[i].getStudent();
	}
}

void showStudentsWithGoodMarks(Student* A) {
	cout << "\n\nStudents with good marks\n";
	for (int i = 0; i < M; ++i) {
		A[i].showStudentWithGoodStatus();
	}
}

void showStudentsWithWellMarks(Student* A) {
	cout << "\n\nStudents with well marks\n";
	for (int i = 0; i < M; ++i) {
		A[i].showStudentWithWellStatus();
	}
}

void showStudentsWithSatisfactoryMarks(Student* A) {
	cout << "\n\nStudents with satisfactory marks\n";
	for (int i = 0; i < M; ++i) {
		A[i].showStudentWithSatisfactoryMarks();
	}
}

void showStudentsWithUnsatisfactoryMarks(Student* A) {
	cout << "\n\nStudents with unsatisfactory marks\n";
	for (int i = 0; i < M; ++i) {
		A[i].showStudentWithUnsatisfactoryMarks();
	}
}

int countStudentsWithUnsatisfactoryMarksForGroup(Student* A, int group) {
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		if (A[i].getIntGroup() == group) {
			A[i].determineStudentStatus();
			if (A[i].getIntSatisfaction() == 2) cnt++;
		}
	}
	return cnt;
}

int countStudentsWithUnsatisfactoryMarksForCourse(Student* A, int course) {
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		if (A[i].getIntCourse() == course) {
			A[i].determineStudentStatus();
			if (A[i].getIntSatisfaction() == 2) cnt++;
		}
	}
	return cnt;
}

void appointScholarship(Student* A) {
	float average = 0;
	for (int i = 0; i < M; ++i) {
		average = A[i].getFloatAverageMark();
		A[i].determineStudentStatus();
		if (A[i].getIntSatisfaction() == 1) {
			if (average == 10) A[i].editScholarship(160);
			else if (average > 8) A[i].setScholarship(140);
			else if (average > 6) A[i].setScholarship(120);
			else if (average > 5) A[i].setScholarship(100);
		}
		else if (A[i].getIntSatisfaction() == 2) A[i].setScholarship(0);
	}
}

void sortArrayRegardingAverageMark(Student* A) {
	float k = 0, j = 0;
	int biggest = 0;
	for (int start = 0; start < M - 1; ++start) {
		if (!A[start].getFloatAverageMark()) continue;
		biggest = start;
		for (int current = start + 1; current < M; ++current) {
			k = A[current].getFloatAverageMark();
			j = A[biggest].getFloatAverageMark();
			if (k > j)
				biggest = current;
		}
		swap(A[start], A[biggest]);
	}
}

void sortArrayRegardingCourse(Student* A) {
	float k = 0, j = 0;
	int smallest = 0;
	for (int start = 0; start < M - 1; ++start) {
		if (!A[start].getIntCourse()) continue;
		smallest = start;
		for (int current = start + 1; current < M; ++current) {
			if (A[current].getIntCourse() < A[smallest].getIntCourse())
				smallest = current;
		}
		swap(A[start], A[smallest]);
	}
}

void sortArrayRegardingScholarship(Student* A) {
	int biggest = 0;
	for (int start = 0; start < M - 1; ++start) {
		biggest = start;
		for (int current = start + 1; current < M; ++current) {
			if (A[current].getFloatScholarship() > A[biggest].getFloatScholarship())
				biggest = current;
		}
		swap(A[start], A[biggest]);
	}
}

void sortArrayByCourseAndScholarship(Student* A) {
	sortArrayRegardingScholarship(A);
	for (int i = 0; i < 5; ++i)
		getListOfStudentsOfCourse(A, i);

}

void sortArrayInAlphabeticalOrderRegardingToWellStatus(Student* A) {
	Student tmp; char* curr, * prev;
	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			curr = A[j].getCharSurname();
			prev = A[i].getCharSurname();
			if (prev && curr) {
				if (strcmp(prev, curr) > 0) {
					swap(A[i], A[j]);
				}
			}
		}
	}
}

void showListOfWellStudents(Student* A) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < M; ++j)
			if (A[j].getIntCourse() == i) {
				A[j].showStudentWithWellStatus();
			}
	}
}

float countPercentOfWellStudentsForCourse(Student* A, int course) {
	float all = 0, crs = 0;
	int stat = 0;
	for (int i = 0; i < M; ++i) {
		stat = A[i].getIntStatus();
		if (stat == 2 && A[i].getIntCourse() == course) { ++crs; ++all; }
		else if (stat == 2) ++all;
	}
	return crs / all * 100;
}

void writeToFile(const char path[100], Student*& A) {
	ofstream fout(path, ios::binary);
	if (!fout) { cout << "File didn't open\n"; exit(37); }
	for (int i = 0; i < M; ++i) {
		fout.write((char*)&A[i], sizeof(Student));
	}
	fout.close();
}

void readFromFile(const char path[100], Student*& A) {
	ifstream fin(path, ios::binary);
	if (!fin) { cout << "File didn't open\n"; exit(37); }
	Student buffer;
	int N = 0;
	while (N < M) {
		fin.read((char*)&buffer, sizeof(Student));
		if (fin.eof()) break;
		A[N] = buffer;
		++N;
	}
	fin.close();
}

void task1(Student* A, int num) {
	int task = 0, k = 1;
	while (k) {
		cout << "\n\nPress 1 - Set student\n" << "Press 2 - Edit student\n" << "Press 3 - Delete student\n";
		cin >> task;
		switch (task) {
		case 1:
			A[num].setStudent();
			break;
		case 2:
			A[num].editStudent();
			break;
		case 3:
			A[num].deleteStudent();
			break;
		}
		cout << "\nIf you want to choose another function press 1, if you want to return to menu press 0\n";
		cin >> k;
	}
}

void task2(Student* A) {
	int task = 0, k = 1;
	while (k) {
		cout << "\n\nPress 1 - Show students with well marks\n" << "Press 2 - Show students with good and well marks\n" <<
			"Press 3 - Show students with satisfactory marks\n" << "Press 4 - Show students with unsatisfactory marks\n";
		cin >> task;
		switch (task) {
		case 1: showStudentsWithWellMarks(A); break;
		case 2:showStudentsWithGoodMarks(A); break;
		case 3:showStudentsWithSatisfactoryMarks(A); break;
		case 4:showStudentsWithUnsatisfactoryMarks(A); break;
		}
		cout << "\nIf you want to choose another function press 1, if you want to return to menu press 0\n";
		cin >> k;
	}
}

void task3(Student* A) {
	int task = 0, k = 1, num = 0;
	while (k) {
		cout << "\nPress 1 - Count students with unsatisfactory marks for course\n" <<
			"\nPress 2 - Count students with unsatisfactory marks for group\n" <<
			"\nPress 3 - Count students with unsatisfactory marks for all courses\n" <<
			"\nPress 4 - Count students with unsatisfactory marks for all groups\n";
		cin >> task;
		switch (task) {
		case 1:
			cout << "Enter course ";
			cin >> num;
			cout << "\nNumber of students with unsatisfactory marks for this course is ";
			cout << countStudentsWithUnsatisfactoryMarksForCourse(A, num);
			break;
		case 2:
			cout << "Enter group ";
			cin >> num;
			cout << "\nNumber of students with unsatisfactory marks for this group is ";
			cout << countStudentsWithUnsatisfactoryMarksForGroup(A, num);
			break;
		case 3:
			for (num = 1; num <= 20; ++num) {
				cout << "\nNumber of students with unsatisfactory marks for " << num << " group is ";
				cout << countStudentsWithUnsatisfactoryMarksForGroup(A, num);
			}
			break;
		case 4:
			for (num = 1; num <= 5; ++num) {
				cout << "\nNumber of students with unsatisfactory marks for " << num << " course is ";
				cout << countStudentsWithUnsatisfactoryMarksForCourse(A, num);
			}
			break;
		}
		cout << "\n\nIf you want to choose another function press 1, if you want to return to menu press 0\n";
		cin >> k;
	}
}

void task7(Student* A) {
	sortArrayInAlphabeticalOrderRegardingToWellStatus(A);
	showListOfWellStudents(A);
	for (int num = 1; num <= 5; ++num) {
		cout << "\nNumber of students with well marks for " << num << " course is ";
		cout << countPercentOfWellStudentsForCourse(A, num);
	}
}

void menu(Student* A) {
	int k = 1;
	int choice = 0, num = 0;
	while (k) {
		cout << "\nChoose what you want to do:\n" << "Press 1 - Set/edit/delete student\n" <<
			"Press 2 - Find students, that pass exams on well marks/on well or good marks/with satisfactory marks/with unsatisfactory marks\n" <<
			"Press 3 - Count students with unsatisfactory marks for course/for group\n" <<
			"Press 4 - Appoint scholarship for students\n" <<
			"Press 5 - Sort students descending regarding average mark\n" <<
			"Press 6 - Sort students regarding course and scholarship\n" <<
			"Press 7 - Get list of students with well marks  and percent of all students with well marks for every course in alphabetical order\n" <<
			"Press 8 - Print list of all students\n\n";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter number of student\n";
			cin >> num;
			task1(A, num);
			break;
		case 2:
			task2(A);
			break;
		case 3:
			task3(A);
			break;
		case 4:
			appointScholarship(A);
			break;
		case 5:
			sortArrayRegardingAverageMark(A);
			break;
		case 6:
			sortArrayByCourseAndScholarship(A);
			break;
		case 7:
			task7(A);
			break;
		case 8: 
			getListOfStudents(A);
			break;
		}
		cout << "\nIf you want to choose another function - press 1, to finish press 0\n";
		cin >> k;
	}
}