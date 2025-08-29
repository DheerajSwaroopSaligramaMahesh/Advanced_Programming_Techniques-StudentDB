/*
 * StudentDb.cpp
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>

#include "StudentDb.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"

StudentDb::StudentDb()
{
}

std::map<int, std::unique_ptr<const Course> >& StudentDb::getCourses()
{
	return courses;
}

void StudentDb::addStudent(std::string firstName, std::string lastName,
		Poco::Data::Date dateOfBirth, std::string street,
		unsigned short postalCode, std::string cityName,
		std::string additionalInfo)
{
	Student student(firstName, lastName, dateOfBirth, street, postalCode,
			cityName, additionalInfo);
	students.insert(std::make_pair(student.getMatrikelNumber(), student));
}

void StudentDb::addBlockCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime)
{
	BlockCourse blockCourse(courseKey, title, major, creditPoints, startDate,
			endDate, startTime, endTime);
	courses[courseKey] = std::make_unique<const BlockCourse>(blockCourse);
}

void StudentDb::addWeeklyCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints,
		Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime)
{
	WeeklyCourse weeklyCourse(courseKey, title, major, creditPoints, dayOfWeek,
			startTime, endTime);
	courses[courseKey] = std::make_unique<const WeeklyCourse>(weeklyCourse);
}

void StudentDb::addEnrollment(unsigned int matrikelNumber,
		unsigned int courseKey, std::string semester)
{
	auto &course = courses.at(courseKey);
	Enrollment newEnrollment(semester, const_cast<Course*>(course.get()));
	students.at(matrikelNumber).setEnrollments(newEnrollment);
}

std::map<int, Student> StudentDb::getStudents()
{
	return students;
}

bool StudentDb::matrikelNumberExists(int matrikelNumber)
{
	if (students.find(matrikelNumber) != students.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StudentDb::updateName(unsigned int matrikelNumber, std::string firstName,
		std::string lastName)
{
	students.at(matrikelNumber).setFirstName(firstName);
	students.at(matrikelNumber).setLastName(lastName);
}

void StudentDb::updateDateOfBirth(unsigned int matrikelNumber,
		Poco::Data::Date dateOfBirth)
{
	students.at(matrikelNumber).setDateOfBirth(dateOfBirth);
}

void StudentDb::updateAddress(unsigned int matrikelNumber, std::string street,
		unsigned short postalCode, std::string cityName,
		std::string additionalInfo)
{
	students.at(matrikelNumber).setAddress(street, postalCode, cityName,
			additionalInfo);
}

bool StudentDb::courseExists(unsigned int courseKey)
{
	if (courses.find(courseKey) != courses.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StudentDb::deleteEnrollment(unsigned int matrikelNumber,
		unsigned int courseKey)
{
	students.at(matrikelNumber).deleteEnrollment(courseKey);
}

void StudentDb::updateGrade(unsigned int matrikelNumber, unsigned int courseKey,
		float grade)
{
	students.at(matrikelNumber).updateGrade(courseKey, grade);
}

void StudentDb::write(std::ostream &outFile) const
{
	outFile << courses.size() << std::endl;
	for (const auto &course : courses)
	{
		course.second->write(outFile);
	}
	outFile << students.size() << std::endl;
	for (const auto &student : students)
	{
		student.second.write(outFile);
	}
	for (const auto &student : students)
	{
		auto enrollments = student.second.getEnrollments();
		unsigned int matrikelNumber = student.first;
		for (const auto &enrollment : enrollments)
		{
			outFile << enrollments.size() << std::endl;
			enrollment.write(matrikelNumber, outFile);
		}
	}
}
