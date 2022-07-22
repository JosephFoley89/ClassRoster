#include <iostream>
#include <string>
#include "Roster.h"
using namespace std;

Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::Add(string id, string fname, string lname, string email, int a, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(id, fname, lname, email, a, courseDays, program);
			break;
		}
	}
}

void Roster::Remove(string studentID) {
	cout << endl << "Calling Remove " << studentID << ": " << endl;
	bool j = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr)
			if (classRosterArray[i]->GetStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				j = true;
			}
	}
	if (j == false) {
		cout << "ERROR - Student: " << studentID << " not found." << endl;
	}
}

void Roster::PrintAll() {
	cout << endl << "Calling PrintAll():" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	cout << endl << "Calling PrintAverageDaysInCourse() for each student:" << endl;
	int stuIDX;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			stuIDX = i;
		}
	}
	cout << "Student " << classRosterArray[stuIDX]->GetStudentID() << " " << " has averaged " <<
		classRosterArray[stuIDX]->GetAverageDaysInCourses() << " day(s) per course for the last three courses." << endl;
}

void Roster::PrintInvalidEmails() {
	cout << endl << "Calling PrintInvalidEmails():" << endl;
	cout << "Invalid email addresses:" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->ValidateEmailAddress()) {
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram byDegreeProgram) {
	cout << endl << "Calling PrintByDegreeProgram(SOFTWARE):" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == byDegreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::PrintByDegreeProgram() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (classRosterArray[i]->GetDegreeProgram() == NETWORK) {
				classRosterArray[i]->Print();
			}
			if (classRosterArray[i]->GetDegreeProgram() == SECURITY) {
				classRosterArray[i]->Print();
			}
			if (classRosterArray[i]->GetDegreeProgram() == SOFTWARE) {
				classRosterArray[i]->Print();
			}
		}
	}
}

string Roster::GetSID(int studentNo) {
	return classRosterArray[studentNo]->GetStudentID();
}