#pragma once
// an enum of the 3 types of degree programs
// used an unsigned char to save memory since all values are less than 8 bits
enum DegreeProgram : unsigned char
{
	SECURITY, NETWORK, SOFTWARE, UNDECIDED
};