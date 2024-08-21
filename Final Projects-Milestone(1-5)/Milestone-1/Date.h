#pragma once
#include "Status.h"
#include <iostream>
#include <string>

/**
 * @class Date
 * @brief Represents a date with day, month, and year, and provides related operations.
 *
 * The Date class is designed to represent a specific date with day, month, and year attributes.
 * It provides various operations to manipulate and compare dates, as well as to check the validity
 * of a date. The class also includes a status attribute to represent the state of the date object,
 * which holds a message and a code. Additionally, a formatted flag is included to indicate whether
 * the date is formatted or not.
 */
class Date {
public:
    static const int MAX_YEAR = 2030; ///< The maximum allowed year.

private:
    int year;       ///< The year of the date.
    int month;      ///< The month of the date.
    int day;        ///< The day of the date.
    Status status;  ///< The status of the date.
    bool formatted; ///< Flag indicating if the date is formatted.

    /**
     * @brief Validates the date.
     * @return True if the date is valid, false otherwise.
     * This function checks if the year, month, and day attributes of the date object
     * represent a valid date. It also updates the status attribute based on the validation result.
     */
    bool validate();

    /**
     * @brief Calculates a unique value representing the date.
     * @return The unique date value.
     * This function calculates a unique integer value based on the year, month, and day attributes,
     * which can be used for date comparisons.
     */
    int uniqueDateValue() const;

public:
    /**
     * @brief Parameterized constructor initializing Date object.
     * @param y The year.
     * @param m The month.
     * @param d The day.
     * This constructor initializes a Date object with the provided year, month, and day values,
     * and sets the formatted flag to false.
     */
    Date(int y, int m, int d);

    /**
     * @brief Default constructor initializing Date object with current date.
     * This constructor initializes a Date object with the current system date,
     * and sets the formatted flag to true.
     */
    Date();

    // Comparison operators
    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;

    /**
     * @brief Gets the status of the date.
     * @return The status of the date.
     * This function returns a const reference to the status attribute of the date object.
     */
    const Status& state() const;
    /**
     * @brief Sets the formatted flag of the date.
     * @param f The value to set the formatted flag.
     * @return The Date object with updated formatted flag.
     * This function sets the formatted attribute of the date object to the provided value,
     * and returns a reference to the date object.
     */
    Date& setFormatted(bool f);

    /**
     * @brief Checks if the date is valid.
     * @return True if the date is valid, false otherwise.
     * This function checks the validity of the date object by calling the validate function,
     * and returns the result.
     */
    explicit operator bool() const;

    /**
     * @brief Writes the date to an output stream.
     * @param os The output stream.
     * @return The output stream.
     * This function writes the date object to the provided output stream in a formatted manner,
     * and returns the output stream.
     */
    std::ostream& write(std::ostream& os) const;

    /**
     * @brief Reads a date from an input stream.
     * @param is The input stream.
     * @return The input stream.
     * This function reads a date from the provided input stream, updates the date object,
     * and returns the input stream.
     */
    std::istream& read(std::istream& is);

    /**
     * @brief Stream insertion operator for Date.
     * @param os The output stream.
     * @param date The Date object to be inserted into the stream.
     * @return The output stream.
     * This function writes the provided Date object to the output stream using the write function,
     * and returns the output stream.
     */ 
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    /**
     * @brief Stream extraction operator for Date.
     * @param is The input stream.
     * @param date The Date object to be extracted from the stream.
     * @return The input stream.
     * This function reads a Date object from the input stream using the read function,
     * and returns the input stream.
     */
    friend std::istream& operator>>(std::istream& is, Date& date);
};
