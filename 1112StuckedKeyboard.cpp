//
// Created by UestcGavei711 on 2022/6/1.
//

// 循环判断当前字母和前面是否一样，从第二个开始
#include "iostream"
#include "map"
#include "set"
using namespace std;

int k;
string s;
map<char, int> mp;

int main() {
    cin >> k;
    cin >> s;


    // 预先扫描一遍哪些字符是可以重复的
    for (int i = 0; i < s.size(); ++i) {
        int j = i + 1;
        while (j < s.size() && s[j] == s[i]) j++;
        int len = j - i; // 重复的长度
        if (len % k != 0)
            mp[s[i]] = true;
        i = j - 1;
    }
    string res = "";
    set<char> se;
    for (int i = 0; i < s.size(); ++i) {
        if (mp.count(s[i]) == 0) { // 有重复
            if (se.count(s[i]) == 0)
                cout << s[i], se.insert(s[i]);
            res += s[i];
            i += k - 1;
        }
        else{
            res += s[i];
        }
    }
    cout << endl << res;
    return 0;
}