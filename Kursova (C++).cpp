#include "BigInt.h"
#include "ArrayBigInt.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;
    bool flag = false;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    do {
        int choice;

        cout << "\nЩо потрібно зробити?" << endl;
        cout << "\nПрочитати з файлу - 1" << endl;
        cout << "Ввести самостійно - 2" << endl;
        cout << "Вийти - 3" << endl;
        cout << "\nВаш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int currentIndex = 0; // Індекс поточного символу в масиві поточного числа

            int maxLength;
            long long MAX_SIZE;

            cout << "\nВведіть скільки символів потрібно прочитати з файлу: ";
            cin >> MAX_SIZE;
            cout << "Введіть максимальний розмір числа: ";
            cin >> maxLength;

            char* currentNumber = new char[maxLength];
            char* line = new char[MAX_SIZE];

            ArrayBigInt ARRAY;

            // Відкриття файлу для читання
            inFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Source.txt");
            if (!inFile) {
                cout << "Не вийшло відкрити файл для читання!" << endl;
                break;
            }

            // Відкриття файлу для запису
            outFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Result.txt");
            if (!outFile) {
                cout << "Не вийшло відкрити файл для запису!" << endl;
                break;
            }

            // Читання рядка з файлу
            if (inFile.getline(line, MAX_SIZE)) {
                for (int i = 0; line[i] != '\0'; ++i) {
                    if (isdigit(line[i]) || line[i] == '-') {
                        currentNumber[currentIndex++] = line[i]; // Додавання символу до поточного числа
                    }
                    else if (currentIndex > 0) {
                        currentNumber[currentIndex] = '\0'; // Додаємо завершувальний символ
                        String STR(currentNumber, maxLength);
                        BigInt BIGINT(STR);
                        ARRAY = ARRAY + BIGINT;

                        currentIndex = 0; // Скидаємо індекс для наступного числа
                    }
                }
            }

            BigInt SUM = ARRAY.Sum();

            // Запис суми у файл
            outFile << "Сума = " << SUM << endl;

            delete[] currentNumber;
            delete[] line;

            outFile.close();
            inFile.close();

            cout << "Суму чисел записано у файл!" << endl;

            break;
        }

        case 2: {
            int size, count = 0, ix = 1;

            ArrayBigInt ARRAY;

            cout << "\nСкільки чисел потрібно ввести: ";
            cin >> size;

            while (count < size) {
                BigInt B;
                cout << "Число (" << ix << ")" << ": " << endl;
                ix++;
                cin >> B;
                ARRAY = ARRAY + B;
                count++;

            }

            BigInt SUM = ARRAY.Sum();

            // Відкриття файлу для запису
            outFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Result.txt");
            if (!outFile) {
                cout << "Не вийшло відкрити файл для запису!" << endl;
                break;
            }

            // Запис суми у файл
            outFile << "Сума = " << SUM << endl;

            outFile.close();

            cout << "Сума ваших чисел записана у файл!" << endl;

            break;
        }

        case 3: {
            flag = true;
            break;
        }

        default: {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }
        }
    } while (!flag);

    return 0;
}