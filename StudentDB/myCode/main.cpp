#include <iostream>
#include <cstdlib>

#include "Course.h"
#include "Student.h"
#include "StudentDb.h"
#include "SimpleUI.h"

// Main program
int main()
{
	// TODO: Add your program code here
	std::cout << "StudentDB started." << std::endl << std::endl;

	StudentDb db;
	SimpleUI simpleUI(db);

	simpleUI.run();

	return 0;
}
