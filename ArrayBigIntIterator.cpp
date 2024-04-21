#include "ArrayBigIntIterator.h"

// �����������
ArrayBigIntIterator::ArrayBigIntIterator(BigInt* startPtr) : ptr(startPtr) {}

// ��������� ������������
BigInt& ArrayBigIntIterator::operator*() const {
    return *ptr;
}

BigInt* ArrayBigIntIterator::operator->() const {
    return ptr;
}

// �������� ��������� ���������� �� ����������
ArrayBigIntIterator& ArrayBigIntIterator::operator++() {
    ++ptr;
    return *this;
}

ArrayBigIntIterator& ArrayBigIntIterator::operator--() {
    --ptr;
    return *this;
}

// ��������� ��������� ���������� �� ����������
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

// ��������� ���������
bool ArrayBigIntIterator::operator==(const ArrayBigIntIterator& other) const {
    return ptr == other.ptr;
}

bool ArrayBigIntIterator::operator!=(const ArrayBigIntIterator& other) const {
    return ptr != other.ptr;
}