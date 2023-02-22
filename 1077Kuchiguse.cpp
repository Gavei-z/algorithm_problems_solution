//
// Created by Gavei on 2022/2/25.
//

#include "iostream"
#include "algorithm"

using namespace std;
int n;

int main() {
    scanf("%d\n", &n);
//    cin >> n;
    string res;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        int len = s.length();
        reverse(s.begin(), s.end());
        if (i == 0) {
            res = s;
        } else {
            int lenres = res.length();
            if (lenres > len) swap(res, s);
            int minlen = min(lenres, len);
            for (int j = 0; j < minlen; ++j) {
                if (res[j] != s[j]){
                    res = res.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(res.begin(),res.end());
    if (res.length() == 0)
        cout << "nai";
    else
        cout << res;
    return 0;
}