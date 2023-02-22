//
// Created by Gavei on 2022/3/20.
//

// nc 两个共有的相同数字的数量
// nt 两个集合不同数字的数量

#include "iostream"
#include "set"
#include "vector"

using namespace std;

int n, m, k;
int main(){
    cin >> n;
    vector<set<int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> m;
        set<int> s;
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            s.insert(num);
        }
        v[i] = s;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >>b;
        int nc = 0, nt = v[b-1].size();
        for (auto it = v[a-1].begin(); it != v[a-1].end(); it++) {
            if(v[b-1].find(*it) == v[b-1].end())
                nt ++;
            else
                nc ++;
        }
        double res = (double)nc / nt * 100;
        printf("%.1f%%\n", res);
    }
    return 0;
}