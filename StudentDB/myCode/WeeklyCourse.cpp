/*
 * WeeklyCourse.cpp
 *
 *  Created on: 15-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include "WeeklyCourse.h"

WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints,
		Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime) :
		Course(courseKey, title, major, creditPoints), dayOfWeek(dayOfWeek), startTime(
				startTime), endTime(endTime)
{
}

Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return dayOfWeek;
}

Poco::Data::Time WeeklyCourse::getStartTime() const
{
	return startTime;
}

Poco::Data::Time WeeklyCourse::getEndTime() const
{
	return endTime;
}

void WeeklyCourse::write(std::ostream &outFile) const
{
	outFile << "W;";
	Course::write(outFile);
	outFile << dayOfWeek << ";" << startTime.hour() << ":" << startTime.minute()
			<< ";" << endTime.hour() << ":" << endTime.minute() << std::endl;
}
