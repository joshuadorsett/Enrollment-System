#pragma once

#include "student.h"
#include <iostream>
#include "degree.h"
#include <vector>
class roster
{
private:
	std::vector<student*> classRosterArray;

public:
	roster();
	~roster();
	void add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram);

	void remove(const std::string& studentID);

	int getSize() const;

	student* getRoster(const int& index) const;

	void printRoster() const;

	void printAverageDaysInCourse(const std::string& studentID);

	void printInvalidEmails();

	void printByDegreeProgram(const DegreeProgram& degreeProgram);

};

