/*
 * Address.h
 *
 *  Created on: 09-Jan-2025
 *      Author: Dheeraj Swaroop S M
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

/**
 * @class Address
 * @brief Represents an address with street, postal code, city, and additional information.
 */
class Address
{
private:
	/** @brief The street name of the address. */
	std::string street;

	/** @brief The postal code of the address. */
	unsigned short postalCode;

	/** @brief The city name of the address. */
	std::string cityName;

	/** @brief Additional information about the address (e.g., apartment number). */
	std::string additionalInfo;

public:
	/**
	 * @brief Constructs an Address object.
	 * @param street The street name.
	 * @param postalCode The postal code.
	 * @param cityName The city name.
	 * @param additionalInfo Additional details about the address.
	 */
	Address(std::string street, unsigned short postalCode, std::string cityName,
			std::string additionalInfo);

	/**
	 * @brief Gets the street name.
	 * @return The street name as a string.
	 */
	std::string getStreet() const;

	/**
	 * @brief Gets the postal code.
	 * @return The postal code as an unsigned short.
	 */
	unsigned short getPostalCode() const;

	/**
	 * @brief Gets the city name.
	 * @return The city name as a string.
	 */
	std::string getCityName() const;

	/**
	 * @brief Gets additional information about the address.
	 * @return Additional info as a string.
	 */
	std::string getAdditionalInfo() const;

	/**
	 * @brief Writes the address data to an output stream.
	 * @param outFile The output stream to write to.
	 */
	void write(std::ostream &outFile) const;
};

#endif /* ADDRESS_H_ */
