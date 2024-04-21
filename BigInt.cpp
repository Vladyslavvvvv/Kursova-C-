#include "BigInt.h"
#include <iostream>
#include <cstring>

// Дефолтний конструктор
BigInt::BigInt() : String() {
    size = 1;
    digits = new int[size];
    digits[0] = 0;
    negative = false;
}

// Конструктор з параметром
BigInt::BigInt(String& str) {
    // Отримуємо фактичний розмір рядка
    size = str.getTrueSize();

    // Виділяємо пам'ять для масиву digits
    digits = new int[size];

    // Визначаємо, чи є число від'ємним
    if (str.charAt(0) == '-') {
        negative = true;
        // Починаємо перетворення від наступного символу
        for (int i = 1; i < size; i++) {
            // Припустимо, що символи в рядку представляють цифри, а не букви
            digits[i - 1] = str.charAt(i) - '0'; // Конвертація символу в цифру
        }
        size--;
    }
    else {
        negative = false;
        // Заповнюємо масив digits значеннями з рядка str
        for (int i = 0; i < size; i++) {
            // Припустимо, що символи в рядку представляють цифри, а не букви
            digits[i] = str.charAt(i) - '0'; // Конвертація символу в цифру
        }
    }
}

// Конструктор копіювання
BigInt::BigInt(BigInt& other) {
    size = other.size;

    digits = new int[size];
    for (int i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }

    negative = other.negative;
}

// Конструктор переміщення
BigInt::BigInt(BigInt&& other) : size(0), digits(nullptr) {
    digits = other.digits;
    size = other.size;
    negative = other.negative;

    other.digits = nullptr;
    other.size = 0;
    other.negative = false;
}

// Деструктор
BigInt::~BigInt() {
    delete[] digits;
}

// Оператор переміщення
BigInt& BigInt::operator=(BigInt&& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        // Звільняємо пам'ять поточного об'єкту
        delete[] digits;
        size = 0;
        negative = false;

        // Переміщуємо дані з іншого об'єкту
        digits = other.digits;
        size = other.size;
        negative = other.negative;

        other.digits = nullptr;
        other.size = 0;
        other.negative = false;
    }
    return *this;
}

// Оператор копіювання
BigInt& BigInt::operator=(BigInt& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        // Виділяємо пам'ять для нового масиву
        delete[] digits;
        size = other.size;
        digits = new int[size];

        // Копіюємо дані з іншого об'єкту
        for (int i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }

        negative = other.negative;
    }
    return *this;
}

// Оператор додавання
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

// Оператор віднімання
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

// Оператор множення
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

// Оператор ділення
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

// Метод для перетворення масиву цифр в число
long long BigInt::arrayToNumber(int* digits, int size) {
    long long result = 0;
    for (int i = 0; i < size; ++i) {
        result = result * 10 + digits[i];
    }

    return result;
}

// Метод для перетворення числа в масив цифр
void BigInt::numberToArray(long long number, int*& digits, int& size) {
    // Знаходимо кількість цифр у числі
    long long temp = number;
    size = 0;
    while (temp != 0) {
        temp /= 10;
        size++;
    }

    // Виділяємо пам'ять для масиву цифр
    digits = new int[size];

    // Заповнюємо масив цифр
    temp = number;
    for (int i = size - 1; i >= 0; --i) {
        digits[i] = temp % 10;
        temp /= 10;
    }
}

// Оператор менше
bool BigInt::operator<(BigInt& other) {
    // Перевіряємо знак
    if (negative) {
        return true;
    }
    else {
        return false;
    }

    // Порівнюємо розміри
    if (size < other.size) {
        return true;
    }
    else if (size > other.size) {
        return false;
    }

    // Якщо розміри однакові, порівнюємо почергово розряди, починаючи з найбільшого
    for (int i = 0; i < size; ++i) {
        if (digits[i] < other.digits[i]) {
            return true;
        }
        else if (digits[i] > other.digits[i]) {
            return false;
        }
    }

    // Якщо всі розряди однакові, числа рівні
    return false;
}

// Оператор більше
bool BigInt::operator>(BigInt& other) {
    // Перевіряємо знак
    if (negative) {
        return false;
    }
    else {
        return true;
    }

    // Порівнюємо розміри
    if (size > other.size) {
        return true;
    }
    else if (size < other.size) {
        return false;
    }

    // Якщо розміри однакові, порівнюємо почергово розряди, починаючи з найбільшого
    for (int i = 0; i < size; ++i) {
        if (digits[i] > other.digits[i]) {
            return true;
        }
        else if (digits[i] < other.digits[i]) {
            return false;
        }
    }

    // Якщо всі розряди однакові, числа рівні
    return false;
}

// Оператор рівне
bool BigInt::operator==(BigInt& other) {
    // Перевіряємо знак
    if (negative == other.negative) {
        return true;
    }
    else {
        return false;
    }

    // Порівнюємо розміри
    if (size != other.size) {
        return false;
    }

    // Порівнюємо почергово розряди
    for (int i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }

    // Якщо всі розряди однакові, числа рівні
    return true;
}

// Оператор не рівне
bool BigInt::operator!=(BigInt& other) {
    // Використовуємо вже існуючу реалізацію оператора рівне
    return !(*this == other);
}

// Оператор менше-рівне
bool BigInt::operator<=(BigInt& other) {
    // Використовуємо вже існуючі оператори порівняння '<' та '=='
    return (*this < other) || (*this == other);
}

// Оператор більше-рівне
bool BigInt::operator>=(BigInt& other) {
    // Використовуємо вже існуючі оператори порівняння '>' та '=='
    return (*this > other) || (*this == other);
}

// Оператор виведення
ostream& operator<<(ostream& os, BigInt& bigint) {
    if (bigint.negative) {
        os << "-";
    }

    for (int i = 0; i < bigint.size; i++) {
        os << bigint.digits[i];
    }
    return os;
}

// Оператор введення
istream& operator>>(istream& is, BigInt& bigint) {
    String str;
    bool flag = false;

    do {
        is >> str;
        if (str.charAt(0) == '-') {
            for (int i = 1; i < str.getTrueSize(); i++) {
                if (!isdigit(str.charAt(i))) { // Перевіряємо, чи кожен символ є цифрою
                    flag = false;
                    cout << "Error: Please enter only digits. Try again: " << endl;
                    break; // Виходимо з циклу, якщо знайдено неправильний символ
                }
                else {
                    flag = true;
                }
            }
        }
        else {
            for (int i = 0; i < str.getTrueSize(); i++) {
                if (!isdigit(str.charAt(i))) { // Перевіряємо, чи кожен символ є цифрою
                    flag = false;
                    cout << "Error: Please enter only digits. Try again: " << endl;
                    break; // Виходимо з циклу, якщо знайдено неправильний символ
                }
                else {
                    flag = true;
                }
            }
        }
    } while (flag == false);

    bigint = BigInt(str); // Викликаємо конструктор з параметром для ініціалізації bigint

    return is;
}