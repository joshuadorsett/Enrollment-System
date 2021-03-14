#include "roster.h"

//constructor
roster::roster()
{
	for (auto& i : classRosterArray)
    {
	    i = nullptr;
    }
}

//adds student to roster.
void roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress,
	const int& age, const int& daysInCourse1, const int& daysInCourse2, const int& daysInCourse3, const DegreeProgram& degreeprogram)
{
	std::vector<int> temp{ daysInCourse1, daysInCourse2, daysInCourse3 };
	
 	auto newStudent = std::make_shared<student>(studentID, firstName, lastName,emailAddress, age, temp, degreeprogram);
 	
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
			
			classRosterArray.erase(classRosterArray.begin() + i);
			
			return;
		}
		
	}
	std::cout << "student not found in roster.\n-----------------------\n";
}

//gets the size of the roster
int roster::getSize() const
{
	return static_cast<int>(classRosterArray.size());
}

//returns the pointer to the array of students.
std::shared_ptr<student> roster::getRoster(const int& index) const
{
	return classRosterArray.at((unsigned long) index);
}

//calls student.print() function for each student in roster.
void roster::printRoster() const
{
	for (const auto& student : classRosterArray)
    {
	    student->Print();
    }
}

//prints average days left for courses by student ID
void roster::printAverageDaysInCourse(const std::string& studentID)
{
	for (auto & student : classRosterArray)
	{
		if (studentID == student->getStudentId())
		{
			int total =
			        student->getNumOfDaysLeft(0) +
			        student->getNumOfDaysLeft(1) +
			        student->getNumOfDaysLeft(2);
			
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
	
	for (auto & student : classRosterArray)
	{
        auto email = student->getEmailAddress();
        
		if (email.size() > email.find(' '))
		{
			invalidEmails.push_back(email);
			invalid = true;
			continue;
		}
		if (email.size() <= email.find('@'))
		{
			invalidEmails.push_back(email);
			invalid = true;
			continue;
		}
		if (email.size() <= email.find('.'))
		{
			invalidEmails.push_back(email);
 			invalid = true;
		}
	}
	if (invalid)
	{
		std::cout << "List of invalid emails:\n";
		
		for (std::string& email : invalidEmails)
        {
		    std::cout << email << "\n";
        }
		
		std::cout << "-----------------------\n";
	}
	else
    {
	    std::cout << "All emails are valid.\n-----------------------\n";
    }
}

//prints the degree program associated with appropriate enum value.
void roster::printByDegreeProgram(const DegreeProgram& degreeProgram)
{
	if (degreeProgram == SECURITY)
    {
	    std::cout << "Security\n-----------------------\n";
    }
	if (degreeProgram == NETWORK)
    {
	    std::cout << "Network\n-----------------------\n";
    }
	if (degreeProgram == SOFTWARE)
    {
        std::cout << "Software\n-----------------------\n";
    }
	else
    {
	    std::cout << "invalid degree program\n-----------------------\n";
    }
}
