//
// Created by Gavei on 2022/2/18.
//

#include "iostream"
#include "cmath"

using namespace std;

int n;

int main() {
    cin >> n;
    int boundary = sqrt(n) + 1;
    int len = 0, first = 0;
    for (int i = 2; i <= boundary; ++i) {
        int num = 1, book = 0;
        for (int j = i; j <= boundary; ++j) {
            num *= j;
            if (n % num != 0) {
                book = j;
                break;
            }
        }

        if (book - i > len) {
            len = book - i ;
            first = i;
        }
    }
    if (first == 0) {
        cout << 1 << endl << n;
    } else {
        cout << len << endl;
        for (int i = 0; i < len; ++i) {
            cout << first + i;
            if (i != len - 1)
                cout << "*";
        }
    }
    return 0;
}