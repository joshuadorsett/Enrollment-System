#pragma once

#include "student.h"
#include <iostream>
#include "degree.h"
class roster
{
private:
	int m_Size = 0;
	student* classRosterArray[50];

public:
	roster();
	~roster();
	void add(const int& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram);

	void remove(const int& studentID);

	void printRoster() const;

	void printAverageDaysInCourse(const int& studentID);

	void printInvalidEmails();

	void printByDegreeProgram(const DegreeProgram& degreeProgram);

};

