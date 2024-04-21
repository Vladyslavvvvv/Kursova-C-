#include "BigInt.h"
#include <iostream>
#include <cstring>

// ��������� �����������
BigInt::BigInt() : String() {
    size = 1;
    digits = new int[size];
    digits[0] = 0;
    negative = false;
}

// ����������� � ����������
BigInt::BigInt(String& str) {
    // �������� ��������� ����� �����
    size = str.getTrueSize();

    // �������� ���'��� ��� ������ digits
    digits = new int[size];

    // ���������, �� � ����� ��'�����
    if (str.charAt(0) == '-') {
        negative = true;
        // �������� ������������ �� ���������� �������
        for (int i = 1; i < size; i++) {
            // ����������, �� ������� � ����� ������������� �����, � �� �����
            digits[i - 1] = str.charAt(i) - '0'; // ����������� ������� � �����
        }
        size--;
    }
    else {
        negative = false;
        // ���������� ����� digits ���������� � ����� str
        for (int i = 0; i < size; i++) {
            // ����������, �� ������� � ����� ������������� �����, � �� �����
            digits[i] = str.charAt(i) - '0'; // ����������� ������� � �����
        }
    }
}

// ����������� ���������
BigInt::BigInt(BigInt& other) {
    size = other.size;

    digits = new int[size];
    for (int i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }

    negative = other.negative;
}

// ����������� ����������
BigInt::BigInt(BigInt&& other) : size(0), digits(nullptr) {
    digits = other.digits;
    size = other.size;
    negative = other.negative;

    other.digits = nullptr;
    other.size = 0;
    other.negative = false;
}

// ����������
BigInt::~BigInt() {
    delete[] digits;
}

// �������� ����������
BigInt& BigInt::operator=(BigInt&& other) {
    if (this != &other) { // �������� �� �������������
        // ��������� ���'��� ��������� ��'����
        delete[] digits;
        size = 0;
        negative = false;

        // ��������� ��� � ������ ��'����
        digits = other.digits;
        size = other.size;
        negative = other.negative;

        other.digits = nullptr;
        other.size = 0;
        other.negative = false;
    }
    return *this;
}

// �������� ���������
BigInt& BigInt::operator=(BigInt& other) {
    if (this != &other) { // �������� �� �������������
        // �������� ���'��� ��� ������ ������
        delete[] digits;
        size = other.size;
        digits = new int[size];

        // ������� ��� � ������ ��'����
        for (int i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }

        negative = other.negative;
    }
    return *this;
}

// �������� ���������
BigInt BigInt::operator+(BigInt& other) {
    BigInt result;

    long long res1 = arrayToNumber(digits, size);
    if (negative) {
        res1 = res1 - (res1 + res1);
    }

    long long res2 = arrayToNumber(other.digits, other.size);
    if (other.negative) {
        res2 = res2 - (res2 + res2);
    }

    long long resultNumber = res1 + res2;
    if (resultNumber < 0) {
        result.negative = true;
        resultNumber = abs(resultNumber);
    }

    int* resultDigits;
    int resultSize;
    numberToArray(resultNumber, resultDigits, resultSize);

    result.size = resultSize;
    result.digits = resultDigits;

    return result;
}

// �������� ��������
BigInt BigInt::operator-(BigInt& other) {
    BigInt result;

    long long res1 = arrayToNumber(digits, size);
    if (negative) {
        res1 = res1 - (res1 + res1);
    }

    long long res2 = arrayToNumber(other.digits, other.size);
    if (other.negative) {
        res2 = res2 - (res2 + res2);
    }

    long long resultNumber = res1 - res2;
    if (resultNumber < 0) {
        result.negative = true;
        resultNumber = abs(resultNumber);
    }

    int* resultDigits;
    int resultSize;
    numberToArray(resultNumber, resultDigits, resultSize);

    result.size = resultSize;
    result.digits = resultDigits;
    return result;
}

// �������� ��������
BigInt BigInt::operator*(BigInt& other) {
    BigInt result;

    long long res1 = arrayToNumber(digits, size);
    if (negative) {
        res1 = res1 - (res1 + res1);
    }

    long long res2 = arrayToNumber(other.digits, other.size);
    if (other.negative) {
        res2 = res2 - (res2 + res2);
    }

    long long resultNumber = res1 * res2;
    if (resultNumber < 0) {
        result.negative = true;
        resultNumber = abs(resultNumber);
    }

    int* resultDigits;
    int resultSize;
    numberToArray(resultNumber, resultDigits, resultSize);

    result.size = resultSize;
    result.digits = resultDigits;
    return result;
}

