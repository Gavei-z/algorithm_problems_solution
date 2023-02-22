//
// Created by Gavei on 2022/4/19.
//

#include "iostream"
#include "vector"
using namespace std;

int n, b;
vector<int> v;
bool check(){
    for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
        if (v[i] != v[j])
            return false;
    }
    return true;
}
int main(){
    cin >> n >> b;
    if (n == 0) v.push_back(0);
    while (n){
        v.push_back(n % b);
        n /= b;
    }
    if (check())
        cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << v.back();
    for (int i = v.size() - 2; i >= 0; --i)
        cout << " " <<v[i];
    return 0;
}