//
// Created by 10263 on 2022/8/13.
//

#include "iostream"

using namespace std;

const int N = 1010;
int dp[N][N];
void solution1() {
    string s;
    getline(cin, s);
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        int t = 0;
        for (int j = i, k = i; j >= 0 && k < s.size(); --j, ++k) {
            if (s[j] == s[k])
                t++;
            else
                break;
        }
        res = max(res, 2 * t - 1);
        t = 0;
        for (int j = i, k = i + 1; j >= 0 && k < s.size(); --j, ++k) {
            if (s[j] == s[k])
                t++;
            else
                break;
        }
        res = max(res, 2 * t);
    }
    cout << res << endl;
}

void solution2() {
    string s;
    int res = 1;
    getline(cin, s);

    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = 1;
        if (s[i] == s[i + 1] && i + 1 < s.size()) dp[i][i + 1] = 1, res = 2;
    }
    for (int l = 3; l <= s.size(); ++l) {
        for (int i = 0, j = l + i - 1; i + l - 1 < s.size(); ++i, ++j) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] ? 1 :0;
            if (dp[i][j])
                res = max(res, l);
        }
    }
    cout << res << endl;
}

int main() {
    solution2();
    return 0;
}