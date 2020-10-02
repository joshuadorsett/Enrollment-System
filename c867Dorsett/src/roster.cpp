#include "roster.h"
#include <vector>
#include <xutility>
#include <string>

//constructor
roster::roster()
{
	for (auto& i : classRosterArray)
		i = nullptr;
}
//destructor
roster::~roster()
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
		delete classRosterArray.at(i);
}
void roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress,
	const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram)
{
 	student* newStudent = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	classRosterArray.push_back(newStudent);
}
void roster::remove(const std::string& studentID)
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
	{
		if (studentID == classRosterArray.at(i)->getStudentId())
		{
			std::cout << classRosterArray[i]->getStudentId() << " has been deleted.\n-----------------------\n";
			delete classRosterArray.at(i);
			classRosterArray.erase(classRosterArray.begin() + i);
			return;
		}
		
	}
	std::cout << "student not found in roster.\n-----------------------\n";
}

int roster::getSize() const
{
	return classRosterArray.size();
}

student* roster::getRoster(const int& index) const
{
	return classRosterArray.at(index);
}

void roster::printRoster() const
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
		classRosterArray.at(i)->Print();
}

void roster::printAverageDaysInCourse(const std::string& studentID)
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
	{
		if (studentID == classRosterArray.at(i)->getStudentId())
		{
			student* selectedStudent = classRosterArray.at(i);
			int total = selectedStudent->getNumOfDaysLeft(0) + selectedStudent->getNumOfDaysLeft(1) + selectedStudent->getNumOfDaysLeft(2);
			std::cout << "average number of days left is " << total / 3 << "\n-----------------------\n";
			return;
		}
	}
	std::cout << "student not found in roster\n-----------------------\n";
}

void roster::printInvalidEmails()
{
	std::vector<std::string> invalidEmails;
	invalidEmails.reserve(classRosterArray.size());
	bool invalid = false;
	std::string email;
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		email = classRosterArray.at(i)->getEmailAddress();
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
		std::cout << "-----------------------\n";
	}
	else
		std::cout << "All emails are valid.\n-----------------------\n";
}

void roster::printByDegreeProgram(const DegreeProgram& degreeProgram)
{
	if (degreeProgram == SECURITY)
		std::cout << "Security\n-----------------------\n";
	if (degreeProgram == NETWORK)
		std::cout << "Network\n-----------------------\n";
	if (degreeProgram == SOFTWARE)
		std::cout << "Software\n-----------------------\n";
	else
		std::cout << "invalid degree program\n-----------------------\n";
}
