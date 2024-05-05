#pragma once
#include "String.h"
#include <iostream>
#include <cstring>

class BigInt : public String
{
public:
	// ����� ��� ������� �� ������� �������
	char charAt(int index);

	BigInt(char* str, int maxSize) : String(str, maxSize) {}

	BigInt() : String() {}

	// ����������� ���������
	BigInt(BigInt& other);

	// ����������� ����������
	BigInt(BigInt&& other);

	// �������� ��������� ��'���� BigInt
	BigInt& operator=(BigInt& other);

	// �������� ��������� ��'���� String
	BigInt& operator=(String& other);

	// �������� ���������� ��'���� BigInt
	BigInt& operator=(BigInt&& other);

	// �������� ���������� ��'���� String
	BigInt& operator=(String&& other);

	// ������ ������ �������
	char* reverseString(char* Str);

	// �������� ���������
	String operator+(String& other) override;

	// �������� ��������
	BigInt operator-(BigInt& other);

	// �������� ��������
	BigInt operator*(BigInt& other);

	// �������� ��������
	BigInt operator/(BigInt& other);

	// �������� �����
	bool operator>(BigInt& other);

	// �������� �����
	bool operator<(BigInt& other);

	// �������� ����
	bool operator==(BigInt& other);

	// �������� �� ����
	bool operator!=(BigInt& other);

	// �������� ����� ����
	bool operator>=(BigInt& other);

	// �������� ����� ����
	bool operator<=(BigInt& other);

	// �������������� �������� �������� >>
	friend istream& operator>>(istream& is, BigInt& bigint);

	// �������������� �������� ��������� <<
	friend ostream& operator<<(ostream& os, BigInt& bigint);
};