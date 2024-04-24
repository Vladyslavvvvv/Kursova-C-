#include "ArrayBigInt.h"
#include <iostream>

// �����������
ArrayBigInt::ArrayBigInt() : BIcount(0) {}

// ��������� ��'���� �� ������
ArrayBigInt ArrayBigInt::Add(BigInt& bigint) {
    if (BIcount < Csize) {
        array[BIcount++] = bigint;
    }
    return *this;
}

// ³���������� ������ ������ �� ��������� ���������
void ArrayBigInt::Show() {
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        cout << *it << endl;
    }
}

// ��������� ���� ��� �������� ������
BigInt ArrayBigInt::Sum() {
    BigInt result;
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        result = result + *it;
    }
    return result;
}

// ��������� ������� ��� �������� ������
BigInt ArrayBigInt::Prod() {
    BigInt result;
    for (ArrayBigIntIterator it = begin(); it != end(); ++it) {
        result = result * *it;
    }
    return result;
}

// ��������� ������
ArrayBigIntIterator ArrayBigInt::begin() {
    return ArrayBigIntIterator(array);
}

ArrayBigIntIterator ArrayBigInt::end() {
    return ArrayBigIntIterator(array + BIcount);
}