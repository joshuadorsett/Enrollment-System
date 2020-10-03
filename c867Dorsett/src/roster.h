#pragma once

#include "student.h"
#include <iostream>
#include "degree.h"
#include <vector>
class roster
{
private:
	//dynamic array of pointers to each student in the roster.
	std::vector<student*> classRosterArray;

public:

	//constructors
	roster();
	~roster();

	//adds student to roster.
	void add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram);

	//removes student from roster.
	void remove(const std::string& studentID);

	//gets the size of the roster
	int getSize() const;

	//returns the pointer to the array of students.
	student* getRoster(const int& index) const;

	//calls student.print() function for each student in roster.
	void printRoster() const;

	//prints average days left for courses by student ID
	void printAverageDaysInCourse(const std::string& studentID);

	//prints a list of emails that are not valid according to email rules
	void printInvalidEmails();

	//prints the degree program associated with appropriate enum value.
	void printByDegreeProgram(const DegreeProgram& degreeProgram);

};

