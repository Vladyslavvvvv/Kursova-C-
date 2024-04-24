#include "ArrayBigInt.h"
#include <iostream>

// Конструктор
ArrayBigInt::ArrayBigInt() : BIcount(0) {}

// Додавання об'єктів до масиву
ArrayBigInt ArrayBigInt::Add(BigInt& bigint) {
    if (BIcount < Csize) {
        array[BIcount++] = bigint;
    }
    return *this;
}

// Відображення всього масиву за допомогою ітератора
void ArrayBigInt::Show() {
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        cout << *it << endl;
    }
}

// Отримання суми всіх елементів масиву
BigInt ArrayBigInt::Sum() {
    BigInt result;
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        result = result + *it;
    }
    return result;
}

// Отримання добутку всіх елементів масиву
BigInt ArrayBigInt::Prod() {
    BigInt result;
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        result = result * *it;
    }
    return result;
}

// Ітераційні методи
ArrayBigIntIterator ArrayBigInt::begin() {
    return ArrayBigIntIterator(array);
}

ArrayBigIntIterator ArrayBigInt::end() {
    return ArrayBigIntIterator(array + BIcount);
}