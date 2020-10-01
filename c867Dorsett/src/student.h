#pragma once
#include <string>
#include <array>
class student
{
private:
	int studentId;

	std::string firstName;

	std::string lastName;

	std::string emailAddress;

	int age;

	int numOfDaysLeft[3] = {0, 0, 0 };

	std::string degreeProgram;
	
public:
	//constructors
	student();
	student(const int& studentId, const std::string& firstName, const std::string& lastName, 
		const std::string& emailAddress, const int& age, const int& daysInCourse1, const int& daysInCourse2, 
		const int& daysInCourse3, const std::string& degreeProgram);
	//rule of fifths
	~student();
 	student(const student& copiedStudent); 	
	student& operator=(const student& copiedStudent);
// 	student(student&& copiedStudent);
// 	student& operator=(student&& copiedStudent) noexcept;
	//Print data
	void Print() const;
	//getters
	int getStudentId() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmailAddress() const;
	int getAge() const;
	//this currently returns just one day based on the index
	//may change this to return multiple values
	int getNumOfDaysLeft(const int& index) const;
	std::string getDegreeProgram() const;
	//setters
	void setStudentId(const int& id);
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string &lastName);
	void setEmailAddress(const std::string& emailAddress);
	void setAge(const int& age);
	//this currently sets each index one at a time but may change this to return multiple values in a tuple?
	void setNumOfDaysLeft(const int& courseOne, const int& courseTwo, const int& courseThree);
	void setDegreeProgram(const std::string& degreeProgram);

};

