#include "BigInt.h"
#include <cstring>
#include <iostream>

using namespace std;

// Метод для доступу до кожного символу
char BigInt::charAt(int index) {
    if (index >= 0 && index < strlen(str)) {
        return str[index];
    }
    else {
        return '\0'; // Повертаємо нульовий символ у випадку невірного індексу
    }
}

// Реверс масиву символів
char* BigInt::reverseString(char* Str) {
    int len = strlen(Str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = Str[i];
        Str[i] = Str[len - i - 1];
        Str[len - i - 1] = temp;
    }
    return Str;
}

// Конструктор копіювання
BigInt::BigInt(BigInt& other) {
    delete[] str; // Звільнення пам'яті об'єкта
    maxLength = other.maxLength; // Оновлення максимальної довжини
    str = new char[maxLength]; // Виділення нової пам'яті
    copy(other.str, other.str + maxLength, str); // Копіювання рядка
}

// Конструктор переміщення
BigInt::BigInt(BigInt&& other) {
    delete[] str; // Звільнення пам'яті об'єкта
    maxLength = other.maxLength; // Оновлення максимальної довжини
    str = other.str; // Переміщення вказівника
    other.str = nullptr; // Нульове значення вказівника у переданому об'єкті
    other.maxLength = 0; // Оновлення максимальної довжини у переданому об'єкті
}

// Оператор присвоєння об'єкта BigInt
BigInt& BigInt::operator=(BigInt& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        String::operator=(other); // Викликаємо оператор присвоєння базового класу
    }
    return *this;
}

// Оператор присвоєння об'єкта String
BigInt& BigInt::operator=(String& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        String::operator=(other); // Викликаємо оператор присвоєння базового класу
    }
    return *this;
}

// Оператор переміщення об'єкта BigInt
BigInt& BigInt::operator=(BigInt&& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        String::operator=(other); // Викликаємо оператор присвоєння базового класу
    }
    return *this;
}

// Оператор переміщення об'єкта String
BigInt& BigInt::operator=(String&& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        String::operator=(other); // Викликаємо оператор присвоєння базового класу
    }
    return *this;
}

// Оператор додавання
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

    reverseString(result); // Реверс результату

    return String(result, maxlen + 2);
}

// Оператор віднімання
BigInt BigInt::operator-(BigInt& other) {
    if (*this < other) {
        cout << "Перше число менше за друге! Програма не може працювати з від'ємними значеннями." << endl;
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

        // Визначаємо більшу довжину для вирахування різниці
        int maxlen = len1 > len2 ? len1 : len2;

        // Виділення пам'яті для результату
        char* result = new char[maxlen + 1];
        result[maxlen] = '\0';

        int borrow = 0;
        int i = len1 - 1;
        int j = len2 - 1;
        int k = maxlen - 1;

        // Вирахування різниці цифр
        while (k >= 0) {
            int digit1 = i >= 0 ? str[i] - '0' : 0;
            int digit2 = j >= 0 ? other.str[j] - '0' : 0;
            int diff = digit1 - digit2 - borrow;

            // Якщо різниця від'ємна, запозичуємо в одиницю від попереднього розряду
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

        // Перевірка на нулі на початку
        int idx = 0;
        while (result[idx] == '0') {
            idx++;
        }

        // Повертаємо результат як BigInt
        return BigInt(result + idx, maxlen - idx + 1);
    }
}

// Оператор множення
BigInt BigInt::operator*(BigInt& other) {
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    int maxlen = len1 + len2; // Максимальна можлива довжина результуючого числа

    // Виділення пам'яті для результату
    char* result = new char[maxlen + 1];
    for (int i = 0; i < maxlen; ++i) {
        result[i] = '0'; // Ініціалізація всіх цифр результату нулями
    }
    result[maxlen] = '\0';

    // Обчислення добутку
    for (int i = len1 - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; --j) {
            int digit1 = str[i] - '0';
            int digit2 = other.str[j] - '0';
            int product = digit1 * digit2 + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = product % 10 + '0';
        }
        result[i] += carry; // Додаємо залишок перенесення до попереднього розряду
    }

    // Перевірка на нулі на початку
    int i = 0;
    while (result[i] == '0') {
        i++;
    }

    // Повертаємо результат як BigInt
    return BigInt(result + i, maxlen + 1);
}

