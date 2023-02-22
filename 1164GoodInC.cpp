//
// Created by UestcGavei711 on 2022/6/4.
//

#include "iostream"
#include "vector"

using namespace std;
string s[26][7];

int main() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            string line;
            getline(cin, line);
            s[i][j] = line;
        }
    }
    string stp; // string to print
    getline(cin, stp);
    bool is_first = true; // 换行时需要重置
    bool is_first_word = true;
    vector<char> v;
    for (int i = 0; i < stp.size(); ++i) {
        if (stp[i] >= 'A' && stp[i] <= 'Z' && i != stp.size() - 1)
            v.push_back(stp[i]);
        else if (stp[i] < 'A' || stp[i] > 'Z' || i == stp.size() - 1) {
            if (i == stp.size() - 1 && stp[i] >= 'A' && stp[i] <= 'Z')
                v.push_back(stp[i]);
            // 输出v中的字母
            if (v.size()) {
                if (!is_first_word)
                    cout << endl;
                for (int j = 0; j < 7; ++j) {
                    if (j != 0)
                        cout << endl;
                    for (int k = 0; k < v.size(); ++k) {
                        int idx = v[k] - 'A'; // 是哪个字母？
                        if (is_first)
                            cout << s[idx][j], is_first = false;
                        else
                            cout << ' ' << s[idx][j];
                    }
                    is_first = true;
                }
                is_first_word = false;
                v.clear();
                cout << endl;
            }

        }
    }

    return 0;
}