// �������� ������
BigInt BigInt::operator/(BigInt& other) {
    BigInt result;

    long long res1 = arrayToNumber(digits, size);
    if (negative) {
        res1 = res1 - (res1 + res1);
    }

    long long res2 = arrayToNumber(other.digits, other.size);
    if (other.negative) {
        res2 = res2 - (res2 + res2);
    }

    long long resultNumber = res1 / res2;
    if (resultNumber < 0) {
        result.negative = true;
        resultNumber = abs(resultNumber);
    }

    int* resultDigits;
    int resultSize;
    numberToArray(resultNumber, resultDigits, resultSize);

    result.size = resultSize;
    result.digits = resultDigits;
    return result;
}

// ����� ��� ������������ ������ ���� � �����
long long BigInt::arrayToNumber(int* digits, int size) {
    long long result = 0;
    for (int i = 0; i < size; ++i) {
        result = result * 10 + digits[i];
    }

    return result;
}

// ����� ��� ������������ ����� � ����� ����
void BigInt::numberToArray(long long number, int*& digits, int& size) {
    // ��������� ������� ���� � ����
    long long temp = number;
    size = 0;
    while (temp != 0) {
        temp /= 10;
        size++;
    }

    // �������� ���'��� ��� ������ ����
    digits = new int[size];

    // ���������� ����� ����
    temp = number;
    for (int i = size - 1; i >= 0; --i) {
        digits[i] = temp % 10;
        temp /= 10;
    }
}

// �������� �����
bool BigInt::operator<(BigInt& other) {
    // ���������� ����
    if (negative) {
        return true;
    }
    else {
        return false;
    }

    // ��������� ������
    if (size < other.size) {
        return true;
    }
    else if (size > other.size) {
        return false;
    }

    // ���� ������ �������, ��������� ��������� �������, ��������� � ����������
    for (int i = 0; i < size; ++i) {
        if (digits[i] < other.digits[i]) {
            return true;
        }
        else if (digits[i] > other.digits[i]) {
            return false;
        }
    }

    // ���� �� ������� �������, ����� ���
    return false;
}

// �������� �����
bool BigInt::operator>(BigInt& other) {
    // ���������� ����
    if (negative) {
        return false;
    }
    else {
        return true;
    }

    // ��������� ������
    if (size > other.size) {
        return true;
    }
    else if (size < other.size) {
        return false;
    }

    // ���� ������ �������, ��������� ��������� �������, ��������� � ����������
    for (int i = 0; i < size; ++i) {
        if (digits[i] > other.digits[i]) {
            return true;
        }
        else if (digits[i] < other.digits[i]) {
            return false;
        }
    }

    // ���� �� ������� �������, ����� ���
    return false;
}

// �������� ����
bool BigInt::operator==(BigInt& other) {
    // ���������� ����
    if (negative == other.negative) {
        return true;
    }
    else {
        return false;
    }

    // ��������� ������
    if (size != other.size) {
        return false;
    }

    // ��������� ��������� �������
    for (int i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }

    // ���� �� ������� �������, ����� ���
    return true;
}

// �������� �� ����
bool BigInt::operator!=(BigInt& other) {
    // ������������� ��� ������� ��������� ��������� ����
    return !(*this == other);
}

// �������� �����-����
bool BigInt::operator<=(BigInt& other) {
    // ������������� ��� ������� ��������� ��������� '<' �� '=='
    return (*this < other) || (*this == other);
}

// �������� �����-����
bool BigInt::operator>=(BigInt& other) {
    // ������������� ��� ������� ��������� ��������� '>' �� '=='
    return (*this > other) || (*this == other);
}

// �������� ���������
ostream& operator<<(ostream& os, BigInt& bigint) {
    if (bigint.negative) {
        os << "-";
    }

    for (int i = 0; i < bigint.size; i++) {
        os << bigint.digits[i];
    }
    return os;
}

// �������� ��������
istream& operator>>(istream& is, BigInt& bigint) {
    String str;
    bool flag = false;

    do {
        is >> str;
        if (str.charAt(0) == '-') {
            for (int i = 1; i < str.getTrueSize(); i++) {
                if (!isdigit(str.charAt(i))) { // ����������, �� ����� ������ � ������
                    flag = false;
                    cout << "Error: Please enter only digits. Try again: " << endl;
                    break; // �������� � �����, ���� �������� ������������ ������
                }
                else {
                    flag = true;
                }
            }
        }
        else {
            for (int i = 0; i < str.getTrueSize(); i++) {
                if (!isdigit(str.charAt(i))) { // ����������, �� ����� ������ � ������
                    flag = false;
                    cout << "Error: Please enter only digits. Try again: " << endl;
                    break; // �������� � �����, ���� �������� ������������ ������
                }
                else {
                    flag = true;
                }
            }
        }
    } while (flag == false);

    bigint = BigInt(str); // ��������� ����������� � ���������� ��� ����������� bigint

    return is;
}