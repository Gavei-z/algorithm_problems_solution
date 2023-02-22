//
// Created by Gavei on 2022/7/10.
//

#include "iostream"

using namespace std;
const int N = 100010;
const int MOD = 1000000007;
int P[N], A[N], T[N];
int main(){
    string s;
    cin >> s;
    int p = 0, a = 0, t = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'P')
            p ++;
        else if (s[i] == 'A')
            a ++;
        else
            t ++;
        P[i] = p;
        A[i] = a;
        T[i] = t;
    }
    int res = 0;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == 'A')
            res = (res + P[i] * (T[s.length() - 1] - T[i]) % MOD) % MOD;

    cout << res << endl;
    return 0;
}