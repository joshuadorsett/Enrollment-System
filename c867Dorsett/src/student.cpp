#include "student.h"
#include <iostream>
#include <xutility>

// private member function used to output a string for degree program.
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

//constructors
student::student()
	:studentId("null"), firstName("null"), lastName("null"), emailAddress("null"), age(0), degreeProgram(SOFTWARE)
{
	degreeProgramString = this->tostring(SOFTWARE);
}

student::student(const std::string& studentId, const std::string& firstName, const std::string& lastName,
	const std::string& emailAddress, const int& age, int numOfDaysLeft[], const DegreeProgram& degreeProgram)
	: studentId(studentId), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age),
	degreeProgram(degreeProgram)
{
	for (int i = 0; i < 3; i++)
		this->numOfDaysLeft[i] = numOfDaysLeft[i];
	degreeProgramString = this->tostring(degreeProgram);
}

//destructor
student::~student()
{}

//copy constructor
student::student(const student& copiedStudent)
	: studentId(copiedStudent.studentId), firstName(copiedStudent.firstName), lastName(copiedStudent.lastName),
	emailAddress(copiedStudent.emailAddress), age(copiedStudent.age), degreeProgram(copiedStudent.degreeProgram)
{
	for (int i = 0; i < 3; i++)
		this->numOfDaysLeft[i] = copiedStudent.numOfDaysLeft[i];
	degreeProgramString = this->tostring(copiedStudent.degreeProgram);
}

//copy assignment operator
student& student::operator=(const student& copiedStudent)
{
	studentId = copiedStudent.studentId;
	firstName = copiedStudent.firstName;
	lastName = copiedStudent.lastName;
	emailAddress = copiedStudent.emailAddress;
	age = copiedStudent.age;
	for (int i = 0; i < 3; i++)
		this->numOfDaysLeft[i] = numOfDaysLeft[i];
	degreeProgram = copiedStudent.degreeProgram;
	degreeProgramString = this->tostring(copiedStudent.degreeProgram);
	return *this;
}

// Prints student data to console.
void student::Print() const
{
	std::cout << "Student ID: " << studentId << "\n";
	std::cout << "Name: " << firstName << " " << lastName << "\nEmail: " << emailAddress << "\nAge: " << age << "\n";
	std::cout << "Days left for course 1: " << numOfDaysLeft[0] << "\nDays left for course 2: " << numOfDaysLeft[1] << "\n";
	std::cout << "Days left for course 3: " << numOfDaysLeft[2] << "\nDegree program: " << degreeProgramString << "\n-----------------------\n";
}

// getters
std::string student::getStudentId() const
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
void student::setStudentId(const std::string& id)
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