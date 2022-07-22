#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(string id, string fname, string lname, string email, int a, int days[3], DegreeProgram program) {
	studentID = id;
	firstName = fname;
	lastName = lname;
	emailAddress = email;
	age = a;
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = days[i];
	}
	degreeProgram = program;
}
 
//Getters

string Student::GetStudentID() { return studentID; }
string Student::GetFirstName() { return firstName; }
string Student::GetLastName() { return lastName; }
string Student::GetEmailAddress() { return emailAddress; }
int Student::GetAge() { return age; }
int* Student::GetDaysInCourse() { return daysInCourse; }
DegreeProgram Student::GetDegreeProgram() { return degreeProgram; }
string Student::GetDegreeProgram(string str) {
	if (degreeProgram == SECURITY) {
		return "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		return "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		return "SOFTWARE";
	}
}

//Setters

void Student::SetStudentID(string id) { studentID = id; }
void Student::SetFirstName(string fname) { firstName = fname; }
void Student::SetLastName(string lname) { lastName = lname; }
void Student::SetEmailAddress(string email) { emailAddress = email; }
void Student::SetAge(int a) { age = a; }
void Student::SetDaysInCourse(int index, int days) { daysInCourse[index] = days; }
void Student::SetDegreeProgram(DegreeProgram program) { degreeProgram = program; }
void Student::SetDaysInCourse(int* days) {
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = days[i];
	}
}

//Utility

bool Student::ValidateEmailAddress() {
	if (emailAddress.find("@") == string::npos ||
		emailAddress.find(".") == string::npos ||
		emailAddress.find(" ") != string::npos) {
		return true;
	}
	return false;
}

void Student::Print() {
	int i = 0;

	cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "daysInCourse: {" << "\t";
	cout << daysInCourse[i];
	for (int i = 1; i < 3; i++) {
		cout << ", " << daysInCourse[i];
	}
	cout << "}\tDegree Program: " << GetDegreeProgram(" ") << "." << endl;
}

float Student::GetAverageDaysInCourses() {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += daysInCourse[i];
	}
	return static_cast<float>(sum) / 3;
}