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
	// Дефолтний конструктор
	BigInt();

	// Конструктор з параметром
	BigInt(String& str);

	// Конструктор копіювання
	BigInt(BigInt& other);

	// конструктор переміщення
	BigInt(BigInt&& other);

	// Деструктор
	~BigInt();

	// Перевантаження операції = (Переміщення)
	BigInt& operator=(BigInt&& other);

	// Перевантаження операції = (Присвоєння)
	BigInt& operator=(BigInt& other);

	// Оператор додавання
	virtual String operator+(String& other) override;

	// Оператор віднімання
	BigInt operator-(BigInt& other);

	// Оператор множення
	BigInt operator*(BigInt& other);

	// Оператор ділення
	BigInt operator/(BigInt& other);

	// Оператор менше
	bool operator<(BigInt& other);

	// Оператор більше
	bool operator>(BigInt& other);

	// Оператор рівне
	bool operator==(BigInt& other);

	// Оператор не рівне
	bool operator!=(BigInt& other);

	// Оператор менше-рівне
	bool operator<=(BigInt& other);

	// Оператор білше-рівне
	bool operator>=(BigInt& other);

	// Метод для перетворення масиву цифр в число
	long long arrayToNumber(int* digits, int size);

	// Метод для перетворення числа в масив цифр
	void numberToArray(long long number, int*& digits, int& size);

	// Оператор виведення
	friend ostream& operator<<(ostream& os, BigInt& bigint);

	// Оператор введення
	friend istream& operator>>(istream& os, BigInt& bigint);
};