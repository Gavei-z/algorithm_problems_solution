//
// Created by Gavei on 2022/4/29.
//

#include "iostream"
#include "vector"
using namespace std;

int n;
vector<int> res;
int main() {
    cin >> n;
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0) {
            vector<int> seq;
            for (int m = n, j = i; j <= n / i; ++j) {
                if (m % j == 0){
                    seq.push_back(j);
                    m /= j;
                }
                else
                    break;
            }
            if (seq.size() > res.size())
                res = seq;
        }

    if (res.empty())
        res.push_back(n);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        if (i == 0)
            cout << res[i];
        else
            cout << "*" << res[i];
    }
    return 0;
}