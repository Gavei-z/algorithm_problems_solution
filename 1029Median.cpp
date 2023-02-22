//
// Created by Gavei on 2022/7/31.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 200010;

int n;
vector<int> v;
int main() {
    for (int i = 0; i < 2; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    cout << v[(v.size() - 1) / 2] << endl;
    return 0;
}