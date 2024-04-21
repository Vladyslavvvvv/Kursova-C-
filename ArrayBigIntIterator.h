#pragma once
#include "BigInt.h"

class ArrayBigIntIterator {
private:
    BigInt* ptr;

public:
    // Constructor
    ArrayBigIntIterator(BigInt* startPtr);

    // Dereferencing operators
    BigInt& operator*() const;
    BigInt* operator->() const;

    // Prefix increment and decrement operators
    ArrayBigIntIterator& operator++();
    ArrayBigIntIterator& operator--();

    // Postfix increment and decrement operators
    ArrayBigIntIterator operator++(int);
    ArrayBigIntIterator operator--(int);

    // Comparison operators
    bool operator==(const ArrayBigIntIterator& other) const;
    bool operator!=(const ArrayBigIntIterator& other) const;
};