#pragma once
#include "BigInt.h"

class ArrayBigIntIterator {
private:
    BigInt* ptr;

public:
    // Конструктор
    ArrayBigIntIterator(BigInt* startPtr);

    // Оператори розіменування
    BigInt& operator*() const;
    BigInt* operator->() const;

    // Префіксні оператори інкремента та декремента
    ArrayBigIntIterator& operator++();
    ArrayBigIntIterator& operator--();

    // Постфіксні оператори інкременту та декременту
    ArrayBigIntIterator operator++(int);
    ArrayBigIntIterator operator--(int);

    // Оператори порівняння
    bool operator==(const ArrayBigIntIterator& other) const;
    bool operator!=(const ArrayBigIntIterator& other) const;
};