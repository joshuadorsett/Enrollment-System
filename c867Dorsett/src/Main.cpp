#include <iostream>
#include "student.h"
#include "roster.h"
#include <iosfwd>
#include <string>
#include<sstream>
#include <vector>
#include "degree.h"
	// A function to parse input data and add into roster.
void inputParser(const std::string studentData[5], roster& classRoster);

int main()
{
	//The input data provided.
	const std::string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Joshua,Dorsett,joshdorsett@gmail.com,28, 18,19,18,SOFTWARE" };
	
	//declared roster object for students to enroll into.
	roster classRoster;
	
	//called the input parser function to input student data into roster.
	inputParser(studentData, classRoster);

	//outputs project information
	std::cout << "Scripting and Programming - Applications C867\nC++\njdors43\nJoshua Dorsett\n-----------------------\n";

	//prints the current roster.
	classRoster.printRoster();

	//prints list of invalid emails.
 	classRoster.printInvalidEmails();

	// loops through roster and prints average days in courses left for each student.
	for (int i = 0; i < classRoster.getSize(); i++)
	{
		std::cout << "Student " << classRoster.getRoster(i)->getStudentId() << ": ";
		classRoster.printAverageDaysInCourse(classRoster.getRoster(i)->getStudentId());
	}

	//prints the degree program for enum SOFTWARE.
 	classRoster.printByDegreeProgram(SOFTWARE);

	//removes student A3 from roster.
	classRoster.remove("A3");

	//prints updated roster.
	classRoster.printRoster();

	//tries to remove student A3 again but this student is not in roster.
  	classRoster.remove("A3");

	//closes main function.
	return 0;
}

// the definition for function that inputs tabe into roster
void inputParser( const std::string studentData[5],  roster& classRoster)
{
	//loops through student data array
	for (int i = 0; i < 5; i++)
	{
		//makes a vector to hold each section of the string that will be split.
		std::vector<std::string> result;
		//makes a string stream object with the current string.
		std::stringstream stringStream(studentData[i]);

		//loops through the stream and splits it up by commas.
		while (stringStream.good())
		{
			std::string subString;
			std::getline(stringStream, subString, ',');
			result.push_back(subString);
		}

		//converts the results into the appropriate data types for adding into roster object.
		std::string id = result.at(0);
		std::string fisrtName = result.at(1);
		std::string lastName = result.at(2);
		std::string email = result.at(3);
		int age;
		std::string ageString = result.at(4);
		std::istringstream(ageString) >> age;
		int courseOne;
		std::string courseOneString = result.at(5);
		std::istringstream(courseOneString) >> courseOne;
		int courseTwo;
		std::string courseTwoString = result.at(6);
		std::istringstream(courseTwoString) >> courseTwo;
		int courseThree;
		std::string courseThreeString = result.at(7);
		std::istringstream(courseThreeString) >> courseThree;
		DegreeProgram degreeProgram;
		std::string degreeProgramString = result.at(8);
		if (degreeProgramString == "SOFTWARE")
			degreeProgram = SOFTWARE;
		if (degreeProgramString == "NETWORK")
			degreeProgram = NETWORK;
		if (degreeProgramString == "SECURITY")
			degreeProgram = SECURITY;

		//adds data into roster for each student
		classRoster.add(id, fisrtName, lastName, email, age, courseOne, courseTwo, courseThree, degreeProgram);

	}
	//starts over for next student in the loop or ends function if complete.
}