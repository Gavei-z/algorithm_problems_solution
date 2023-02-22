//
// Created by Gavei on 2022/3/13.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
vector<int> prime(50000, 1);

void GeneratePrime() {
    for (int i = 2; i * i < 50000; ++i) {
        for (int j = 2; j * i < 50000; ++j) {
            prime[j * i] = 0;
        }
    }
}

int main() {
    long int n;
    cin >> n;
    bool flag0 = false;
    cout << n << "=";
    if (n == 1) cout << 1;
    else {

        for (int i = 2; i < 50000 && n > 2; ++i) {
            int exp = 0;
            bool flag = false;
            while (prime[i] == 1 && n % i == 0) {
                // 得到指数
                n /= i;
                exp++;
                flag = true;
            }
            if (flag) {
                if (flag0) cout << "*";
                cout << i;
                if (exp >= 2) cout << "^" << exp;
                flag0 = true;
            }
        }
        if (n > 1) cout << (flag0 ? "*" : "") << n;
    }
    return 0;
}