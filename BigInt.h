#pragma once
#include "String.h"
#include <iostream>
#include <cstring>

class BigInt : public String
{
public:
	int* digits;
	int size;
	bool negative;

public:
	// ��������� �����������
	BigInt();

	// ����������� � ����������
	BigInt(String& str);

	// ����������� ���������
	BigInt(BigInt& other);

	// ����������� ����������
	BigInt(BigInt&& other);

	// ����������
	~BigInt();

	// �������������� �������� = (����������)
	BigInt& operator=(BigInt&& other);

	// �������������� �������� = (���������)
	BigInt& operator=(BigInt& other);

	// �������� ���������
	virtual String operator+(String& other) override;

	// �������� ��������
	BigInt operator-(BigInt& other);

	// �������� ��������
	BigInt operator*(BigInt& other);

	// �������� ������
	BigInt operator/(BigInt& other);

	// �������� �����
	bool operator<(BigInt& other);

	// �������� �����
	bool operator>(BigInt& other);

	// �������� ����
	bool operator==(BigInt& other);

	// �������� �� ����
	bool operator!=(BigInt& other);

	// �������� �����-����
	bool operator<=(BigInt& other);

	// �������� ����-����
	bool operator>=(BigInt& other);

	// ����� ��� ������������ ������ ���� � �����
	long long arrayToNumber(int* digits, int size);

	// ����� ��� ������������ ����� � ����� ����
	void numberToArray(long long number, int*& digits, int& size);

	// �������� ���������
	friend ostream& operator<<(ostream& os, BigInt& bigint);

	// �������� ��������
	friend istream& operator>>(istream& os, BigInt& bigint);
};