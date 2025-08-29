/*
 * SimpleUI.cpp
 *
 *  Created on: 10-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */
#include <iostream>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <fstream>

#include "SimpleUI.h"
#include "Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"

SimpleUI::SimpleUI(StudentDb &db) :
		db(db)
{
}

Poco::Data::Date SimpleUI::stringToDate(std::string dateString)
{
	Poco::Data::Date date;
	int day, month, year;
	if (sscanf(dateString.c_str(), "%d.%d.%d", &day, &month, &year) != 3)
	{
		std::cerr << "Invalid date format. Please enter the date as DD.MM.YYYY."
				<< std::endl;
		return Poco::Data::Date();
	}
	date = Poco::Data::Date(year, month, day);

	return date;
}

Poco::Data::Time SimpleUI::stringToTime(std::string timeString)
{
	Poco::Data::Time time;
	int hour, minute;
	if (sscanf(timeString.c_str(), "%d:%d", &hour, &minute) != 2)
	{
		std::cerr << "Invalid time format. Please enter the time as HH:MM."
				<< std::endl;
		return Poco::Data::Time();
	}
	time = Poco::Data::Time(hour, minute, 0);

	return time;
}

Poco::DateTime::DaysOfWeek SimpleUI::convertDay(std::string dayOfWeekString)
{
	std::string day = dayOfWeekString;
	for (char &i : day)
	{
		i = toupper(i);
	}
	if (day == "SUNDAY")
	{
		return Poco::DateTime::DaysOfWeek::SUNDAY;
	}
	else if (day == "MONDAY")
	{
		return Poco::DateTime::DaysOfWeek::MONDAY;
	}
	else if (day == "TUESDAY")
	{
		return Poco::DateTime::DaysOfWeek::TUESDAY;
	}
	else if (day == "WEDNESDAY")
	{
		return Poco::DateTime::DaysOfWeek::WEDNESDAY;
	}
	else if (day == "THURSDAY")
	{
		return Poco::DateTime::DaysOfWeek::THURSDAY;
	}
	else if (day == "FRIDAY")
	{
		return Poco::DateTime::DaysOfWeek::FRIDAY;
	}
	else if (day == "SATURDAY")
	{
		return Poco::DateTime::DaysOfWeek::SATURDAY;
	}

	return Poco::DateTime::DaysOfWeek::SUNDAY;
}

void SimpleUI::run()
{
	int choice;
	do
	{
		std::cout << "Enter choice " << std::endl;
		std::cout << "1. Add new course" << std::endl;
		std::cout << "2. List courses" << std::endl;
		std::cout << "3. Add new student" << std::endl;
		std::cout << "4. Add enrollment" << std::endl;
		std::cout << "5. Print student" << std::endl;
		std::cout << "6. Search student" << std::endl;
		std::cout << "7. Update student" << std::endl;
		std::cout << "8. Write to File" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			addNewCourse();
			break;

		case 2:
			listCourses();
			break;

		case 3:
			addNewStudent();
			break;

		case 4:
			addEnrollment();
			break;

		case 5:
			printStudent();
			break;

		case 6:
			searchStudent();
			break;

		case 7:
			updateStudent();
			break;

		case 8:
			writeToFile();
			break;

		case 0:
			std::cout << "Exiting..." << std::endl;
			break;

		default:
			std::cout << "Invalid choice, try again" << std::endl;
			break;
		}
	} while (choice != 0);
}

void SimpleUI::addNewCourse()
{
	unsigned int courseKey;
	std::string title;
	std::string major;
	float creditPoints;
	char courseType;

	std::string startDateString;
	std::string endDateString;
	std::string startTimeString;
	std::string endTimeString;
	std::string dayOfWeekString;

	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	Poco::DateTime::DaysOfWeek dayOfWeek;

	std::cout << "Enter Course Type (B: BlockCourse, W: WeeklyCourse): ";
	std::cin >> courseType;
	std::cout << "Enter Course Key: ";
	std::cin >> courseKey;
	std::cout << "Enter title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Enter Major: ";
	std::cin >> major;
	std::cout << "Enter Credit points: ";
	std::cin >> creditPoints;

	if (courseType == 'B')
	{
		std::cout << "Enter start date (DD.MM.YYYY): ";
		std::cin >> startDateString;
		std::cout << "Enter end date (DD.MM.YYYY): ";
		std::cin >> endDateString;

		startDate = stringToDate(startDateString);
		endDate = stringToDate(endDateString);
	}
	else if (courseType == 'W')
	{
		std::cout << "Enter Day of Week: ";
		std::cin >> dayOfWeekString;
		dayOfWeek = convertDay(dayOfWeekString);
	}

	std::cout << "Enter start time (HH:MM): ";
	std::cin >> startTimeString;
	std::cout << "Enter end time (HH:MM): ";
	std::cin >> endTimeString;

	startTime = stringToTime(startTimeString);
	endTime = stringToTime(endTimeString);

	std::cout << std::endl;

	if (courseType == 'B')
	{
		db.addBlockCourse(courseKey, title, major, creditPoints, startDate,
				endDate, startTime, endTime);
		std::cout << "Course added successfully" << std::endl << std::endl;
	}
	else if (courseType == 'W')
	{
		db.addWeeklyCourse(courseKey, title, major, creditPoints, dayOfWeek,
				startTime, endTime);
		std::cout << "Course added successfully" << std::endl << std::endl;
	}
}

