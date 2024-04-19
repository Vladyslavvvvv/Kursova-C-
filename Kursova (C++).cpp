#include "BigInt.h"
#include "String.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    BigInt B1;
    String B2, BB;

    cout << "BigInt 1: " << endl;
    cin >> B1;

    cout << "BigInt 2: " << endl;
    cin >> B2;

    cout << "B1 = " << B1 << endl;
    cout << "B2 = " << B2 << endl;

    BB = move(B1 + B2);

    //BB = B1 + B2;
    //B4 = B1 - B2;
    //B5 = B1 * B2;
    //B6 = B1 / B2;

    cout << "B1 + B2 = " << BB << endl;
    //cout << "B1 - B2 = " << B4 << endl;
    //cout << "B1 * B2 = " << B5 << endl;
    //cout << "B1 / B2 = " << B6 << endl;

    return 0;
}