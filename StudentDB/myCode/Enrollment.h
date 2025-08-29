/*
 * Enrollment.h
 *
 *  Created on: 07-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <string>

#include "Course.h"

/**
 * @class Enrollment
 * @brief Represents a student's enrollment in a course, including grade and semester details.
 *
 * This class stores details of a student's enrollment, including the course,
 * the semester in which they enrolled, and their grade.
 */
class Enrollment
{
private:
	/** @brief The grade awarded for the course. */
	float grade;

	/** @brief The semester in which the student enrolled in the course. */
	std::string semester;

	/** @brief Pointer to the Course object representing the enrolled course. */
	Course *course;

public:
	/**
	 * @brief Constructs an Enrollment object.
	 * @param semester The semester in which the student is enrolled.
	 * @param course Pointer to the course in which the student is enrolled.
	 */
	Enrollment(std::string semester, Course *course);

	/**
	 * @brief Gets the student's grade.
	 * @return The grade as a float.
	 */
	float getGrade();

	/**
	 * @brief Gets the semester of enrollment.
	 * @return The semester as a std::string.
	 */
	std::string getSemester() const;

	/**
	 * @brief Gets the course in which the student is enrolled.
	 * @return A pointer to the Course object.
	 */
	Course* getCourse() const;

	/**
	 * @brief Sets the student's grade for the course.
	 * @param grade The grade to be assigned.
	 */
	void setGrade(float grade);

	/**
	 * @brief Writes the enrollment details to an output stream.
	 *
	 * Outputs the enrollment details, including the student's matriculation number,
	 * course key, semester, and grade.
	 *
	 * @param matrikelNumber The student's matriculation number.
	 * @param outFile The output stream to write to.
	 */
	void write(unsigned int matrikelNumber, std::ostream &outFile) const;
};

#endif /* ENROLLMENT_H_ */
