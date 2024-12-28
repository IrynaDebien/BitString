#include "mystring.h"
#include "BitString.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    mystring str1("azerty");
    str1.printString();
    cout << endl;
    cout << "Length of str1: " << str1.getLength() << endl;
    cout << endl;

    mystring str2 = str1; // Using the copy constructor
    cout << "Used the copy constructor: " << endl;
    str2.printString();
    cout << endl;

    str1.clear(); // Clearing the string
    cout << "Used clear method: " << endl;
    str1.printString(); // Output: (empty)
    cout << endl;

    str1 = str2; // Using the assignment operator
    cout << "Used the assignment operator: " << endl;
    str1.printString();
    cout << endl;

    mystring str3("qsdfgh");
    mystring str4 = str3 + str2; // Using the + operator
    cout << "Used the + operator: " << endl;
    str4.printString();
    cout << endl;

    mystring str5("wxcvbn");
    str5 += str2; // Using the += operator
    cout << "Used the += operator: " << endl;
    str5.printString();
    cout << endl;

    if (str5 == str3) { // Using the == operator
        cout << "str5 is equal to str3" << endl;
    }
    if (str5 != str3) { // Using the != operator
        cout << "str5 is not equal to str3" << endl;
    }
    else {
        cout << " something went wrong" << endl;
    }
    cout << endl;

    BitString bitStr1("10000000");
    cout << "Created bit string 1: " << endl;
    bitStr1.printString();
    cout << endl;

    BitString bitStr2("01111111");
    cout << "Created bit string 2: " << endl;
    bitStr2.printString();
    cout << endl;

    BitString bitStr3 = bitStr1 + bitStr2;
    cout << "Created bit string 3 from the first two: " << endl;
    bitStr3.printString();
    cout << endl;

    bitStr1.changeSign();
    cout << "Changed the sign of bit string 1: " << endl;
    bitStr1.printString();
    cout << endl;

    if (bitStr1 == bitStr2) { // Using the == operator
        cout << "bit string 1 is equal to bit string 2" << endl;
    }
    else if (bitStr1 != bitStr2) { // Using the != operator
        cout << "bit string 1 is not equal to bit string 2" << endl;
    }
    else {
        cout << " something went wrong" << endl;
    }
    cout << endl;

    return 0;
}
