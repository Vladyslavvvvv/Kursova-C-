#include "BigInt.h"
#include <cstring>
#include <iostream>

using namespace std;

// ����� ��� ������� �� ������� �������
char BigInt::charAt(int index) {
    if (index >= 0 && index < strlen(str)) {
        return str[index];
    }
    else {
        return '\0'; // ��������� �������� ������ � ������� �������� �������
    }
}

// ������ ������ �������
char* BigInt::reverseString(char* Str) {
    int len = strlen(Str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = Str[i];
        Str[i] = Str[len - i - 1];
        Str[len - i - 1] = temp;
    }
    return Str;
}

// ����������� ���������
BigInt::BigInt(BigInt& other) {
    delete[] str; // ��������� ���'�� ��'����
    maxLength = other.maxLength; // ��������� ����������� �������
    str = new char[maxLength]; // �������� ���� ���'��
    copy(other.str, other.str + maxLength, str); // ��������� �����
}

// ����������� ����������
BigInt::BigInt(BigInt&& other) {
    delete[] str; // ��������� ���'�� ��'����
    maxLength = other.maxLength; // ��������� ����������� �������
    str = other.str; // ���������� ���������
    other.str = nullptr; // ������� �������� ��������� � ���������� ��'���
    other.maxLength = 0; // ��������� ����������� ������� � ���������� ��'���
}

// �������� ��������� ��'���� BigInt
BigInt& BigInt::operator=(BigInt& other) {
    if (this != &other) { // �������� �� �������������
        String::operator=(other); // ��������� �������� ��������� �������� �����
    }
    return *this;
}

// �������� ��������� ��'���� String
BigInt& BigInt::operator=(String& other) {
    if (this != &other) { // �������� �� �������������
        String::operator=(other); // ��������� �������� ��������� �������� �����
    }
    return *this;
}

// �������� ���������� ��'���� BigInt
BigInt& BigInt::operator=(BigInt&& other) {
    if (this != &other) { // �������� �� �������������
        String::operator=(other); // ��������� �������� ��������� �������� �����
    }
    return *this;
}

// �������� ���������� ��'���� String
BigInt& BigInt::operator=(String&& other) {
    if (this != &other) { // �������� �� �������������
        String::operator=(other); // ��������� �������� ��������� �������� �����
    }
    return *this;
}

// �������� ���������
String BigInt::operator+(String& other) {
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    int maxlen = len1 > len2 ? len1 : len2;

    char* result = new char[maxlen + 2];
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? str[i] - '0' : 0;
        int digit2 = j >= 0 ? other.str[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[k++] = sum % 10 + '0';
        carry = sum / 10;
        i--;
        j--;
    }

    result[k] = '\0';

    reverseString(result); // ������ ����������

    return String(result, maxlen + 2);
}

// �������� ��������
BigInt BigInt::operator-(BigInt& other) {
    if (*this < other) {
        cout << "����� ����� ����� �� �����! �������� �� ���� ��������� � ��'������ ����������." << endl;
        BigInt B1;
        return B1;
    }
    else if (*this == other) {
        char* ch = new char[2];
        ch[0] = '0';
        ch[1] = '\0';
        BigInt B2(ch, 2);
        return B2;
    }
    else {
        int len1 = strlen(str);
        int len2 = strlen(other.str);

        // ��������� ����� ������� ��� ����������� ������
        int maxlen = len1 > len2 ? len1 : len2;

        // �������� ���'�� ��� ����������
        char* result = new char[maxlen + 1];
        result[maxlen] = '\0';

        int borrow = 0;
        int i = len1 - 1;
        int j = len2 - 1;
        int k = maxlen - 1;

        // ����������� ������ ����
        while (k >= 0) {
            int digit1 = i >= 0 ? str[i] - '0' : 0;
            int digit2 = j >= 0 ? other.str[j] - '0' : 0;
            int diff = digit1 - digit2 - borrow;

            // ���� ������ ��'����, ���������� � ������� �� ������������ �������
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }

            result[k--] = diff + '0';
            i--;
            j--;
        }

        // �������� �� ��� �� �������
        int idx = 0;
        while (result[idx] == '0') {
            idx++;
        }

        // ��������� ��������� �� BigInt
        return BigInt(result + idx, maxlen - idx + 1);
    }
}

