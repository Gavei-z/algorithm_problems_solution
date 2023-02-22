//
// Created by 10263 on 2022/8/24.
//
#include "iostream"

using namespace std;

int num[] = {1,2,3,1,2,3,1,2,3,1,2,3,
             1,2,3,1,2,3,4,1,2,3,
             1,2,3,4};
int pos[] = {2,2,2,3,3,3,4,4,4,5,5,5,
             6,6,6,7,7,7,7,8,8,8,
             9,9,9,9};
int main() {
    string s;
    while (cin >> s)
    {
        int last = pos[s[0] - 'a'];
        int res = num[s[0] - 'a'];
        for (int i = 1; i < s.size(); ++i) {
            if (pos[s[i] - 'a'] == last)
                res += 2;
            res += num[s[i] - 'a'];
            last = pos[s[i] - 'a'];
        }
        cout << res << endl;
    }
    return 0;
}