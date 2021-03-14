#include "student.h"
#include <iostream>

// private member function used to output a string for degree program.
std::string student::m_tostring(const DegreeProgram& degreeProgram)
{
	if (degreeProgram == SECURITY)
    {
	    return "Security";
    }
	if (degreeProgram == NETWORK)
    {
	    return "Network";
    }
	if (degreeProgram == SOFTWARE)
    {
	    return "Software";
    }
	else
    {
	    return "invalid degree program";
    }
}

//constructors
student::student()
	: m_ID("null"), m_firstName("null"), m_lastName("null"), m_emailAddress("null"), m_age(0), m_degreeProgram(SOFTWARE)
{
    m_degreeProgramString = this->m_tostring(SOFTWARE);
}

student::student(std::string  studentId, std::string  firstName, std::string  lastName,
                 std::string  emailAddress, const int& age, std::vector<int, std::allocator<int>> numOfDaysLeft, const DegreeProgram& degreeProgram)
	: m_ID(std::move(studentId)), m_firstName(std::move(firstName)), m_lastName(std::move(lastName)), m_emailAddress(std::move(emailAddress)), m_age(age),
      m_degreeProgram(degreeProgram)
{
	for (int i = 0; i < 3; i++)
    {
	    this->m_numOfDaysLeft[i] = numOfDaysLeft[i];
    }
    m_degreeProgramString = this->m_tostring(degreeProgram);
}

//destructor
student::~student() = default;

//copy constructor
student::student(const student& copiedStudent)
	: m_ID(copiedStudent.m_ID), m_firstName(copiedStudent.m_firstName), m_lastName(copiedStudent.m_lastName),
      m_emailAddress(copiedStudent.m_emailAddress), m_age(copiedStudent.m_age), m_degreeProgram(copiedStudent.m_degreeProgram)
{
	for (int i = 0; i < 3; i++)
    {
	    this->m_numOfDaysLeft[i] = copiedStudent.m_numOfDaysLeft[i];
    }
    m_degreeProgramString = this->m_tostring(copiedStudent.m_degreeProgram);
}

//copy assignment operator
student& student::operator=(const student& copiedStudent)
{
    m_ID = copiedStudent.m_ID;
    m_firstName = copiedStudent.m_firstName;
    m_lastName = copiedStudent.m_lastName;
    m_emailAddress = copiedStudent.m_emailAddress;
    m_age = copiedStudent.m_age;
	for (int i = 0; i < 3; i++)
    {
	    this->m_numOfDaysLeft[i] = m_numOfDaysLeft[i];
    }
    m_degreeProgram = copiedStudent.m_degreeProgram;
    m_degreeProgramString = this->m_tostring(copiedStudent.m_degreeProgram);
	return *this;
}

// Prints student data to console.
void student::Print() const
{
	std::cout << "Student ID: " << m_ID << "\n";
	std::cout << "Name: " << m_firstName << " " << m_lastName << "\nEmail: " << m_emailAddress << "\nAge: " << m_age << "\n";
	std::cout << "Days left for course 1: " << m_numOfDaysLeft[0] << "\nDays left for course 2: " << m_numOfDaysLeft[1] << "\n";
	std::cout << "Days left for course 3: " << m_numOfDaysLeft[2] << "\nDegree program: " << m_degreeProgramString << "\n-----------------------\n";
}

// getters
std::string student::getStudentId() const
{
	return this->m_ID;
}

std::string student::getEmailAddress() const
{
	return this->m_emailAddress;
}

int student::getNumOfDaysLeft(const int& index) const
{
	return m_numOfDaysLeft[(int&&)index];
}