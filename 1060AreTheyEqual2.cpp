//
// Created by Gavei on 2022/3/22.
//

#include "iostream"
#include "cstring"

using namespace std;

string change(string a, int n) {
    int pos = a.find(".");
    if (pos == -1) a += '.', pos = a.find(".");
    string s = a.substr(0, pos) + a.substr(pos + 1);
    while (s.size() && s[0] == '0') s = s.substr(1), pos--;
    if (s.empty()) pos = 0;
    if (s.size() > n) s = s.substr(0, n);
    if (s.size() < n) s += string(n - s.size(), '0');
    return "0." + s + "*10^" + to_string(pos);
}

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    a = change(a, n);
    b = change(b, n);
    if (a == b) cout << "YES " << a;
    else cout << "NO " << a <<" " << b;
    return 0;
}

