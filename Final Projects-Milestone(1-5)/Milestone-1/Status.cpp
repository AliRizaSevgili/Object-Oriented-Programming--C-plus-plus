
#include "Status.h"
#include <cstring>



Status::Status(const char* desc, int c) : code(c) {
    if (desc != nullptr) {
        description = new char[strlen(desc) + 1];
        strcpy(description, desc);
    }
    else {
        description = nullptr;
    }
}


Status::Status(const Status& other) : code(other.code) {
    if (other.description != nullptr) {
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    else {
        description = nullptr;
    }
}

Status& Status::operator=(const Status& other) {
    if (this != &other) {
        delete[] description;
        code = other.code;
        if (other.description != nullptr) {
            description = new char[strlen(other.description) + 1];
            strcpy(description, other.description);
        }
        else {
            description = nullptr;
        }
    }
    return *this;
}

Status::~Status() {
    delete[] description;
}


Status& Status::operator=(const char* desc) {
    delete[] description;
    if (desc != nullptr) {
        description = new char[strlen(desc) + 1];
        strcpy(description, desc);
    }
    else {
        description = nullptr;
    }
    return *this;
}


Status& Status::operator=(int c) {
    code = c;
    return *this;
}


Status::operator int() const {
    return code;
}


Status::operator const char* () const {
    return description;
}


Status::operator bool() const {
    return description == nullptr;
}


void Status::clear() {
    delete[] description;
    description = nullptr;
    code = 0;
}


std::ostream& operator<<(std::ostream& os, const Status& status) {
    if (!status) {
        if (status.code != 0) {
            os << "ERR#" << status.code << ": ";
        }
        if (status.description != nullptr) {
            os << status.description;
        }
    }
    return os;
}


int Status::getCode() const {
    return code;
}