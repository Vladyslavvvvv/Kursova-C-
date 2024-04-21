#pragma once
#include "BigInt.h"
#include "ArrayBigIntIterator.h"

class ArrayBigInt : BigInt {
public:
    static const int Csize = 100;
    BigInt array[Csize];
    int BIcount;

public:
    // Constructor
    ArrayBigInt();

    // Addition of objects to the array
    ArrayBigInt operator+(BigInt& bigint);

    // Displaying the entire array using an iterator
    void Show();

    // Getting the sum of all elements in the array
    BigInt sum();

    // Iteration methods
    ArrayBigIntIterator begin();
    ArrayBigIntIterator end();
};