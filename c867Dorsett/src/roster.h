#pragma once
/*
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2.  Create a student object for each student in the data table and populate classRosterArray.
a.  Parse each set of data identified in the “studentData Table.”
b.  Add each student object to classRosterArray.
3.  Define the following functions:
a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster
b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.

e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

*/
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

