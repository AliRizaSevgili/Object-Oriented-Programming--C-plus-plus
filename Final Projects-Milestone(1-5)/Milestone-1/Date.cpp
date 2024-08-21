#include "date.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

Date::Date(int y, int m, int d) : year(y), month(m), day(d), formatted(false) {
    validate();
}

// Default constructor for the Date class which initializes an object with the current date.
Date::Date() {
    // 'time_t' is a data type used by the C standard to represent time. 'time(0)' returns the current calendar time (the number of seconds elapsed since January 1, 1970 UTC, known as Unix epoch).
    // The '0' argument indicates that we want the current time. 't' is assigned this value.
    time_t t = time(0);

    // 'localtime' is a function that converts 'time_t' to a 'tm' structure representing local time.
    // 'localtime' takes a pointer to a 'time_t' object, so we pass the address of 't' using '&t'.
    // The function returns a pointer to a static 'tm' structure which holds the local time broken down into its components.
    struct tm* now = localtime(&t);

    // The 'tm_year' member of the 'tm' structure holds the number of years since 1900.
    // Therefore, we add 1900 to this value to get the current calendar year and assign it to the 'year' member of our Date class.
    year = now->tm_year + 1900;

    // The 'tm_mon' member of the 'tm' structure holds the month of the year, starting from 0 for January to 11 for December.
    // We add 1 to this value because our Date class expects the month to be in the range 1-12, with 1 for January and so on.
    month = now->tm_mon + 1;

    // 'tm_mday' represents the day of the month in the 'tm' structure, which ranges from 1 to 31.
    // This value is directly assigned to the 'day' member of our Date class since they both represent the same concept.
    day = now->tm_mday;

    // We set a boolean member 'formatted' of our Date class to true. This could be an indication that the date has been correctly initialized and formatted for use.
    formatted = true;

    // Call a member function 'validate' of our Date class to check if the date is valid.
    // This is not shown here but it likely checks for things like correct ranges for day, month, and year, and possibly leap years.
    validate();
}


bool Date::validate() {
    if (year < 0 || year > MAX_YEAR) {
        status = Status("Invalid year in date", 1);
        return false;
    }
    if (month < 1 || month > 12) {
        status = Status("Invalid month in date", 2);
        return false;
    }
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    if (day < 1 || day > daysInMonth[month]) {
        status = Status("Invalid day in date", 3);
        return false;
    }
    status = Status("Date is valid", 0);
    return true;
}

int Date::uniqueDateValue() const {
    return (year * 372) + (month * 31) + day;
}


bool Date::operator==(const Date& rhs) const {
    return uniqueDateValue() == rhs.uniqueDateValue();
}

bool Date::operator!=(const Date& rhs) const {
    return !(*this == rhs);
}

bool Date::operator<(const Date& rhs) const {
    return uniqueDateValue() < rhs.uniqueDateValue();
}

bool Date::operator>(const Date& rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date& rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date& rhs) const {
    return !(*this < rhs);
}

const Status& Date::state() const {
    return status; 
}

Date& Date::setFormatted(bool f) {
    formatted = f;
    return *this;
}

Date::operator bool() const {
    return status.getCode() == 0;
}

std::ostream& Date::write(std::ostream& os) const {
    if (formatted) {
        os << std::setfill('0') << std::setw(4) << year << '/'
            << std::setfill('0') << std::setw(2) << month << '/'
            << std::setfill('0') << std::setw(2) << day;
    }
    else {
        os << std::setfill('0') << std::setw(2) << day
            << std::setfill('0') << std::setw(2) << month
            << std::setw(2) << (year % 100);
    }
    return os;
}

std::istream& Date::read(std::istream& is) {
    std::string input;
    is >> input;
    std::istringstream ss(input);
    char delimiter;
    if (formatted) {
        ss >> year >> delimiter >> month >> delimiter >> day;
    }
    else {
        ss >> day >> month >> year;
        year += 2000;
    }
    validate();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    return date.write(os);
}

std::istream& operator>>(std::istream& is, Date& date) {
    return date.read(is);
}
