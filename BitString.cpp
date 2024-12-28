#include "BitString.h"

// Check if the string is a valid bit string
bool BitString::isValidBitString(const char* str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

// Default constructor
BitString::BitString() : mystring() {}

// Constructor with parameter
BitString::BitString(const char* str) {
    if (isValidBitString(str)) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }
    else {
        data = nullptr;
        length = 0;
    }
}

// Copy constructor
BitString::BitString(const BitString& other) : mystring(other) {}

// Copy assignment operator
BitString& BitString::operator=(const BitString& other) {
    if (this == &other) {
        return *this;
    }
    mystring::operator=(other);
    return *this;
}

// Destructor
BitString::~BitString() {}

// Change the sign of the number
void BitString::changeSign() {
    if (length == 0) return;
    for (size_t i = 0; i < length; ++i) {
        data[i] = (data[i] == '0') ? '1' : '0';
    }
}

// String concatenation operator overload +
BitString BitString::operator+(const BitString& other) const {
    if (length == 0) return other;
    if (other.length == 0) return *this;
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    strcpy_s(newData, newLength + 1, data);
    strcat_s(newData, newLength + 1, other.data);
    BitString newString(newData);
    delete[] newData;
    return newString;
}

// String concatenation operator overload +=
BitString& BitString::operator+=(const BitString& other) {
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    strcpy_s(newData, newLength + 1, data);
    strcat_s(newData, newLength + 1, other.data);
    delete[] data;
    data = newData;
    length = newLength;
    return *this;
}

// Equality operator overload ==
bool BitString::operator==(const BitString& other) const {
    return mystring::operator==(other);
}

// Inequality operator overload !=
bool BitString::operator!=(const BitString& other) const {
    return !(*this == other);
}
