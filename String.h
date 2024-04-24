#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    char* str; // �������� �� ������� ����� � �������� ���'��
    int maxLength; // ����������� ������� �����

public:
    // ��������� �����������
    String();

    // ����������� �����������
    String(char* newStr, int newLength);

    // ����������� ���������
    String(String& other);

    // ����������� ����������
    String(String&& other);

    // ����������
    ~String();

    // ����� ��� ������������ ����������� �������
    void setLength(int newLength);

    // ����� ��� ������������ �������� �����
    void setString(char* newStr);

    // ����� ��� ��������� ����������� �������
    int getLength();

    // ����� ��� ��������� �������� �����
    char* getString();

    // ����� ��� ��������� ���������� ������ �����
    int getTrueSize();

    // �������������� �������� +
    virtual String operator+(String& other);

    // �������������� �������� -
    String operator-(String& other);

    // �������������� �������� *
    bool operator*(String& other);

    // �������������� �������� = (���������)
    String& operator=(String& other);

    // �������������� �������� = (����������)
    String& operator=(String&& other);

    // �������������� �������� �������� >>
    friend istream& operator>>(istream& is, String& str);

    // �������������� �������� ��������� <<
    friend ostream& operator<<(ostream& os, String& str);
};