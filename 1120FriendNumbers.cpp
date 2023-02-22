//
// Created by UestcGavei711 on 2022/7/12.
//

#include "iostream"
#include "set"

using namespace std;

const int N = 10010;

int n;
set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, sum = 0;
        cin >> x;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        s.insert(sum);
    }
    cout << s.size() << endl;
    bool is_first = true;
    for (auto num : s) {
        if (is_first)
            cout << num, is_first = false;
        else
            cout << " " << num;
    }
    return 0;
}