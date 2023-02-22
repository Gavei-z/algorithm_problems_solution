//
// Created by 10263 on 2022/9/24.
//
#include "iostream"
#include "cmath"

using namespace std;
const int N = 998;
int x;

bool check(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main() {
    cin >> x;
    for (int i = 2; i <= N; ++i) {
        for (int j = i; j <= N ; ++j) {
            if (check(i) && check(j) && i * j == x) {
                cout << i << ' ' << j << endl;
            }
        }
    }
    return 0;
}