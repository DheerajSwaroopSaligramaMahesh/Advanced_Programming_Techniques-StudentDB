/*
 * Course.cpp
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */
#include <iostream>
#include "Course.h"

std::map<unsigned char, std::string> Course::majorById =
{
{ 'A', "Automation" },
{ 'C', "Communication" },
{ 'E', "Embedded" },
{ 'P', "Power" } };

Course::Course(unsigned int courseKey, std::string title, std::string major,
		float creditPoints) :
		courseKey(courseKey), title(title), creditPoints(creditPoints)
{
	for (const auto &pair : majorById)
	{
		if (pair.second == major)
		{
			this->major = pair.first;
		}
	}
}

unsigned int Course::getCourseKey() const
{
	return courseKey;
}

std::string Course::getTitle() const
{
	return title;
}

std::string Course::getMajor() const
{
	return majorById[major];
}

float Course::getCreditPoints() const
{
	return creditPoints;
}

void Course::write(std::ostream &outFile) const
{
	outFile << courseKey << ";" << title << ";" << getMajor() << ";" << creditPoints
			<< ";";
}

Course::~Course()
{
}

