#include <iostream>
#include "student.h"
#include "roster.h"
#include "parser.h"

int main()
{
    //input data provided.
    const std::vector<std::string> studentData =
            {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Joshua,Jackson,joshjackson@gmail.com,28,18,19,18,SOFTWARE"
            };
    
    //declared roster object for students to enroll into.
    roster classRoster;
    
    //called the input parser function to input student data into roster.
    parser::inputParser(studentData, classRoster);
    
    //outputs project information
    std::cout << "Student Enrollment System\nJoshua Dorsett\n-----------------------\n";
    
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
    roster::printByDegreeProgram(SOFTWARE);
    
    //removes student A3 from roster.
    classRoster.remove("A3");
    
    //prints updated roster.
    classRoster.printRoster();
    
    //tries to remove student A3 again but this student is not in roster.
    classRoster.remove("A3");
    
    //closes main function.
    return 0;
}

