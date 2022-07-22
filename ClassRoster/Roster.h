#pragma once
#include "Student.h"
using namespace std;

class Roster {
	public:
		~Roster();
		void Add(
			string studentID,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int daysInCourse1,
			int daysInCourse2,
			int daysInCourse3,
			DegreeProgram degreeprogram
		);
		void Remove(string studentID);
		void PrintAll();
		void PrintAverageDaysInCourse(string studentID);
		void PrintInvalidEmails();
		void PrintByDegreeProgram(DegreeProgram);
		void PrintByDegreeProgram();
		string GetSID(int studentNo);
	private:
		Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};