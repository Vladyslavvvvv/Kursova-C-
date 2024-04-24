#include "BigInt.h"
#include "ArrayBigInt.h"

using namespace std;

// Функція яка демонструє пізнє зв'язування
String polym(String& left, String& right) {
	cout << "WORK" << endl;
	return left + right;
}

int main() {
	BigInt S1, S2, S3, S4, S5, S6;
	String RES;
	ArrayBigInt ARRAY;

	cin >> S1;
	cout << S1 << endl;
	cin >> S2;
	cout << S2 << endl;

    RES = S1 + S2;
	S3 = S1 * S2;

	cout << "+ : " << RES << endl;
	cout << "* : " << S3 << endl;

	return 0;
}