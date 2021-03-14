#pragma once
#include <string>
#include <array>
#include <vector>
#include "degree.h"
class student
{
private:
	//private student information
	std::string m_ID;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_emailAddress;
	int m_age;
	std::vector<int> m_numOfDaysLeft{0, 0, 0 };
	DegreeProgram m_degreeProgram;
	std::string m_degreeProgramString;
	static std::string m_tostring(const DegreeProgram& degreeProgram);

public:
	//constructors
	student();
	student(std::string  studentId, std::string  firstName, std::string  lastName,
            std::string  emailAddress, const int& age, std::vector<int, std::allocator<int>> numOfDaysLeft, const DegreeProgram& degreeProgram);
	
	//destructor
	~student();

	//copy constructor
	student(const student& copiedStudent);

	//copy assignment operator
	student& operator=(const student& copiedStudent);

	// Prints Student data to console.
	void Print() const;

	//getters
	std::string getStudentId() const;
	std::string getEmailAddress() const;
	int getNumOfDaysLeft(const int& index) const;

};

