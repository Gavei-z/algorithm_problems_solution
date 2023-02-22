//
// Created by Gavei on 2022/4/15.
//

#include "iostream"
#include "cstring"

using namespace std;
string MN[2][13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
                    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int find(string ori, int p) {
    int res = 0;
    for (int i = 0; i < (p == 1 ? 12 : 13); ++i) {
        if (ori == MN[p][i]) {
            res = (p == 1 ? (i + 1) * 13 : i);
            break;
        }
    }
    return res;
}

int main() {
    string s;
    int n;
    scanf("%d\n", &n);
    while (n--) {
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9') {
            //数字
            int num = stoi(s);
            int digit1 = num / 13, digit2 = num % 13;
            if (num < 13)
                cout << MN[0][digit2] << endl;
            else{
                cout << MN[1][digit1 - 1];
                if (digit2 == 0)
                    cout << endl;
                else
                    cout << " " << MN[0][digit2] << endl;
            }
        } else {
            if (s.length() > 3) {
                int res1 = find(s.substr(0, 3), 1);
                int res2 = find(s.substr(4, 3), 0);
                cout << res1 + res2 << endl;
            } else
                cout << find(s, 0) + find(s, 1) << endl;
        }
    }
    return 0;
}