// Оператор ділення
BigInt BigInt::operator/(BigInt& other) {
    // Ініціалізація результату ділення як нульове BigInt
    char* b1 = new char[2];
    b1[0] = '0';
    b1[1] = '\0';
    BigInt result(b1, 2);

    char* b2 = new char[2];
    b2[0] = '1';
    b2[1] = '\0';
    BigInt quotient(b2, 2);

    // Копія діленого, яку будемо змінювати
    BigInt dividend = *this;

    // Поки ділене більше або дорівнює дільнику
    while (dividend > other) {
        dividend = dividend - other; // Віднімаємо дільник від діленого
        result = result + quotient; // Інкрементуємо результат
    }

    result = result + quotient;

    // Повернення результату ділення
    return result;
}

// Оператор більше
bool BigInt::operator>(BigInt& other) {
    // Перевіряємо довжини об'єктів
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    if (len1 > len2) {
        return true; // Якщо перший об'єкт має більшу довжину, він більший
    }
    else if (len1 < len2) {
        return false; // Якщо перший об'єкт має меншу довжину, він менший
    }
    // Якщо довжини рівні, порівнюємо числові значення
    for (int i = 0; i < len1; ++i) {
        if (str[i] > other.str[i]) {
            return true;
        }
        else if (str[i] < other.str[i]) {
            return false;
        }
    }
    // Якщо обидва об'єкти рівні
    return false;
}

// Оператор менше
bool BigInt::operator<(BigInt& other) {
    // Перевіряємо довжини об'єктів
    int len1 = strlen(str);
    int len2 = strlen(other.str);
    if (len1 < len2) {
        return true; // Якщо перший об'єкт має меншу довжину, він менший
    }
    else if (len1 > len2) {
        return false; // Якщо перший об'єкт має більшу довжину, він більший
    }
    // Якщо довжини рівні, порівнюємо числові значення
    for (int i = 0; i < len1; ++i) {
        if (str[i] < other.str[i]) {
            return true;
        }
        else if (str[i] > other.str[i]) {
            return false;
        }
    }
    // Якщо обидва об'єкти рівні
    return false;
}

// Оператор рівне
bool BigInt::operator==(BigInt& other) {
    return strcmp(str, other.str) == 0; // Просто порівняння кожного символу
}

// Оператор не рівне
bool BigInt::operator!=(BigInt& other) {
    return strcmp(str, other.str) != 0;
}

// Оператор більше рівне
bool BigInt::operator>=(BigInt& other) {
    return strcmp(str, other.str) >= 0;
}

// Оператор менше рівне
bool BigInt::operator<=(BigInt& other) {
    return strcmp(str, other.str) <= 0;
}

// Перевантаження операції введення >>
istream& operator>>(istream& is, BigInt& bigint) {
    bool flag = false;
    long long int maxSize;

    cout << "Введіть максимальний розмір великого цілого числа: ";
    while (!(is >> maxSize) || maxSize <= 0) {
        cout << "Неправильний ввід! Введіть ціле число: ";
        is.clear();
        is.ignore();
    }

    maxSize++;

    char* input = new char[maxSize + 1];

    cout << "Введіть велике ціле число: ";
    is >> input;

    // Перевірка на наявність лише цифр у введеному рядку
    bool isValid = true;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!isdigit(input[i])) {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "Неправильний ввід! Введіть ціле число: " << endl;
        // Звільнення виділеної пам'яті перед виходом з функції
        delete[] input;
        // Очищення потоку вводу від неправильних символів
        is.clear();
        // Видалення неправильного введення з потоку
        is.ignore();
        // Рекурсивний виклик для повторного введення
        return operator>>(is, bigint);
    }

    bigint = BigInt(input, maxSize);

    delete[] input;

    return is;
}

// Перевантаження операції виведення <<
ostream& operator<<(ostream& os, BigInt& bigint) {
    os << bigint.str;

    return os;
}