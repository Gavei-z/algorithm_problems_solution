//
// Created by UestcGavei711 on 2022/7/2.
//

#include "iostream"

using namespace std;

int main(){
    int n, a = 1, left = 0, right = 0, now = 0, res = 0;
    cin >> n;
    while (n / a) {
        left = n / (a * 10), now = n % (a * 10) / a, right = n % a;
        if (now == 0)
            res += left * a;
        else if (now == 1)
            res += left * a + right + 1;
        else
            res += (left + 1) * a;
        a *= 10;
    }
    cout << res << endl;
    return 0;
}