/*
 * Enrollment.cpp
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include "Enrollment.h"

Enrollment::Enrollment(std::string semester, Course *course) :
		grade(0.0f), semester(semester), course(course)
{
}

float Enrollment::getGrade()
{
	return grade;
}

std::string Enrollment::getSemester() const
{
	return semester;
}

Course* Enrollment::getCourse() const
{
	return course;
}

void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

void Enrollment::write(unsigned int matrikelNumber, std::ostream &outFile) const
{
	outFile << matrikelNumber << ";" << course->getCourseKey() << ";"
			<< semester << ";" << grade;
}
