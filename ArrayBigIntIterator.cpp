#include "ArrayBigIntIterator.h"

// Constructor
ArrayBigIntIterator::ArrayBigIntIterator(BigInt* startPtr) : ptr(startPtr) {}

// Dereferencing operators
BigInt& ArrayBigIntIterator::operator*() const {
    return *ptr;
}

BigInt* ArrayBigIntIterator::operator->() const {
    return ptr;
}

// Prefix increment and decrement operators
ArrayBigIntIterator& ArrayBigIntIterator::operator++() {
    ++ptr;
    return *this;
}

ArrayBigIntIterator& ArrayBigIntIterator::operator--() {
    --ptr;
    return *this;
}

// Postfix increment and decrement operators
ArrayBigIntIterator ArrayBigIntIterator::operator++(int) {
    ArrayBigIntIterator temp = *this;
    ++ptr;
    return temp;
}

ArrayBigIntIterator ArrayBigIntIterator::operator--(int) {
    ArrayBigIntIterator temp = *this;
    --ptr;
    return temp;
}

// Comparison operators
bool ArrayBigIntIterator::operator==(const ArrayBigIntIterator& other) const {
    return ptr == other.ptr;
}

bool ArrayBigIntIterator::operator!=(const ArrayBigIntIterator& other) const {
    return ptr != other.ptr;
}