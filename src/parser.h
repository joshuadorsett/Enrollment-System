//
// Created by Joshua Dorsett on 3/14/21.
//

#pragma once

#include <sstream>

namespace parser
{
    DegreeProgram degreeProgramChoices(std::string const &degreeProgramString)
    {
        if (degreeProgramString == "SOFTWARE")
        {
            return SOFTWARE;
        }
        if (degreeProgramString == "NETWORK")
        {
            return NETWORK;
        }
        if (degreeProgramString == "SECURITY")
        {
            return SECURITY;
        }
        return UNDECIDED;
    }
    
    void resultTypeConversion(std::vector<std::string> &result, std::string &id,
                              std::string &firstName, std::string &lastName, std::string &email,
                              int &age, int &courseOne, int &courseTwo, int &courseThree, DegreeProgram &degreeProgram)
    {
        id = result.at(0);
        firstName = result.at(1);
        lastName = result.at(2);
        email = result.at(3);
        std::string ageString = result.at(4);
        std::istringstream(ageString) >> age;
        std::string courseOneString = result.at(5);
        std::istringstream(courseOneString) >> courseOne;
        std::string courseTwoString = result.at(6);
        std::istringstream(courseTwoString) >> courseTwo;
        std::string courseThreeString = result.at(7);
        std::istringstream(courseThreeString) >> courseThree;
        std::string degreeProgramString = result.at(8);
        degreeProgram = degreeProgramChoices(degreeProgramString);
    }

// the definition for function that inputs tabe into roster
    void inputParser(std::vector<std::string> studentData, roster &classRoster)
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
            std::string id, firstName, lastName, email;
            int age, courseOne, courseTwo, courseThree;
            DegreeProgram degreeProgram;
            
            resultTypeConversion(result, id, firstName, lastName, email, age, courseOne, courseTwo, courseThree,
                                 degreeProgram);
            
            //adds data into roster for each student
            classRoster.add(id, firstName, lastName, email, age, courseOne, courseTwo, courseThree, degreeProgram);
            
        }
        //starts over for next student in the loop or ends function if complete.
    }
}
