// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "roster.h"
#include <vector>
#include <xutility>

//constructor
roster::roster()
	:m_Size(0)
{
	for (auto& i : classRosterArray)
		i = nullptr;
}
//destructor
roster::~roster()
{
	for (int i = 0; i < m_Size; i++)
		delete classRosterArray[i];
}
void roster::add(const int& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress,
	const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram)
{
	student newStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	classRosterArray[m_Size] = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	m_Size++;
}
void roster::remove(const int& studentID)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (studentID == classRosterArray[i]->getStudentId())
		{
			delete classRosterArray[i];
			m_Size--;
		}
		else
		{
			std::cout << "student not found in roster";
		}
	}
}

void roster::printRoster() const
{
	for (int i = 0; i < m_Size; i++)
		classRosterArray[i]->Print();
}

void roster::printAverageDaysInCourse(const int& studentID)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (studentID == classRosterArray[i]->getStudentId())
		{
			student* selectedStudent = classRosterArray[i];
			int total = selectedStudent->getNumOfDaysLeft(0) + selectedStudent->getNumOfDaysLeft(1) + selectedStudent->getNumOfDaysLeft(2);
			std::cout << "average number of days left is " << total / 3 << "\n";
			m_Size--;
		}
		else
		{
			std::cout << "student not found in roster";
		}
	}
}

void roster::printInvalidEmails()
{
	std::vector<std::string> invalidEmails;
	invalidEmails.reserve(m_Size);
	bool invalid = false;
	for (int i = 0; i <= m_Size; i++)
	{
		const std::string& email = classRosterArray[i]->getEmailAddress();
		if (email.find(' ') < email.length())
		{
			invalidEmails.push_back(email);
			invalid = true;
			continue;
		}
		if (!(email.find('@') < email.length()))
		{
			invalidEmails.push_back(email);
			invalid = true;
			continue;
		}
		if (!(email.find('.') < email.length()))
		{
			invalidEmails.push_back(email);
 			invalid = true;
		}
	}
	if (invalid)
	{
		std::cout << "List of invalid emails:\n";
		for (std::string& email : invalidEmails)
			std::cout << email << "\n";
	}
	else
		std::cout << "All emails are valid.";
}

void roster::printByDegreeProgram(const DegreeProgram& degreeProgram)
{
	if (degreeProgram == SECURITY)
		std::cout << "Security\n";
	if (degreeProgram == NETWORK)
		std::cout << "Network\n";
	if (degreeProgram == SOFTWARE)
		std::cout << "Software\n";
	else
		std::cout << "invalid degree program\n";
}
