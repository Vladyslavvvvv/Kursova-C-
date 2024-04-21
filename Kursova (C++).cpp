#include "BigInt.h"
#include "ArrayBigInt.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    BigInt B1, B2, B3, B4, B5, B6;

    cout << "BigInt 1: " << endl;
    cin >> B1;

    cout << "BigInt 2: " << endl;
    cin >> B2;

    cout << endl;

    cout << "B1 = " << B1 << endl;
    cout << "B2 = " << B2 << endl;

    ArrayBigInt array;

    array = array + B1;
    array = array + B2;
    array = array + B1;
    array = array + B2;

    array.Show();
    BigInt SUM = array.sum();

    cout << SUM << endl;

    cout << endl;

    B3 = B1 + B2;
    B4 = B1 - B2;
    B5 = B1 * B2;
    B6 = B1 / B2;

    cout << "B1 + B2 = " << B3 << endl;
    cout << "B1 - B2 = " << B4 << endl;
    cout << "B1 * B2 = " << B5 << endl;
    cout << "B1 / B2 = " << B6 << endl;

    return 0;
}