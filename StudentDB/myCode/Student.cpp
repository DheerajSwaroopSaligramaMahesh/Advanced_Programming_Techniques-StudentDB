/*
 * Student.cpp
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include "Student.h"

unsigned int Student::nextMatrikelNumber = 100000;

Student::Student(std::string firstName, std::string lastName,
		Poco::Data::Date dateOfBirth, std::string street,
		unsigned short postalCode, std::string cityName,
		std::string additionalInfo) :
		firstName(firstName), lastName(lastName), dateOfBirth(dateOfBirth), address(
				street, postalCode, cityName, additionalInfo)
{
	matrikelNumber = nextMatrikelNumber;
	nextMatrikelNumber++;
}

unsigned int Student::getMatrikelNumber() const
{
	return matrikelNumber;
}

std::string Student::getFirstName() const
{
	return firstName;
}

std::string Student::getLastName() const
{
	return lastName;
}

Poco::Data::Date Student::getDateOfBirth() const
{
	return dateOfBirth;
}

Address Student::getAddress() const
{
	return address;
}

std::vector<Enrollment> Student::getEnrollments() const
{
	return enrollments;
}

void Student::setEnrollments(Enrollment &newEnrollment)
{
	enrollments.push_back(newEnrollment);
}

void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Student::setDateOfBirth(Poco::Data::Date dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

void Student::setAddress(std::string street, unsigned short postalCode,
		std::string cityName, std::string additionalInfo)
{
	this->address = Address(street, postalCode, cityName, additionalInfo);
}

void Student::deleteEnrollment(unsigned int courseKey)
{
	for (auto it = enrollments.begin(); it != enrollments.end(); it++)
	{
		if (it->getCourse()->getCourseKey() == courseKey)
		{
			enrollments.erase(it);
			return;
		}
	}
}

void Student::updateGrade(unsigned int courseKey, float grade)
{
	for (auto &enrollment : enrollments)
	{
		if (enrollment.getCourse()->getCourseKey() == courseKey)
		{
			enrollment.setGrade(grade);
		}
	}
}

void Student::write(std::ostream &outFile) const
{
	outFile << matrikelNumber << ";" << firstName << ";" << lastName << ";"
			<< dateOfBirth.day() << "." << dateOfBirth.month() << "."
			<< dateOfBirth.year() << ";";
	address.write(outFile);
}
