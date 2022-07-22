#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Roster.h"
using namespace std;

int main() {
	Roster classRoster;
	DegreeProgram program;

	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Joseph,Foley,JFole50@WGU.edu,32,1,1,1,SOFTWARE" 
	};

	//Header

	cout << "+---------------------------------------------------+" << endl;
	cout << "|  Scripting and Programming - Applications - C867  |" << endl;
	cout << "|          Programming Language Used : C++          |" << endl;
	cout << "|             010093068 : Joseph Foley              |" << endl;
	cout << "+---------------------------------------------------+" << endl;

	//Adding students to the roster

	cout << "Adding Students to Roster: " << endl;

	for (int i = 0; i < 5; i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string variables[9];

		int j = 0;
		while (getline(ss, token, ',')) {
			variables[j] = token;
			j += 1;
		}

		if (variables[8] == "SECURITY") {
			program = SECURITY;
		}
		else if (variables[8] == "NETWORK") {
			program = NETWORK;
		}
		else if (variables[8] == "SOFTWARE") {
			program = SOFTWARE;
		}

		cout << "\nAdding" << endl;
		for (string s : variables) {
			cout << s << " ";
		}
		classRoster.Add(
			variables[0],
			variables[1],
			variables[2],
			variables[3],
			stoi(variables[4]),
			stoi(variables[5]),
			stoi(variables[6]),
			stoi(variables[7]),
			program
		);
		cout << " success" << endl;
	}
	cout << endl;

	//Task related activities

	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();

	for (int i = 0; i < 5; i++) {
		classRoster.PrintAverageDaysInCourse(classRoster.GetSID(i));
	}

	classRoster.PrintByDegreeProgram(SOFTWARE);
	classRoster.Remove("A3");
	classRoster.PrintAll();
	classRoster.Remove("A3");
}

