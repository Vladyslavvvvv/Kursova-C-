#pragma once
#include "BigInt.h"
#include "ArrayBigIntIterator.h"

class ArrayBigInt : BigInt {
public:
    static const int Csize = 1000;
    BigInt array[Csize];
    int BIcount;

public:
    // �����������
    ArrayBigInt();

    // ³���������� ������ ������ �� ��������� ���������
    ArrayBigInt Add(BigInt& bigint);

    // ³���������� ������ ������ �� ��������� ���������
    void Show();

    // ��������� ���� ��� �������� ������
    BigInt Sum();

    // ��������� ������
    ArrayBigIntIterator begin();
    ArrayBigIntIterator end();
};