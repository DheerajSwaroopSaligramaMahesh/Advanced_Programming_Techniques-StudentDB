/*
 * BlockCourse.h
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>

#include "Course.h"

/**
 * @class BlockCourse
 * @brief Represents a block course with a fixed start and end date.
 *
 * A BlockCourse is a type of Course that runs for a fixed period between
 * a start date and an end date. It includes specific start and end times.
 */
class BlockCourse: public Course
{
private:
	/** @brief The start date of the course. */
	Poco::Data::Date startDate;

	/** @brief The end date of the course. */
	Poco::Data::Date endDate;

	/** @brief The start time of the course. */
	Poco::Data::Time startTime;

	/** @brief The end time of the course. */
	Poco::Data::Time endTime;

public:
	/**
	 * @brief Constructs a BlockCourse object.
	 * @param courseKey The unique course identifier.
	 * @param title The title of the course.
	 * @param major The major associated with the course.
	 * @param creditPoints The credit points awarded for the course.
	 * @param startDate The start date of the course.
	 * @param endDate The end date of the course.
	 * @param startTime The start time of the course.
	 * @param endTime The end time of the course.
	 */
	BlockCourse(unsigned int courseKey, std::string title, std::string major,
			float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	/**
	 * @brief Gets the start date of the course.
	 * @return The start date as a Poco::Data::Date object.
	 */
	Poco::Data::Date getStartDate() const;

	/**
	 * @brief Gets the end date of the course.
	 * @return The end date as a Poco::Data::Date object.
	 */
	Poco::Data::Date getEndDate() const;

	/**
	 * @brief Gets the start time of the course.
	 * @return The start time as a Poco::Data::Time object.
	 */
	Poco::Data::Time getStartTime() const;

	/**
	 * @brief Gets the end time of the course.
	 * @return The end time as a Poco::Data::Time object.
	 */
	Poco::Data::Time getEndTime() const;

	/**
	 * @brief Writes the BlockCourse data to an output stream.
	 * @param outFile The output stream to write to.
	 */
	void write(std::ostream &outFile) const override;
};

#endif /* BLOCKCOURSE_H_ */
