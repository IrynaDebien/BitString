#pragma once
#include <windows.h>
#include <iostream>
#include <cstring> 
using namespace std;

class mystring {
protected:
    char* data;
    size_t length;

public:
    // Default constructor
    mystring();
    // Constructor with parameter
    mystring(const char* str);
    // Copy constructor
    mystring(const mystring& other);
    // Copy assignment operator
    mystring& operator=(const mystring& other);
    // Method to get the length of the string
    size_t getLength() const;
    // Method to clear the string
    void clear();
    // Destructor
    ~mystring();
    // String concatenation operator overload +
    mystring operator+(const mystring& other) const;
    // String concatenation operator overload +=
    mystring& operator+=(const mystring& other);
    // Equality operator overload ==
    bool operator==(const mystring& other) const;
    // Inequality operator overload !=
    bool operator!=(const mystring& other) const;
    // Method to output the string
    void printString() const;
    // Output stream operator overload
    friend ostream& operator<<(ostream& os, const mystring& str);
};