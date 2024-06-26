#include "String.h"
#include <cstring>
#include <windows.h>
#include <iostream>

using namespace std;


// ��������� �����������
String::String() {
    str = new char[1]; // �������� ���� ��� ������ � ����� �������� ��� ������������� ����-����������
    str[0] = '\0'; // �������� �����
    maxLength = 1; // ����������� ������� �� ������������
}

// ����������� ������������
String::String(char* newStr, int newLength) {
    maxLength = newLength;
    str = new char[maxLength];
    copy(newStr, newStr + maxLength - 1, str);
    str[maxLength - 1] = '\0';
}

// ����������� ���������
String::String(String& other) {
    delete[] str; // ��������� ���'�� ��'����
    maxLength = other.maxLength; // ��������� ����������� �������
    str = new char[maxLength]; // �������� ���� ���'��
    copy(other.str, other.str + maxLength, str); // ��������� �����
}

// ����������� ����������
String::String(String&& other) {
    delete[] str; // ��������� ���'�� ��'����
    maxLength = other.maxLength; // ��������� ����������� �������
    str = other.str; // ���������� ���������
    other.str = nullptr; // ������� �������� ��������� � ���������� ��'���
    other.maxLength = 0; // ��������� ����������� ������� � ���������� ��'���
}

// ����������
String::~String() {
    delete[] str;
}

// ����� ��� ������������ ����������� �������
void String::setLength(int newLength) {
    maxLength = newLength + 1;
}

// ����� ��� ������������ �������� �����
void String::setString(char* newStr) {
    copy(newStr, newStr + maxLength - 1, str);
    str[maxLength - 1] = '\0';
}

// ����� ��� ��������� ����������� �������
int String::getLength() {
    return maxLength - 1;
}

// ����� ��� ��������� �������� �����
char* String::getString() {
    return str;
}

// ����� ��� ��������� ���������� ������ �����
int String::getTrueSize() {
    return strlen(str);
}

// �������������� �������� +
String String::operator+(String& other) {
    int newLength = strlen(str) + strlen(other.str) + 1; // ���������� ���� ������� �����
    char* newStr = new char[newLength + 1]; // +1 ��� ����-����������

    copy(str, str + strlen(str), newStr); // ������� ������ �����
    copy(other.str, other.str + strlen(other.str) + 1, newStr + strlen(str)); // ������ ������ �����

    return String(newStr, newLength); // ��������� ����� ��'��� String
}

// �������������� �������� -
String String::operator-(String& other) {
    char* originalStr = str;
    char* subStr = other.str;
    char* found = strstr(originalStr, subStr);

    if (found == nullptr) { // ���� ������� �� ��������, ��������� ���� ������������ �����
        return String(originalStr, maxLength);
    }

    int subLength = other.getTrueSize();
    int newLength = getTrueSize() - subLength + 1; // +1 ��� ����-����������
    char* newStr = new char[newLength];

    // ������� ������� ����� �� �������
    copy(originalStr, found, newStr);
    // ������� ������� ����� ���� �������
    copy(found + subLength, originalStr + getTrueSize(), newStr + (found - originalStr));

    return String(newStr, newLength);
}

// �������������� �������� *
bool String::operator*(String& other) {
    return strstr(str, other.str);
}

// �������������� �������� = (���������)
String& String::operator=(String& other) {
    if (this != &other) { // �������� �� �������������
        delete[] str; // ��������� ���'�� ��'����
        maxLength = other.maxLength; // ��������� ����������� �������
        str = new char[maxLength]; // �������� ���� ���'��
        copy(other.str, other.str + maxLength, str); // ��������� �����
    }
   return *this;
}

// �������������� �������� = (����������)
String& String::operator=(String&& other) {
    if (this != &other) { // �������� �� �������������
        delete[] str; // ��������� ���'�� ��'����
        maxLength = other.maxLength; // ��������� ����������� �������
        str = other.str; // ���������� ���������
        other.str = nullptr; // ������� �������� ��������� � ���������� ��'���
        other.maxLength = 0; // ��������� ����������� ������� � ���������� ��'���
    }
    return *this;
}

// �������������� �������� �������� >>
istream& operator>>(istream& is, String& Str) {
    SetConsoleCP(1251);
    int maxLength;
    cout << "������ ������������ ����� �����: ";
    // �������� �� �������� �������� �����
    while (!(is >> maxLength) || maxLength <= 0) {
        cout << "������������ ���! ������ ���� �����: ";
        is.clear();
        is.ignore();
    }

    maxLength += 1;

    char* buffer = new char[maxLength + 1]; // �������� �������� ������
    cout << "������ ����� �������: ";
    is.ignore(); // ���������� ������ ������ �����, ��� �������� �������� �� �������� getline() �� >>.
    is.getline(buffer, maxLength + 1); // ���������� ����� � ������ � �����
    Str = String(buffer, maxLength + 1); // ��������� ��'���� String � ������
    delete[] buffer; // ��������� �������� ������� ���'��
    return is;
}

// �������������� �������� ��������� <<
ostream& operator<<(ostream& os, String& str) {
    os << "�����: " << str.getString() << endl << endl;
    return os;
}