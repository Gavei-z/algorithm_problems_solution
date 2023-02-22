//
// Created by 10263 on 2022/9/3.
//
#include "iostream"

using namespace std;

int n, t, k;
int main() {
    cin >> n >> t >> k;
    while (k--)
    {
        int res = 0;
        string s;
        cin >> s;
        int l = s.length();
        if (s[0] == 'f')
            res -= 2;
        if (s[l - 1] == 'a')
            res -= 1;

        for (int i = 0; i < l; ++i) {
            int j = i;
            while (s[j + 1] == s[j]) j ++;
            if (j - i + 1 > 5)
                res += 3;
            i = j;
        }

        for (int i = 0; i < l; ++i) {
            if (s[i] == 'a' && i + 1 < l && (s[i + 1] == 'e' || s[i + 1] == 'h'))
                res -= 4;
        }

        for (int i = 0; i < l; ++i) {
            int j = i;
            while (s[j + 1] - s[j] == 1 && j + 1 < l) j++;
            if (j - i + 1 > 3)
                res += 5;
            i = j;
        }
        cout << res;
        if (res > t)
            cout << "!!!" << endl;
        else
            cout << endl;
    }
    return 0;
}
