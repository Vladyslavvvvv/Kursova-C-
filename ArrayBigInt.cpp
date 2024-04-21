#include "ArrayBigInt.h"
#include <iostream>

// Constructor
ArrayBigInt::ArrayBigInt() : BIcount(0) {}

// Addition of objects to the array
ArrayBigInt ArrayBigInt::operator+(BigInt& bigint) {
    if (BIcount < Csize) {
        array[BIcount++] = bigint;
    }
    return *this;
}

// Displaying the entire array using an iterator
void ArrayBigInt::Show() {
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        cout << *it << endl;
    }
}

// Getting the sum of all elements in the array
BigInt ArrayBigInt::sum() {
    BigInt result;
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        result = result + *it;
    }
    return result;
}

// Iteration methods
ArrayBigIntIterator ArrayBigInt::begin() {
    return ArrayBigIntIterator(array);
}

ArrayBigIntIterator ArrayBigInt::end() {
    return ArrayBigIntIterator(array + BIcount);
}