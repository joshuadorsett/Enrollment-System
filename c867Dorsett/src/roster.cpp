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

//adds student to roster.
void roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress,
	const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram)
{
	int temp[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
 	student* newStudent = new student(studentID, firstName, lastName,emailAddress, age, temp, degreeprogram);
	classRosterArray.push_back(newStudent);
}

//removes student from roster.
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

//gets the size of the roster
int roster::getSize() const
{
	return classRosterArray.size();
}

//returns the pointer to the array of students.
student* roster::getRoster(const int& index) const
{
	return classRosterArray.at(index);
}

//calls student.print() function for each student in roster.
void roster::printRoster() const
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
		classRosterArray.at(i)->Print();
}

//prints average days left for courses by student ID
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

//prints a list of emails that are not valid according to email rules
void roster::printInvalidEmails()
{
	std::vector<std::string> invalidEmails;
	invalidEmails.reserve(classRosterArray.size());
	bool invalid = false;
	std::string email;
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
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

//prints the degree program associated with appropriate enum value.
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
