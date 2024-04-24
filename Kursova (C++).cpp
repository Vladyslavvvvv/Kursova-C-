#include "BigInt.h"
#include "ArrayBigInt.h"
#include <fstream>

using namespace std;

// Функція яка демонструє пізнє зв'язування
String polym(String& left, String& right) {
    cout << "Polymorphism works!" << endl;
	return left + right;
}

int main() {
	ifstream inFile;
	ofstream outFile;
	bool Exit = false;

	do {
		int choice;

		cout << "\nWhat should be done?" << endl;
		cout << "\nRead the array from the file and find the sum - 1" << endl;
		cout << "Read the array from the file and find the product - 2" << endl;
		cout << "Enter the numbers yourself and find the sum - 3" << endl;
		cout << "Enter the numbers yourself and find the product - 4" << endl;
		cout << "Demonstrate polymorphism - 5" << endl;
		cout << "Exit - 6" << endl;
		cout << "\nYour choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
            int currentIndex = 0; // Індекс поточного символу в масиві поточного числа

            int maxLength;
            long long MAX_SIZE;

            cout << "\nEnter how many characters to read from the file: ";
            cin >> MAX_SIZE;
            cout << "Enter the maximum number size: ";
            cin >> maxLength;

            char* currentNumber = new char[maxLength];
            char* line = new char[MAX_SIZE];

            ArrayBigInt ARRAY;

            // Відкриття файлу для читання
            inFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Source.txt");
            if (!inFile) {
                cout << "Could not open file for reading!" << endl;
                break;
            }

            // Відкриття файлу для запису
            outFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Result.txt");
            if (!outFile) {
                cout << "Could not open file for writing!" << endl;
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

            // Запис суми у файл
            outFile << "Sum = " << SUM << endl;

            delete[] currentNumber;
            delete[] line;

            outFile.close();
            inFile.close();

            cout << "The sum of the numbers is written to the file!" << endl;

            break;
		}

        case 2: {
            int currentIndex = 0; // Індекс поточного символу в масиві поточного числа

            int maxLength;
            long long MAX_SIZE;

            cout << "\nEnter how many characters to read from the file: ";
            cin >> MAX_SIZE;
            cout << "Enter the maximum number size: ";
            cin >> maxLength;

            char* currentNumber = new char[maxLength];
            char* line = new char[MAX_SIZE];

            ArrayBigInt ARRAY;

            // Відкриття файлу для читання
            inFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Source.txt");
            if (!inFile) {
                cout << "Could not open file for reading!" << endl;
                break;
            }

            // Відкриття файлу для запису
            outFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Result.txt");
            if (!outFile) {
                cout << "Could not open file for writing!" << endl;
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

            BigInt PROD = ARRAY.Prod();

            // Запис суми у файл
            outFile << "Sum = " << PROD << endl;

            delete[] currentNumber;
            delete[] line;

            outFile.close();
            inFile.close();

            cout << "The product of the numbers is written to the file!" << endl;

            break;
        }

        case 3: {
            int size, count = 0, ix = 1;

            ArrayBigInt ARRAY;

            cout << "\nHow many numbers to enter: ";
            cin >> size;

            while (count < size) {
                BigInt B;
                cout << "Digit (" << ix << ")" << ": " << endl;
                ix++;
                cin >> B;
                ARRAY.Add(B);
                count++;
            }

            BigInt SUM = ARRAY.Sum();

            // Відкриття файлу для запису
            outFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Result.txt");
            if (!outFile) {
                cout << "Could not open file for writing!" << endl;
                break;
            }

            // Запис суми у файл
            outFile << "Sum = " << SUM << endl;

            outFile.close();

            cout << "The sum of your numbers is recorded in a file!" << endl;

            break;
        }
              
        case 4: {
            int size, count = 0, ix = 1;

            ArrayBigInt ARRAY;

            cout << "\nHow many numbers to enter: ";
            cin >> size;

            while (count < size) {
                BigInt B;
                cout << "Digit (" << ix << ")" << ": " << endl;
                ix++;
                cin >> B;
                ARRAY.Add(B);
                count++;
            }

            BigInt PROD = ARRAY.Prod();

            // Відкриття файлу для запису
            outFile.open("C:\\Users\\acer\\OneDrive\\Робочий стіл\\2 курс\\Курсова\\Result.txt");
            if (!outFile) {
                cout << "Could not open file for writing!" << endl;
                break;
            }

            // Запис суми у файл
            outFile << "Product = " << PROD << endl;

            outFile.close();

            cout << "The product of your numbers is recorded in a file!" << endl;

            break;
        }

        case 5: {
            int choice1;
            cout << "\nЯкий тип об'єктів треба ввести?" << endl;
            cout << "String - 1" << endl;
            cout << "BigInt - 2" << endl;
            cout << "Your choice: ";
            cin >> choice1;

            switch (choice1) {
            case 1: {
                String S1, S2;
                cout << "\nString 1: ";
                cin >> S1;
                cout << "String 2: ";
                cin >> S2;
                polym(S1, S2);

                break;
            }

            case 2: {
                BigInt B1, B2;
                cout << "\nBigInt 1: ";
                cin >> B1;
                cout << "BigInt 2: ";
                cin >> B2;
                polym(B1, B2);

                break;
            }
            }

            break;
        }

        case 6: {
            Exit = true;

            break;
        }

        default: {
            cout << "Wrong choice. Try again!" << endl;

            break;
        }
		}

	} while (Exit == false);

	return 0;
}