/*
 * BlockCourse.cpp
 *
 *  Created on: 15-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */
#include <iostream>
#include "BlockCourse.h"

BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime) :
		Course(courseKey, title, major, creditPoints), startDate(startDate), endDate(
				endDate), startTime(startTime), endTime(endTime)
{
}

Poco::Data::Date BlockCourse::getStartDate() const
{
	return startDate;
}

Poco::Data::Date BlockCourse::getEndDate() const
{
	return endDate;
}

Poco::Data::Time BlockCourse::getStartTime() const
{
	return startTime;
}

Poco::Data::Time BlockCourse::getEndTime() const
{
	return endTime;
}

void BlockCourse::write(std::ostream &outFile) const
{
	outFile << "B;";
	Course::write(outFile);
	outFile << startDate.day() << "." << startDate.month() << "."
			<< startDate.year() << ";" << endDate.day() << "."
			<< endDate.month() << "." << endDate.year() << ";"
			<< startTime.hour() << ":" << startTime.minute() << ";"
			<< endTime.hour() << ":" << endTime.minute() << std::endl;
}