void SimpleUI::listCourses()
{
	std::map<int, std::string> daysMap =
	{
	{ 0, "Sunday" },
	{ 1, "Monday" },
	{ 2, "Tuesday" },
	{ 3, "Wednesday" },
	{ 4, "Thursday" },
	{ 5, "Friday" },
	{ 6, "Saturday" } };

	const auto &courses = db.getCourses();
	for (const auto &pair : courses)
	{
		auto blockCourse = dynamic_cast<const BlockCourse*>(pair.second.get());
		auto weekylCourse = dynamic_cast<const WeeklyCourse*>(pair.second.get());

		if (blockCourse != nullptr)
		{
			std::cout << "Type: BlockCourse" << std::endl << "Course Key: "
					<< blockCourse->getCourseKey() << std::endl << "Title: "
					<< blockCourse->getTitle() << std::endl << "Major: "
					<< blockCourse->getMajor() << std::endl << "Credit Points: "
					<< blockCourse->getCreditPoints() << std::endl
					<< "Start Date: "
					<< Poco::DateTimeFormatter::format(
							Poco::DateTime(blockCourse->getStartDate().year(),
									blockCourse->getStartDate().month(),
									blockCourse->getStartDate().day()),
							"%d.%m.%Y") << std::endl << "End Date:  "
					<< Poco::DateTimeFormatter::format(
							Poco::DateTime(blockCourse->getEndDate().year(),
									blockCourse->getEndDate().month(),
									blockCourse->getEndDate().day()),
							"%d.%m.%Y") << std::endl << "Start Time: "
					<< Poco::DateTimeFormatter::format(
							Poco::DateTime(1970, 1, 1,
									blockCourse->getStartTime().hour(),
									blockCourse->getStartTime().minute(), 0),
							"%H:%M") << std::endl << "End Time: "
					<< Poco::DateTimeFormatter::format(
							Poco::DateTime(1970, 1, 1,
									blockCourse->getEndTime().hour(),
									blockCourse->getEndTime().minute(), 0),
							"%H:%M") << std::endl << std::endl;
		}
		else if (weekylCourse != nullptr)
		{
			std::cout << "Type: WeeklyCourse" << std::endl << "Course Key: "
					<< weekylCourse->getCourseKey() << std::endl << "Title: "
					<< weekylCourse->getTitle() << std::endl << "Major: "
					<< weekylCourse->getMajor() << std::endl
					<< "Credit Points: " << weekylCourse->getCreditPoints()
					<< std::endl << "Day of Week: "
					<< daysMap.at(
							static_cast<int>(weekylCourse->getDayOfWeek()))
					<< std::endl << "Start Time: "
					<< Poco::DateTimeFormatter::format(
							Poco::DateTime(1970, 1, 1,
									weekylCourse->getStartTime().hour(),
									weekylCourse->getStartTime().minute(), 0),
							"%H:%M") << std::endl << "End Time: "
					<< Poco::DateTimeFormatter::format(
							Poco::DateTime(1970, 1, 1,
									weekylCourse->getEndTime().hour(),
									weekylCourse->getEndTime().minute(), 0),
							"%H:%M") << std::endl << std::endl;

		}
	}
	std::cout << std::endl;
}

