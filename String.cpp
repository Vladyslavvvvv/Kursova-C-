#include "String.h"
#include <cstring>
#include <iostream>

using namespace std;

// Метод для доступу до кожного символу
char String::charAt(int index) {
    if (index >= 0 && index < strlen(str)) {
        return str[index];
    }
    else {
        return '\0'; // Повертаємо нульовий символ у випадку невірного індексу
    }
}

// Дефолтний конструктор
String::String() {
    str = new char[1]; // Виділяємо місце для масиву з одним символом для завершального нуль-термінатора
    str[0] = '\0'; // Порожній рядок
    maxLength = 1; // Максимальна довжина по замовчуванню
}

// Конструктор ініціалізації
String::String(char* newStr, int newLength) {
    maxLength = newLength;
    str = new char[maxLength];
    copy(newStr, newStr + maxLength - 1, str);
    str[maxLength - 1] = '\0';
}

// Конструктор копіювання
String::String(String& other) {
    delete[] str; // Звільнення пам'яті об'єкта
    maxLength = other.maxLength; // Оновлення максимальної довжини
    str = new char[maxLength]; // Виділення нової пам'яті
    copy(other.str, other.str + maxLength, str); // Копіювання рядка
}

// Конструктор переміщення
String::String(String&& other) {
    delete[] str; // Звільнення пам'яті об'єкта
    maxLength = other.maxLength; // Оновлення максимальної довжини
    str = other.str; // Переміщення вказівника
    other.str = nullptr; // Нульове значення вказівника у переданому об'єкті
    other.maxLength = 0; // Оновлення максимальної довжини у переданому об'єкті
}

// Деструктор
String::~String() {
    delete[] str;
}

// Метод для встановлення максимальної довжини
void String::setLength(int newLength) {
    maxLength = newLength + 1;
}

// Метод для встановлення значення рядка
void String::setString(char* newStr) {
    copy(newStr, newStr + maxLength - 1, str);
    str[maxLength - 1] = '\0';
}

// Метод для отримання максимальної довжини
int String::getLength() {
    return maxLength - 1;
}

// Метод для отримання значення рядка
char* String::getString() {
    return str;
}

// Метод для отримання фактичного розміру рядка
int String::getTrueSize() {
    return strlen(str);
}

// Перевизначення операції +
String String::operator+(String& other) {
    int newLength = getTrueSize() + other.getTrueSize() + 1; // +1 для нуль-термінатора
    char* newStr = new char[newLength];

    copy(str, str + maxLength, newStr); // Копіюємо перший рядок
    copy(other.str, other.str + other.maxLength, newStr + getTrueSize()); // Додаємо другий рядок

    return String(newStr, newLength);
}

// Перевантаження операції -
String String::operator-(String& other) {
    char* originalStr = str;
    char* subStr = other.str;
    char* found = strstr(originalStr, subStr);

    if (found == nullptr) { // Якщо підрядок не знайдено, повертаємо копію оригінального рядка
        return String(originalStr, maxLength);
    }

    int subLength = other.getTrueSize();
    int newLength = getTrueSize() - subLength + 1; // +1 для нуль-термінатора
    char* newStr = new char[newLength];

    // Копіюємо частину рядка до підрядка
    copy(originalStr, found, newStr);
    // Копіюємо частину рядка після підрядка
    copy(found + subLength, originalStr + getTrueSize(), newStr + (found - originalStr));

    return String(newStr, newLength);
}

// Перевантаження операції *
bool String::operator*(String& other) {
    return strstr(str, other.str);
}

// Перевантаження операції = (Присвоєння)
String& String::operator=(String& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        delete[] str; // Звільнення пам'яті об'єкта
        maxLength = other.maxLength; // Оновлення максимальної довжини
        str = new char[maxLength]; // Виділення нової пам'яті
        copy(other.str, other.str + maxLength, str); // Копіювання рядка
    }
   return *this;
}

// Перевантаження операції = (Переміщення)
String& String::operator=(String&& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        delete[] str; // Звільнення пам'яті об'єкта
        maxLength = other.maxLength; // Оновлення максимальної довжини
        str = other.str; // Переміщення вказівника
        other.str = nullptr; // Нульове значення вказівника у переданому об'єкті
        other.maxLength = 0; // Оновлення максимальної довжини у переданому об'єкті
    }
    return *this;
}

// Перевантаження операції введення >>
istream& operator>>(istream& is, String& Str) {
    int maxLength;
    cout << "Enter the maximum size -1: ";
    // Перевірка на коректне введення числа
    while (!(is >> maxLength) || maxLength <= 0) {
        cout << "Invalid input. Enter an integer: ";
        is.clear();
        is.ignore();
    }

    maxLength += 1;

    char* buffer = new char[maxLength + 1]; // Динамічне виділення буфера
    cout << "Enter the value: ";
    is.ignore(); // Пропускаємо символ нового рядка, щоб уникнути конфлікту між методами getline() та >>.
    is.getline(buffer, maxLength + 1); // Зчитування рядка з потоку в буфер
    Str = String(buffer, maxLength + 1); // Створення об'єкта String з буфера
    delete[] buffer; // Звільнення динамічно виділеної пам'яті
    return is;
}

// Перевантаження операції виведення <<
ostream& operator<<(ostream& os, String& str) {
    os << "String: " << str.getString() << "\tMax. size: " << str.getLength() << "\tTrue size: " << str.getTrueSize() << endl << endl;
    return os;
}