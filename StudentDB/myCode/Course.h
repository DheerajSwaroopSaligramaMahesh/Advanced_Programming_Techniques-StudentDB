/*
 * Course.h
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <string>

/**
 * @class Course
 * @brief Represents a generic course with a unique key, title, major, and credit points.
 *
 * This is an abstract base class for different types of courses. It stores
 * general course details such as title, major, and credit points. The `write`
 * function is a virtual method meant to be overridden by derived classes.
 */
class Course
{
private:
	/** @brief Maps major IDs to major names. */
	static std::map<unsigned char, std::string> majorById;

	/** @brief Unique identifier for the course. */
	unsigned int courseKey;

	/** @brief Title of the course. */
	std::string title;

	/** @brief Major associated with the course, stored as an ID. */
	unsigned char major;

	/** @brief Credit points awarded for completing the course. */
	float creditPoints;

public:
	/**
	 * @brief Constructs a Course object.
	 * @param courseKey The unique course identifier.
	 * @param title The title of the course.
	 * @param major The major associated with the course.
	 * @param creditPoints The credit points assigned to the course.
	 */
	Course(unsigned int courseKey, std::string title, std::string major,
			float creditPoints);

	/**
	 * @brief Gets the unique course key.
	 * @return The course key as an unsigned integer.
	 */
	unsigned int getCourseKey() const;

	/**
	 * @brief Gets the title of the course.
	 * @return The title as a std::string.
	 */
	std::string getTitle() const;

	/**
	 * @brief Gets the major of the course.
	 * @return The major as a std::string.
	 */
	std::string getMajor() const;

	/**
	 * @brief Gets the credit points of the course.
	 * @return The credit points as a float.
	 */
	float getCreditPoints() const;

	/**
	 * @brief Writes the course data to an output stream.
	 *
	 * This method is meant to be overridden by derived classes.
	 * @param outFile The output stream to write to.
	 */
	virtual void write(std::ostream &outFile) const;

	/**
	 * @brief Virtual destructor to ensure proper cleanup in derived classes.
	 */
	virtual ~Course() = 0;
};

#endif /* COURSE_H_ */
