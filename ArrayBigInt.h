#pragma once
#include "BigInt.h"
#include "ArrayBigIntIterator.h"

class ArrayBigInt : BigInt {
public:
    static const int Csize = 100;
    BigInt array[Csize];
    int BIcount;

public:
    // Конструктор
    ArrayBigInt();

    // Відображення всього масиву за допомогою ітератора
    ArrayBigInt operator+(BigInt& bigint);

    // Відображення всього масиву за допомогою ітератора
    void Show();

    // Отримання суми всіх елементів масиву
    BigInt Sum();

    // Ітераційні методи
    ArrayBigIntIterator begin();
    ArrayBigIntIterator end();
};