//
// Created by UestcGavei711 on 2022/7/12.
//

#include "iostream"
#include "set"
#include "cmath"

using namespace std;

const int N = 100010;

int n, num[N];
set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        s.insert(num[i]);
    }
    int num = 0;
    while (++num) {
        if (!s.count(num)) {
            cout << num << endl;
            break;
        }
    }
    return 0;
}