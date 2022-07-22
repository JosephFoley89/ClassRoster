#pragma once
#include "Degree.h"
using namespace std;

class Student {
	public:
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* courseDays, DegreeProgram degreeProgram);
		string GetStudentID();
		void SetStudentID(string id);
		string GetFirstName();
		void SetFirstName(string fname);
		string GetLastName();
		void SetLastName(string lname);
		string GetEmailAddress();
		void SetEmailAddress(string newEmailAddress);
		bool ValidateEmailAddress();
		int GetAge();
		void SetAge(int newAge);
		int* GetDaysInCourse();
		void SetDaysInCourse(int* daysInCourseVal);
		void SetDaysInCourse(int index, int days);
		DegreeProgram GetDegreeProgram();
		string GetDegreeProgram(string str);
		void SetDegreeProgram(DegreeProgram newDegProg);
		void Print();
		float GetAverageDaysInCourses();
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse[3] = { 189, 189, 189 };
		DegreeProgram degreeProgram;
};