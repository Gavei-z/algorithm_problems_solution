//
// Created by 10263 on 2022/9/13.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
vector<int> A;

vector<int> div(vector<int>& A, int b, int& r)
{
    vector<int> res;
    // 从高位开始除
    for (int i = A.size() - 1, t = 0; i >= 0; --i) {
        t = (r * 10 + A[i]);
        res.push_back(t / b);
        r = t % b;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}
int main() {
    string a;
    int b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');
    int r = 0;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    cout << endl << r << endl;
    return 0;
}