#include "mystring.h"

// Default constructor
mystring::mystring() : data(nullptr), length(0) {}

// Constructor with parameter
mystring::mystring(const char* str) {
    length = strlen(str);
    data = new char[length + 1];
    strcpy_s(data, length + 1, str);
}

// Copy constructor
mystring::mystring(const mystring& other) {
    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);
}

// Copy assignment operator
mystring& mystring::operator=(const mystring& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);
    return *this;
}

// Method to get the length of the string
size_t mystring::getLength() const {
    return length;
}

// Method to clear the string
void mystring::clear() {
    delete[] data;
    data = nullptr;
    length = 0;
}

// Destructor
mystring::~mystring() {
    delete[] data;
}

// String concatenation operator overload +
mystring mystring::operator+(const mystring& other) const {
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    if (data) {
        strcpy_s(newData, newLength + 1, data);
    }
    else {
        strcpy_s(newData, newLength + 1, "");
    }
    strcat_s(newData, newLength + 1, other.data);
    mystring newString(newData);
    delete[] newData;
    return newString;
}

// String concatenation operator overload +=
mystring& mystring::operator+=(const mystring& other) {
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    if (data) {
        strcpy_s(newData, newLength + 1, data);
    }
    else {
        strcpy_s(newData, newLength + 1, "");
    }
    strcat_s(newData, newLength + 1, other.data);
    delete[] data;
    data = newData;
    length = newLength;
    return *this;
}

// Equality operator overload ==
bool mystring::operator==(const mystring& other) const {
    if (length != other.length) {
        return false;
    }
    return strcmp(data, other.data) == 0;
}

// Inequality operator overload !=
bool mystring::operator!=(const mystring& other) const {
    return !(*this == other);
}

// Method to output the string
void mystring::printString() const {
    if (data) {
        cout << data;
    }
    else {
        cout << "(empty)";
    }
}

// Output stream operator overload
ostream& operator<<(ostream& os, const mystring& str) {
    if (str.data) {
        os << str.data;
    }
    else {
        os << "(empty)";
    }
    return os;
}