// �������� ��������
BigInt BigInt::operator*(BigInt& other) {
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    int maxlen = len1 + len2; // ����������� ������� ������� ������������� �����

    // �������� ���'�� ��� ����������
    char* result = new char[maxlen + 1];
    for (int i = 0; i < maxlen; ++i) {
        result[i] = '0'; // ����������� ��� ���� ���������� ������
    }
    result[maxlen] = '\0';

    // ���������� �������
    for (int i = len1 - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; --j) {
            int digit1 = str[i] - '0';
            int digit2 = other.str[j] - '0';
            int product = digit1 * digit2 + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = product % 10 + '0';
        }
        result[i] += carry; // ������ ������� ����������� �� ������������ �������
    }

    // �������� �� ��� �� �������
    int i = 0;
    while (result[i] == '0') {
        i++;
    }

    // ��������� ��������� �� BigInt
    return BigInt(result + i, maxlen + 1);
}

// �������� ������
BigInt BigInt::operator/(BigInt& other) {
    // ����������� ���������� ������ �� ������� BigInt
    char* b1 = new char[2];
    b1[0] = '0';
    b1[1] = '\0';
    BigInt result(b1, 2);

    char* b2 = new char[2];
    b2[0] = '1';
    b2[1] = '\0';
    BigInt quotient(b2, 2);

    // ���� �������, ��� ������ ��������
    BigInt dividend = *this;

    // ���� ����� ����� ��� ������� �������
    while (dividend > other) {
        dividend = dividend - other; // ³������ ������ �� �������
        result = result + quotient; // ������������ ���������
    }

    result = result + quotient;

    // ���������� ���������� ������
    return result;
}

// �������� �����
bool BigInt::operator>(BigInt& other) {
    // ���������� ������� ��'����
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    if (len1 > len2) {
        return true; // ���� ������ ��'��� �� ����� �������, �� ������
    }
    else if (len1 < len2) {
        return false; // ���� ������ ��'��� �� ����� �������, �� ������
    }
    // ���� ������� ���, ��������� ������ ��������
    for (int i = 0; i < len1; ++i) {
        if (str[i] > other.str[i]) {
            return true;
        }
        else if (str[i] < other.str[i]) {
            return false;
        }
    }
    // ���� ������ ��'���� ���
    return false;
}

// �������� �����
bool BigInt::operator<(BigInt& other) {
    // ���������� ������� ��'����
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    if (len1 < len2) {
        return true; // ���� ������ ��'��� �� ����� �������, �� ������
    }
    else if (len1 > len2) {
        return false; // ���� ������ ��'��� �� ����� �������, �� ������
    }
    // ���� ������� ���, ��������� ������ ��������
    for (int i = 0; i < len1; ++i) {
        if (str[i] < other.str[i]) {
            return true;
        }
        else if (str[i] > other.str[i]) {
            return false;
        }
    }
    // ���� ������ ��'���� ���
    return false;
}

// �������� ����
bool BigInt::operator==(BigInt& other) {
    return strcmp(str, other.str) == 0; // ������ ��������� ������� �������
}

// �������� �� ����
bool BigInt::operator!=(BigInt& other) {
    return strcmp(str, other.str) != 0;
}

// �������� ����� ����
bool BigInt::operator>=(BigInt& other) {
    return strcmp(str, other.str) >= 0;
}

// �������� ����� ����
bool BigInt::operator<=(BigInt& other) {
    return strcmp(str, other.str) <= 0;
}

// �������������� �������� �������� >>
istream& operator>>(istream& is, BigInt& bigint) {
    bool flag = false;
    long long int maxSize;

    cout << "������ ������������ ����� �������� ������ �����: ";
    while (!(is >> maxSize) || maxSize <= 0) {
        cout << "������������ ���! ������ ���� �����: ";
        is.clear();
        is.ignore();
    }

    maxSize++;

    char* input = new char[maxSize + 1];

    cout << "������ ������ ���� �����: ";
    is >> input;

    // �������� �� �������� ���� ���� � ��������� �����
    bool isValid = true;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!isdigit(input[i])) {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "������������ ���! ������ ���� �����: " << endl;
        // ��������� ������� ���'�� ����� ������� � �������
        delete[] input;
        // �������� ������ ����� �� ������������ �������
        is.clear();
        // ��������� ������������� �������� � ������
        is.ignore();
        // ����������� ������ ��� ���������� ��������
        return operator>>(is, bigint);
    }

    bigint = BigInt(input, maxSize);

    delete[] input;

    return is;
}

// �������������� �������� ��������� <<
ostream& operator<<(ostream& os, BigInt& bigint) {
    os << bigint.str;

    return os;
}