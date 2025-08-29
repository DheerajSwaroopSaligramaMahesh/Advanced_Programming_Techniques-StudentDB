/*
 * Address.cpp
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include "Address.h"

Address::Address(std::string street, unsigned short postalCode,
		std::string cityName, std::string additionalInfo) :
		street(street), postalCode(postalCode), cityName(cityName), additionalInfo(
				additionalInfo)
{
}

std::string Address::getStreet() const
{
	return street;
}

unsigned short Address::getPostalCode() const
{
	return postalCode;
}

std::string Address::getCityName() const
{
	return cityName;
}

std::string Address::getAdditionalInfo() const
{
	return additionalInfo;
}

void Address::write(std::ostream &outFile) const
{
	outFile << street << ";" << postalCode << ";" << cityName << ";"
			<< additionalInfo << std::endl;
}
