//
// Created by UestcGavei711 on 2022/7/11.
//

#include "iostream"
#include "vector"
using namespace std;

const int N = 100010;

int n, v[N], dp[N], dp2[N];
vector<int> arr;
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];

    dp[0] = v[0];
    for (int i = 1; i < n; ++i)
        dp[i] = max(v[i], dp[i - 1]);
    dp2[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i)
        dp2[i] = min(dp2[i + 1], v[i]);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] <= v[i] && dp2[i] >= v[i])
            res++, arr.push_back(v[i]);
    }
    cout << res << endl;

    for (int i = 0; i < arr.size(); ++i) {
        if (i == 0)
            cout << arr[i];
        else
            cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}