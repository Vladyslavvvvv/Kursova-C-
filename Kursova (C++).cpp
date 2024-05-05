#include "BigInt.h"
#include "ArrayBigInt.h"
#include <windows.h>
#include <fstream>

using namespace std;

// Функція для демонстрації пізнього зв'язування
String polym(String& left, String& right) {
	return left + right;
}

int main() {
    SetConsoleOutputCP(1251);

	ifstream inFile;
	ofstream outFile;
	bool Exit = false;

	do {
		int choice;

		cout << "\nЩо потрібно зробити?" << endl;
		cout << "\nПрочитати дані з файлу і знайти суму - 1" << endl;
		cout << "Ввести два числа і знайти суму - 2" << endl;
        cout << "Ввести два числа і знайти різницю - 3" << endl;
		cout << "Ввести два числа і знайти добуток - 4" << endl;
        cout << "Ввести два числа і частку - 5" << endl;
        cout << "Порівняти два числа - 6" << endl;
		cout << "Продемонструвати поліморфізм - 7" << endl;
		cout << "Вийти - 8" << endl;
		cout << "\nВведіть ваш вибір: ";
		cin >> choice;
        cout << endl;

		switch (choice) {
		case 1: {
            int currentIndex = 0; // Індекс поточного символу в масиві поточного числа

            int maxLength;
            long long MAX_SIZE;

            cout << "\nСкільки символів потрібно прочитати з файлу: ";
            cin >> MAX_SIZE;
            cout << "Який максимальний розмір числа у цьому файлі: ";
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
                    if (isdigit(line[i])) {
                        currentNumber[currentIndex++] = line[i]; // Додавання символу до поточного числа
                    }
                    else if (currentIndex > 0) {
                        currentNumber[currentIndex] = '\0'; // Додаємо завершувальний символ
                        BigInt BIGINT(currentNumber, maxLength);
                        ARRAY.Add(BIGINT);

                        currentIndex = 0; // Скидаємо індекс для наступного числа
                    }
                }
            }

            BigInt SUM = ARRAY.Sum();

            // 
            cout << "Сума = " << SUM << endl;

            // Запис суми у файл
            outFile << "Сума = " << SUM << endl;

            delete[] currentNumber;
            delete[] line;

            outFile.close();
            inFile.close();

            cout << "Сума чисел записана у файл!" << endl;

            break;
		}

        case 2: {
            BigInt B1, B2, B3;

            cout << "Введіть перше число" << endl;
            cin >> B1;

            cout << "Введіть друге число" << endl;
            cin >> B2;

            B3 = B1 + B2;

            cout << "Сума = " << B3 << endl;

            break;
        }

        case 3: {
            BigInt B1, B2, B3;

            cout << "Введіть перше число" << endl;
            cin >> B1;

            cout << "Введіть друге число" << endl;
            cin >> B2;

            B3 = B1 - B2;

            cout << "Різниця = " << B3 << endl;

            break;
        }
              
        case 4: {
            BigInt B1, B2, B3;
            cout << "Введіть перше число" << endl;
            cin >> B1;
            cout << "Введіть друге число" << endl;
            cin >> B2;

            B3 = B1 * B2;

            cout << "Добуток = " << B3 << endl;

            break;
        }

        case 5: {
            BigInt B1, B2, B3;
            cout << "Введіть перше число" << endl;
            cin >> B1;
            cout << "Введіть друге число" << endl;
            cin >> B2;

            B3 = B1 / B2;

            cout << "Частка (заокруглена до більшого) = " << B3 << endl;

            break;
        }
              
        case 6: {
            BigInt B1, B2;
            cout << "Введіть перше число" << endl;
            cin >> B1;
            cout << "Введіть друге число" << endl;
            cin >> B2;

            if (B1 > B2) {
                cout << "Перше число більше за друге" << endl;
            }
            else if (B1 < B2) {
                cout << "Перше число менше за друге" << endl;
            }
            else if (B1 == B2) {
                cout << "Числа рівні" << endl;
            }

            break;
        }

        case 7: {
            BigInt B1;
            String S2, S3;

            cout << "Введіть велике ціле число" << endl;
            cin >> B1;

            cout << "Введіть рядок символів" << endl;
            cin >> S2;

            cout << "\nВиклик функції для праметрів BigInt і String: ";
            S3 = polym(B1, S2);
            cout << S3;

            cout << "Виклик функції для праметрів String і BigInt: ";
            S3 = polym(S2, B1);
            cout << S3;

            cout << "Виклик функції для праметрів BigInt і BigInt: ";
            S3 = polym(B1, B1);
            cout << S3;

            cout << "Виклик функції для праметрів String і String: ";
            S3 = polym(S2, S2);
            cout << S3;

            break;
        }

        case 8: {
            Exit = true;

            break;
        }

        default: {
            cout << "\nНеправильний вибір! Спробуйте знову." << endl;

            break;
        }
		}

	} while (Exit == false);

	return 0;
}