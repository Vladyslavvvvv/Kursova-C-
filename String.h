#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    char* str; // Вказівник на початок рядка у динамічній пам'яті
    int maxLength; // Максимальна довжина рядка

public:
    // Дефолтний конструктор
    String();

    // Конструктор ініціалізації
    String(char* newStr, int newLength);

    // Конструктор копіювання
    String(String& other);

    // Конструктор переміщення
    String(String&& other);

    // Деструктор
    ~String();

    // Метод для встановлення максимальної довжини
    void setLength(int newLength);

    // Метод для встановлення значення рядка
    void setString(char* newStr);

    // Метод для отримання максимальної довжини
    int getLength();

    // Метод для отримання значення рядка
    char* getString();

    // Метод для отримання фактичного розміру рядка
    int getTrueSize();

    // Перевизначення операції +
    virtual String operator+(String& other);

    // Перевантаження операції -
    String operator-(String& other);

    // Перевантаження операції *
    bool operator*(String& other);

    // Перевантаження операції = (Присвоєння)
    String& operator=(String& other);

    // Перевантаження операції = (Переміщення)
    String& operator=(String&& other);

    // Перевантаження операції введення >>
    friend istream& operator>>(istream& is, String& str);

    // Перевантаження операції виведення <<
    friend ostream& operator<<(ostream& os, String& str);
};