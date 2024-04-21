#pragma once
#include "BigInt.h"

class ArrayBigIntIterator {
private:
    BigInt* ptr;

public:
    // �����������
    ArrayBigIntIterator(BigInt* startPtr);

    // ��������� ������������
    BigInt& operator*() const;
    BigInt* operator->() const;

    // �������� ��������� ���������� �� ����������
    ArrayBigIntIterator& operator++();
    ArrayBigIntIterator& operator--();

    // ��������� ��������� ���������� �� ����������
    ArrayBigIntIterator operator++(int);
    ArrayBigIntIterator operator--(int);

    // ��������� ���������
    bool operator==(const ArrayBigIntIterator& other) const;
    bool operator!=(const ArrayBigIntIterator& other) const;
};