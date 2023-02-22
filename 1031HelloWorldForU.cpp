//
// Created by UestcGavei711 on 2022/7/20.
//

#include "iostream"
#include "cstring"

using namespace std;

string s;
char src[100][100];
int main() {
    memset(src, ' ', sizeof src);
    cin >> s;
    int len = s.length();
    int n1, n2;
    for (int i = 3; i <= len; ++i) {
        int t = len + 2 - i;
        if (t % 2 == 0 && t / 2 <= i) {
            n1 = t / 2, n2 = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n1; ++i)
        src[i][0] = s[cnt++];
    for (int i = 1; i < n2; ++i)
        src[n1 - 1][i] = s[cnt++];
    for (int i = n1 - 2; i >= 0; --i)
        src[i][n2 -1] = s[cnt++];

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j)
            cout << src[i][j];
        cout << endl;
    }

    return 0;
}