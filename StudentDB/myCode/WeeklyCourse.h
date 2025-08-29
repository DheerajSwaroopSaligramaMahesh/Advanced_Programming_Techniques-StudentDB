/*
 * WeeklyCourse.h
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include <Poco/Data/Time.h>

#include "Course.h"

/**
 * @class WeeklyCourse
 * @brief Represents a course that takes place on a specific day of the week at a fixed time.
 */
class WeeklyCourse: public Course
{
private:
	/** @brief The day of the week when the course is held. */
	Poco::DateTime::DaysOfWeek dayOfWeek;

	/** @brief The start time of the course. */
	Poco::Data::Time startTime;

	/** @brief The end time of the course. */
	Poco::Data::Time endTime;

public:
	/**
	 * @brief Constructs a WeeklyCourse object.
	 * @param courseKey Unique identifier for the course.
	 * @param title Course title.
	 * @param major Major subject of the course.
	 * @param creditPoints Credit points for the course.
	 * @param dayOfWeek Day of the week the course is scheduled.
	 * @param startTime Start time of the course.
	 * @param endTime End time of the course.
	 */
	WeeklyCourse(unsigned int courseKey, std::string title, std::string major,
			float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
			Poco::Data::Time startTime, Poco::Data::Time endTime);

	/**
	 * @brief Retrieves the day of the week for the course.
	 * @return The day of the week when the course is held.
	 */
	Poco::DateTime::DaysOfWeek getDayOfWeek() const;

	/**
	 * @brief Retrieves the start time of the course.
	 * @return The start time.
	 */
	Poco::Data::Time getStartTime() const;

	/**
	 * @brief Retrieves the end time of the course.
	 * @return The end time.
	 */
	Poco::Data::Time getEndTime() const;

	/**
	 * @brief Writes course details to an output stream.
	 * @param outFile The output stream to write to.
	 */
	void write(std::ostream &outFile) const override;
};

#endif /* WEEKLYCOURSE_H_ */
