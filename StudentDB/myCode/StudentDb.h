/*
 * StudentDb.h
 *
 *  Created on: 07-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include <map>
#include <memory>

#include "Student.h"
#include "Course.h"

/**
 * @class StudentDb
 * @brief Manages student and course records, allowing modifications, enrollments, and queries.
 */
class StudentDb
{
private:
	/** @brief A map storing students using Matrikel number as the key. */
	std::map<int, Student> students;

	/** @brief A map storing courses using course key as the key, with unique ownership. */
	std::map<int, std::unique_ptr<const Course>> courses;

public:
	/**
	 * @brief Constructs an empty StudentDb object.
	 */
	StudentDb();

	/**
	 * @brief Retrieves the list of courses.
	 * @return A reference to a map containing course keys and corresponding courses.
	 */
	std::map<int, std::unique_ptr<const Course>>& getCourses();

	/**
	 * @brief Adds a new student to the database.
	 * @param firstName First name of the student.
	 * @param lastName Last name of the student.
	 * @param dateOfBirth Date of birth of the student.
	 * @param street Street address of the student.
	 * @param postalCode Postal code of the student's residence.
	 * @param cityName City name of the student's residence.
	 * @param additionalInfo Additional address details.
	 */
	void addStudent(std::string firstName, std::string lastName,
			Poco::Data::Date dateOfBirth, std::string street,
			unsigned short postalCode, std::string cityName,
			std::string additionalInfo);

	/**
	 * @brief Adds a new block course to the database.
	 * @param courseKey Unique identifier for the course.
	 * @param title Course title.
	 * @param major Major subject of the course.
	 * @param creditPoints Credit points for the course.
	 * @param startDate Start date of the course.
	 * @param endDate End date of the course.
	 * @param startTime Start time of the course.
	 * @param endTime End time of the course.
	 */
	void addBlockCourse(unsigned int courseKey, std::string title,
			std::string major, float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	/**
	 * @brief Adds a new weekly course to the database.
	 * @param courseKey Unique identifier for the course.
	 * @param title Course title.
	 * @param major Major subject of the course.
	 * @param creditPoints Credit points for the course.
	 * @param dayOfWeek Day of the week the course takes place.
	 * @param startTime Start time of the course.
	 * @param endTime End time of the course.
	 */
	void addWeeklyCourse(unsigned int courseKey, std::string title,
			std::string major, float creditPoints,
			Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	/**
	 * @brief Enrolls a student in a course.
	 * @param matrikelNumber Matrikel number of the student.
	 * @param courseKey Unique identifier for the course.
	 * @param semester Semester of enrollment.
	 */
	void addEnrollment(unsigned int matrikelNumber, unsigned int courseKey,
			std::string semester);

	/**
	 * @brief Retrieves the list of students.
	 * @return A map of students indexed by Matrikel number.
	 */
	std::map<int, Student> getStudents();

	/**
	 * @brief Checks if a Matrikel number exists in the database.
	 * @param matrikelNumber The Matrikel number to check.
	 * @return True if the Matrikel number exists, false otherwise.
	 */
	bool matrikelNumberExists(int matrikelNumber);

	/**
	 * @brief Updates a student's name.
	 * @param matrikelNumber Matrikel number of the student.
	 * @param firstName New first name.
	 * @param lastName New last name.
	 */
	void updateName(unsigned int matrikelNumber, std::string firstName,
			std::string lastName);

	/**
	 * @brief Updates a student's date of birth.
	 * @param matrikelNumber Matrikel number of the student.
	 * @param dateOfBirth New date of birth.
	 */
	void updateDateOfBirth(unsigned int matrikelNumber,
			Poco::Data::Date dateOfBirth);

	/**
	 * @brief Updates a student's address.
	 * @param matrikelNumber Matrikel number of the student.
	 * @param street New street address.
	 * @param postalCode New postal code.
	 * @param cityName New city name.
	 * @param additionalInfo Additional address details.
	 */
	void updateAddress(unsigned int matrikelNumber, std::string street,
			unsigned short postalCode, std::string cityName,
			std::string additionalInfo);

	/**
	 * @brief Checks if a course exists in the database.
	 * @param courseKey Unique identifier for the course.
	 * @return True if the course exists, false otherwise.
	 */
	bool courseExists(unsigned int courseKey);

	/**
	 * @brief Removes an enrollment from a student's record.
	 * @param matrikelNumber Matrikel number of the student.
	 * @param courseKey Unique identifier for the course.
	 */
	void deleteEnrollment(unsigned int matrikelNumber, unsigned int courseKey);

	/**
	 * @brief Updates a student's grade for a specific course.
	 * @param matrikelNumber Matrikel number of the student.
	 * @param courseKey Unique identifier for the course.
	 * @param grade New grade to assign.
	 */
	void updateGrade(unsigned int matrikelNumber, unsigned int courseKey,
			float grade);

	/**
	 * @brief Writes all student and course data to an output stream.
	 * @param outFile The output stream to write to.
	 */
	void write(std::ostream &outFile) const;
};

#endif /* STUDENTDB_H_ */
