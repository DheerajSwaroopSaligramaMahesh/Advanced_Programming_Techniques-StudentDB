/*
 * Student.h
 *
 *  Created on: 07-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <vector>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>

#include "Enrollment.h"
#include "Address.h"

/**
 * @class Student
 * @brief Represents a student with personal details, address, and course enrollments.
 */
class Student
{
private:
	/** @brief Static variable to track the next available Matrikel number. */
	static unsigned int nextMatrikelNumber;

	/** @brief Unique Matrikel number assigned to the student. */
	unsigned int matrikelNumber;

	/** @brief First name of the student. */
	std::string firstName;

	/** @brief Last name of the student. */
	std::string lastName;

	/** @brief Date of birth of the student. */
	Poco::Data::Date dateOfBirth;

	/** @brief Address of the student. */
	Address address;

	/** @brief List of enrollments representing the student's registered courses. */
	std::vector<Enrollment> enrollments;

public:
	/**
	 * @brief Constructs a Student object with the given personal details and address.
	 * @param firstName First name of the student.
	 * @param lastName Last name of the student.
	 * @param dateOfBirth Date of birth of the student.
	 * @param street Street address of the student.
	 * @param postalCode Postal code of the student's residence.
	 * @param cityName City name of the student's residence.
	 * @param additionalInfo Additional address information.
	 */
	Student(std::string firstName, std::string lastName,
			Poco::Data::Date dateOfBirth, std::string street,
			unsigned short postalCode, std::string cityName,
			std::string additionalInfo);

	/**
	 * @brief Gets the student's Matrikel number.
	 * @return The Matrikel number.
	 */
	unsigned int getMatrikelNumber() const;

	/**
	 * @brief Gets the student's first name.
	 * @return The first name.
	 */
	std::string getFirstName() const;

	/**
	 * @brief Gets the student's last name.
	 * @return The last name.
	 */
	std::string getLastName() const;

	/**
	 * @brief Gets the student's date of birth.
	 * @return The date of birth.
	 */
	Poco::Data::Date getDateOfBirth() const;

	/**
	 * @brief Gets the student's address.
	 * @return The address object.
	 */
	Address getAddress() const;

	/**
	 * @brief Gets the list of enrollments for the student.
	 * @return A vector of Enrollment objects.
	 */
	std::vector<Enrollment> getEnrollments() const;

	/**
	 * @brief Adds a new enrollment for the student.
	 * @param newEnrollment The Enrollment object to be added.
	 */
	void setEnrollments(Enrollment &newEnrollment);

	/**
	 * @brief Sets the student's first name.
	 * @param firstName The new first name.
	 */
	void setFirstName(std::string firstName);

	/**
	 * @brief Sets the student's last name.
	 * @param lastName The new last name.
	 */
	void setLastName(std::string lastName);

	/**
	 * @brief Sets the student's date of birth.
	 * @param dateOfBirth The new date of birth.
	 */
	void setDateOfBirth(Poco::Data::Date dateOfBirth);

	/**
	 * @brief Sets the student's address details.
	 * @param street The street address.
	 * @param postalCode The postal code.
	 * @param cityName The city name.
	 * @param additionalInfo Additional address information.
	 */
	void setAddress(std::string street, unsigned short postalCode,
			std::string cityName, std::string additionalInfo);

	/**
	 * @brief Deletes an enrollment from the student's records based on the course key.
	 * @param courseKey The unique identifier for the course to be removed.
	 */
	void deleteEnrollment(unsigned int courseKey);

	/**
	 * @brief Updates the grade of a specific enrollment for the student.
	 * @param courseKey The unique identifier for the course.
	 * @param grade The new grade to be assigned.
	 */
	void updateGrade(unsigned int courseKey, float grade);

	/**
	 * @brief Writes the student's details to an output stream.
	 * @param outFile The output stream where the data will be written.
	 */
	void write(std::ostream &outFile) const;
};

#endif /* STUDENT_H_ */