void SimpleUI::addNewStudent()
{
	std::string firstName;
	std::string lastName;
	std::string dateOfBirthString;
	Poco::Data::Date dateOfBirth;
	std::string street;
	unsigned short postalCode;
	std::string cityName;
	std::string additionalInfo;

	std::cout << "Enter First name: ";
	std::cin >> firstName;
	std::cout << "Enter Last name: ";
	std::cin >> lastName;
	std::cout << "Enter Date of Birth (DD.MM.YYYY): ";
	std::cin >> dateOfBirthString;

	dateOfBirth = stringToDate(dateOfBirthString);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter Address - Street: ";
	std::getline(std::cin, street);
	std::cout << "Enter Postal code: ";
	std::cin >> postalCode;
	std::cout << "Enter City Name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, cityName);
	std::cout
			<< "Enter Additional Information (Enter null or - if no Additional Info): ";
	std::getline(std::cin, additionalInfo);

	if (additionalInfo == "null" || additionalInfo == "-")
	{
		additionalInfo = "";
	}

	std::cout << std::endl;

	db.addStudent(firstName, lastName, dateOfBirth, street, postalCode,
			cityName, additionalInfo);
	std::cout << "Student added successfully" << std::endl << std::endl;
}

void SimpleUI::printStudent()
{
	const auto students = db.getStudents();
	for (const auto &student : students)
	{
		std::cout << "Matrikel Number: " << student.first << std::endl
				<< "Name: " << student.second.getFirstName() << " "
				<< student.second.getLastName() << std::endl
				<< "Date of Birth: "
				<< Poco::DateTimeFormatter::format(
						Poco::DateTime(student.second.getDateOfBirth().year(),
								student.second.getDateOfBirth().month(),
								student.second.getDateOfBirth().day()),
						"%d.%m.%Y") << std::endl << "Address: "
				<< student.second.getAddress().getStreet() << ", "
				<< student.second.getAddress().getPostalCode() << ", "
				<< student.second.getAddress().getCityName() << ", "
				<< student.second.getAddress().getAdditionalInfo();
		std::cout << std::endl << std::endl;
	}
	std::cout << std::endl;
}

void SimpleUI::addEnrollment()
{
	unsigned int matrikelNumber;
	unsigned int courseKey;
	std::string semester;

	std::cout << "Enter Matrikel Number: ";
	std::cin >> matrikelNumber;
	std::cout << "Enter Course Key: ";
	std::cin >> courseKey;
	std::cout << "Enter Semester: ";
	std::cin >> semester;

	const auto students = db.getStudents();
	if (students.find(matrikelNumber) == students.end())
	{
		std::cout << "Student with Matrikel Number " << matrikelNumber
				<< " not found!" << std::endl;
		return;
	}

	const auto &courses = db.getCourses();
	if (courses.find(courseKey) == courses.end())
	{
		std::cout << "Course with Course Key " << courseKey << " not found!"
				<< std::endl;
		return;
	}

	auto itr = db.getStudents().find(matrikelNumber);
	for (auto &enrollment : itr->second.getEnrollments())
	{
		if (enrollment.getCourse()->getCourseKey() == courseKey
				&& semester == enrollment.getSemester())
		{
			std::cout
					<< "Student is already enrolled in this course for the given semester."
					<< std::endl;
			return;
		}
	}
	db.addEnrollment(matrikelNumber, courseKey, semester);
	std::cout << "Enrollment added successfully" << std::endl << std::endl;
}

void SimpleUI::searchStudent()
{
	std::string searchStr;
	int found = 0;
	std::cout << "Enter search string: ";
	std::cin.ignore();
	std::getline(std::cin, searchStr);
	std::cout << std::endl;
	std::cout << "Search results: ";
	std::map<int, Student> students = db.getStudents();

	for (const auto &student : students)
	{
		std::string fullName = student.second.getFirstName() + " "
				+ student.second.getLastName();
		if (fullName.find(searchStr) != std::string::npos)
		{
			std::cout << "Found, Matrikel number:  " << student.first
					<< std::endl;
			std::cout << "Name: " << student.second.getFirstName() << " "
					<< student.second.getLastName() << std::endl;
			found++;
		}
	}
	if (found == 0)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << std::endl;
}

