#pragma once
#include "mystring.h"

class BitString : public mystring {
private:
    // Check if the string is a valid bit string
    bool isValidBitString(const char* str);

public:
    // Default constructor
    BitString();
    // Constructor with parameter
    BitString(const char* str);
    // Copy constructor
    BitString(const BitString& other);
    // Copy assignment operator
    BitString& operator=(const BitString& other);
    // Destructor
    ~BitString();
    // Change the sign of the number
    void changeSign();
    // String concatenation operator overload +
    BitString operator+(const BitString& other) const;
    // String concatenation operator overload +=
    BitString& operator+=(const BitString& other);
    // Equality operator overload ==
    bool operator==(const BitString& other) const;
    // Inequality operator overload !=
    bool operator!=(const BitString& other) const;
};

