// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include "student.h"
#include "roster.h"

int main()
{
	roster classRoster;
	classRoster.add(2, "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, "Computer Science");
	classRoster.add(1, "Joshua", "Dorsett", "joshdorsett@gmail.com", 28, 55, 67, 88, "Computer Science");
	classRoster.remove(1);
	classRoster.PrintRoster();
	classRoster.printAverageDaysInCourse(2);

	return 0;
}