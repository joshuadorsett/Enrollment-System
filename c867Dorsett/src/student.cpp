// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "student.h"
#include <iostream>
#include <xutility>

std::string student::tostring(const DegreeProgram& degreeProgram)
{
	if (degreeProgram == SECURITY)
		return "Security";
	if (degreeProgram == NETWORK)
		return "Network";
	if (degreeProgram == SOFTWARE)
		return "Software";
	else
		return "invalid degree program";
}

student::student()
	:studentId(0), firstName("null"), lastName("null"), emailAddress("null"), age(0), degreeProgram(SOFTWARE)
{
	degreeProgramString = this->tostring(SOFTWARE);
}
student::student(const int& studentId, const std::string& firstName, const std::string& lastName,
	const std::string& emailAddress, const int& age, const int& daysInCourse1, const int& daysInCourse2,
	const int& daysInCourse3, const DegreeProgram& degreeProgram)
	: studentId(studentId), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age),
	degreeProgram(degreeProgram)
{
	numOfDaysLeft[0] = daysInCourse1;
	numOfDaysLeft[1] = daysInCourse2;
	numOfDaysLeft[2] = daysInCourse3;
	degreeProgramString = this->tostring(degreeProgram);
}

student::~student()
{
}


student::student(const student& copiedStudent)
	: studentId(copiedStudent.studentId), firstName(copiedStudent.firstName), lastName(copiedStudent.lastName),
	emailAddress(copiedStudent.emailAddress), age(copiedStudent.age),
	degreeProgram(copiedStudent.degreeProgram)
{
	numOfDaysLeft[0] = copiedStudent.numOfDaysLeft[0];
	numOfDaysLeft[1] = copiedStudent.numOfDaysLeft[1];
	numOfDaysLeft[2] = copiedStudent.numOfDaysLeft[2];
	degreeProgramString = this->tostring(copiedStudent.degreeProgram);
}

student& student::operator=(const student& copiedStudent)
{
	studentId = copiedStudent.studentId;
	firstName = copiedStudent.firstName;
	lastName = copiedStudent.lastName;
	emailAddress = copiedStudent.emailAddress;
	age = copiedStudent.age;
	numOfDaysLeft[0] = copiedStudent.numOfDaysLeft[0];
	numOfDaysLeft[1] = copiedStudent.numOfDaysLeft[1];
	numOfDaysLeft[2] = copiedStudent.numOfDaysLeft[2];
	degreeProgram = copiedStudent.degreeProgram;
	degreeProgramString = this->tostring(copiedStudent.degreeProgram);
	return *this;
}
/*
student::student(student&& copiedStudent) noexcept
{
}
student& student::operator=(student&& copiedStudent) noexcept
{
	return *this;
}
*/

void student::Print() const
{
	std::cout << "information for student number " << studentId << "\n";
	std::cout << "name: " << firstName << " " << lastName << "\nemail: " << emailAddress << "\nage: " << age << "\n";
	std::cout << "days left for course 1: " << numOfDaysLeft[0] << "\ndays left for course 2: " << numOfDaysLeft[1] << "\n";
	std::cout << "days left for course 3: " << numOfDaysLeft[2] << "\ndegree program: " << degreeProgramString << "\n";
}

// getters
int student::getStudentId() const
{
	return this->studentId;
}

std::string student::getFirstName() const
{
	return this->firstName;
}

std::string student::getLastName() const
{
	return this->lastName;
}

std::string student::getEmailAddress() const
{
	return this->emailAddress;
}

int student::getAge() const
{
	return this->age;
}

int student::getNumOfDaysLeft(const int& index) const
{
	return numOfDaysLeft[(int&&)index];
}

DegreeProgram student::getDegreeProgram() const
{
	return this->degreeProgram;
}

//setters
void student::setStudentId(const int& id)
{
	this->studentId = id;
}

void student::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void student::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void student::setEmailAddress(const std::string& emailAddress)
{
	this->emailAddress = emailAddress;
}

void student::setAge(const int& age)
{
	this->age = age;
}

void student::setNumOfDaysLeft(const int& courseOne, const int& courseTwo, const int& courseThree)
{
	this->numOfDaysLeft[0] = courseOne;
	this->numOfDaysLeft[1] = courseTwo;
	this->numOfDaysLeft[2] = courseThree;

}

void student::setDegreeProgram(const DegreeProgram& degreeProgram)
{
	this->degreeProgram = degreeProgram;
}