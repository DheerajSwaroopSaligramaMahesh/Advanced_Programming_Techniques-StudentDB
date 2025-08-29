/*
 * SimpleUI.h
 *
 *  Created on: 07-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include "StudentDb.h"

/**
 * @class SimpleUI
 * @brief Provides a simple command-line interface for managing student data and courses.
 *
 * The SimpleUI class interacts with the StudentDb to add and manage courses, students,
 * and enrollments. It also provides utilities for date and time conversions.
 */
class SimpleUI
{
private:
	/** @brief Reference to the StudentDb object managing student and course data. */
	StudentDb &db;

public:
	/**
	 * @brief Constructs a SimpleUI object.
	 * @param db Reference to the StudentDb object.
	 */
	SimpleUI(StudentDb &db);

	/**
	 * @brief Runs the user interface, allowing interaction with the database.
	 */
	void run();

	/**
	 * @brief Converts a string to a Poco::Data::Date object.
	 * @param dateString The date in string format (YYYY-MM-DD).
	 * @return A Poco::Data::Date object.
	 */
	Poco::Data::Date stringToDate(std::string dateString);

	/**
	 * @brief Converts a string to a Poco::Data::Time object.
	 * @param timeString The time in string format (HH:MM:SS).
	 * @return A Poco::Data::Time object.
	 */
	Poco::Data::Time stringToTime(std::string timeString);

	/**
	 * @brief Converts a string representing a day of the week to a Poco::DateTime::DaysOfWeek value.
	 * @param dayOfWeekString The day of the week as a string (e.g., "Monday").
	 * @return The corresponding Poco::DateTime::DaysOfWeek enumeration value.
	 */
	Poco::DateTime::DaysOfWeek convertDay(std::string dayOfWeekString);

	/**
	 * @brief Prompts the user to add a new course to the database.
	 */
	void addNewCourse();

	/**
	 * @brief Prompts the user to add a new student to the database.
	 */
	void addNewStudent();

	/**
	 * @brief Prompts the user to enroll a student in a course.
	 */
	void addEnrollment();

	/**
	 * @brief Lists all available courses in the database.
	 */
	void listCourses();

	/**
	 * @brief Prints details of a student based on user input.
	 */
	void printStudent();

	/**
	 * @brief Searches for a student in the database based on user input.
	 */
	void searchStudent();

	/**
	 * @brief Updates student details in the database.
	 */
	void updateStudent();

	/**
	 * @brief Writes all student and course data to a file.
	 */
	void writeToFile() const;
};

#endif /* SIMPLEUI_H_ */
