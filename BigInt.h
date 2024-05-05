#pragma once
#include "String.h"
#include <iostream>
#include <cstring>

class BigInt : public String
{
public:
	// Метод для доступу до кожного символу
	char charAt(int index);

	BigInt(char* str, int maxSize) : String(str, maxSize) {}

	BigInt() : String() {}

	// Конструктор копіювання
	BigInt(BigInt& other);

	// Конструктор переміщення
	BigInt(BigInt&& other);

	// Оператор присвоєння об'єкта BigInt
	BigInt& operator=(BigInt& other);

	// Оператор присвоєння об'єкта String
	BigInt& operator=(String& other);

	// Оператор переміщення об'єкта BigInt
	BigInt& operator=(BigInt&& other);

	// Оператор переміщення об'єкта String
	BigInt& operator=(String&& other);

	// Реверс масиву символів
	char* reverseString(char* Str);

	// Оператор додавання
	String operator+(String& other) override;

	// Оператор віднімання
	BigInt operator-(BigInt& other);

	// Оператор множення
	BigInt operator*(BigInt& other);

	// Оператор множення
	BigInt operator/(BigInt& other);

	// Оператор більше
	bool operator>(BigInt& other);

	// Оператор менше
	bool operator<(BigInt& other);

	// Оператор рівне
	bool operator==(BigInt& other);

	// Оператор не рівне
	bool operator!=(BigInt& other);

	// Оператор більше рівне
	bool operator>=(BigInt& other);

	// Оператор менше рівне
	bool operator<=(BigInt& other);

	// Перевантаження операції введення >>
	friend istream& operator>>(istream& is, BigInt& bigint);

	// Перевантаження операції виведення <<
	friend ostream& operator<<(ostream& os, BigInt& bigint);
};