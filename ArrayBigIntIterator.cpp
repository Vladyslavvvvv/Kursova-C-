#include "ArrayBigIntIterator.h"

// Конструктор
ArrayBigIntIterator::ArrayBigIntIterator(BigInt* startPtr) : ptr(startPtr) {}

// Оператори розіменування
BigInt& ArrayBigIntIterator::operator*() const {
    return *ptr;
}

BigInt* ArrayBigIntIterator::operator->() const {
    return ptr;
}

// Префіксні оператори інкремента та декремента
ArrayBigIntIterator& ArrayBigIntIterator::operator++() {
    ++ptr;
    return *this;
}

ArrayBigIntIterator& ArrayBigIntIterator::operator--() {
    --ptr;
    return *this;
}

// Постфіксні оператори інкременту та декременту
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

// Оператори порівняння
bool ArrayBigIntIterator::operator==(const ArrayBigIntIterator& other) const {
    return ptr == other.ptr;
}

bool ArrayBigIntIterator::operator!=(const ArrayBigIntIterator& other) const {
    return ptr != other.ptr;
}