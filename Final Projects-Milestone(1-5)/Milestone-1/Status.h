
#pragma once

#include <iostream>

class Status
{

public:

    Status(const char* desc = nullptr, int c = 0);
    Status(const Status& other);
    Status& operator=(const Status& other);
    ~Status();

    Status& operator=(const char* desc);
    Status& operator=(int c);

    operator int() const;
    operator const char* () const;
    operator bool() const;

    void clear();
    friend std::ostream& operator<<(std::ostream& os, const Status& status);
    int getCode() const;

private:
	char* description;
	int code;
};