void SimpleUI::updateStudent()
{
	unsigned int matrikelNumber;
	unsigned int choice;

	std::cout << "Enter Matrikel Number: ";
	std::cin >> matrikelNumber;

	if (db.matrikelNumberExists(matrikelNumber))
	{
		std::cout << "1. Update Student Name" << std::endl;
		std::cout << "2. Update Student DOB" << std::endl;
		std::cout << "3. Update Student Address" << std::endl;
		std::cout << "4. Update Student Enrollment Data" << std::endl;
		std::cout << "0. Cancel Update" << std::endl;
		std::cout << "Enter choice: " << std::endl;

		std::cin >> choice;
		switch (choice)
		{
		case 0:
		{
			std::cout << std::endl;
			std::cout << "Update cancelled" << std::endl << std::endl;
			break;
		}
		case 1:
		{
			std::string firstName;
			std::string lastName;
			std::cout << "Enter First name: ";
			std::cin.ignore();
			std::getline(std::cin, firstName);
			std::cout << "Enter Last name: ";
			std::getline(std::cin, lastName);
			db.updateName(matrikelNumber, firstName, lastName);
			std::cout << std::endl;
			std::cout << "Name Updated." << std::endl << std::endl;

			break;
		}
		case 2:
		{
			std::string dateOfBirthString;
			Poco::Data::Date dateOfBirth;
			std::cout << "Enter Date of Birth (DD.MM.YYYY): ";
			std::cin.ignore();
			std::getline(std::cin, dateOfBirthString);
			dateOfBirth = stringToDate(dateOfBirthString);
			db.updateDateOfBirth(matrikelNumber, dateOfBirth);
			std::cout << std::endl;
			std::cout << "Date of Birth Updated." << std::endl << std::endl;

			break;
		}
		case 3:
		{
			std::string street;
			unsigned short postalCode;
			std::string cityName;
			std::string additionalInfo;
			std::cout << "Enter Street: ";
			std::cin.ignore();
			std::getline(std::cin, street);
			std::cout << "Enter Postal Code: ";
			std::cin >> postalCode;
			std::cout << "Enter City Name: ";
			std::cin.ignore();
			std::getline(std::cin, cityName);
			std::cout
					<< "Enter Additional Information (Enter null or - if no Additional Info): ";
			std::getline(std::cin, additionalInfo);
			if (additionalInfo == "null" || additionalInfo == "-")
			{
				additionalInfo = "";
			}
			db.updateAddress(matrikelNumber, street, postalCode, cityName,
					additionalInfo);
			std::cout << std::endl;
			std::cout << "Address Updated" << std::endl << std::endl;

			break;
		}
		case 4:
		{
			unsigned int courseKey;
			float grade;
			std::string semester;
			bool enrollmentExists = false;
			unsigned int option;

			std::cout << "Enter Course ID: ";
			std::cin >> courseKey;

			auto itr = db.getStudents().at(matrikelNumber);
			if (!this->db.courseExists(courseKey))
			{
				std::cout << "Course doesn't exist." << std::endl << std::endl;
				break;
			}

			for (auto &enrollment : itr.getEnrollments())
			{
				if (enrollment.getCourse()->getCourseKey() == courseKey)
				{
					enrollmentExists = true;
					break;
				}
			}

			if (!enrollmentExists)
			{
				std::cout << "Enrollment doesn't exist" << std::endl;
				break;
			}
			std::cout << "Enter choice" << std::endl;
			std::cout << "1. Delete enrollment" << std::endl;
			std::cout << "2. Update Grade" << std::endl;
			std::cin >> option;

			switch (option)
			{
			case 1:
			{
				db.deleteEnrollment(matrikelNumber, courseKey);
				std::cout << std::endl;
				std::cout << "Enrollment deleted" << std::endl << std::endl;
				break;
			}
			case 2:
			{
				std::cout << "Enter grade: ";
				std::cin >> grade;
				db.updateGrade(matrikelNumber, courseKey, grade);
				std::cout << std::endl;
				std::cout << "Grade Updated" << std::endl << std::endl;
				break;
			}
			default:
				std::cout << std::endl;
				std::cout << "Invalid choice" << std::endl << std::endl;
				break;
			}

			break;
		}
		default:
		{
			std::cout << "Invalid option selected" << std::endl << std::endl;
			break;
		}
		}
	}
}

void SimpleUI::writeToFile() const
{
	if (!(db.getStudents().empty() && db.getCourses().empty()))
	{
		std::string fileName;
		std::cout << "Enter the file name: ";
		std::cin >> fileName;
		std::ofstream outFile(fileName);
		if (!outFile)
		{
			std::cerr << "Error opening file for writing.\n";
			return;
		}
		db.write(outFile);
		outFile.close();
		std::cout << "Data has been written to " << fileName << std::endl
				<< std::endl;
	}
	else
	{
		std::cout << "Database empty." << std::endl << std::endl;
	}
}
