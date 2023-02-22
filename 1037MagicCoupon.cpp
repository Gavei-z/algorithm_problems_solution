//
// Created by UestcGavei711 on 2022/7/21.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 100010;
int nc, np;
vector<int> cp, cn, pp, pn;

int main() {
    cin >> nc;
    for (int i = 0; i < nc; ++i) {
        int x;
        cin >> x;
        if (x > 0) cp.push_back(x);
        else if (x < 0) cn.push_back(x);
    }
    cin >> np;
    for (int i = 0; i < np; ++i) {
        int x;
        cin >> x;
        if (x > 0) pp.push_back(x);
        else if (x < 0) pn.push_back(x);
    }
    sort(cp.begin(), cp.end(), greater<int>());
    sort(cn.begin(), cn.end());
    sort(pp.begin(), pp.end(),greater<int>());
    sort(pn.begin(), pn.end());
    int i = 0, res = 0;
    while (i < cp.size() && i < pp.size()) {
        res += cp[i] * pp[i];
        i++;
    }
    i = 0;
    while (i < cn.size() && i < pn.size()) {
        res += cn[i] * pn[i];
        i++;
    }
    cout << res << endl;
    return 0;
}