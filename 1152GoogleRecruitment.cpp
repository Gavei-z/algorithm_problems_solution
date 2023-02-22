//
// Created by UestcGavei711 on 2022/6/29.
//

#include "iostream"
#include "cstring"

using namespace std;

int l, k, prime[40000], cnt;
bool st[40000];
string n;

void init(){
    for (int i = 2; i < 40000; ++i) {
        if (!st[i]){
            prime[cnt ++] = i;
            for (int j = i; j < 40000; j += i)
                st[j] = true;
        }
    }
}
bool judge(int num){
    for (int i = 0; prime[i] * prime[i] <= num; ++i) {
        if (num % prime[i] == 0)
            return false;
    }
    return true;
}
int main(){
    cin >> l >> k;
    cin >> n;
    init();
    for (int i = 0; i + k <= n.length(); ++i) {
        string num_str = n.substr(i, k);
        int num = stoi(num_str);
        if (judge(num)){
            cout << num_str;
            return 0;
        }
    }
    cout << 404;
    return 0;
}