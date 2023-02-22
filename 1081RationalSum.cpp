//
// Created by UestcGavei711 on 2022/7/3.
//

#include "iostream"

using namespace std;

typedef long long LL;
const int N = 110;
LL n, nume[N], demo[N];

LL gca(LL a, LL b) {
    if (b == 0)
        return a;
    return gca(b, a % b);
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &nume[i], &demo[i]);
        LL g = gca(nume[i], demo[i]);
        nume[i] = nume[i] / g;
        demo[i] = demo[i] / g;
    }
    LL resnume = nume[0], resdemo = demo[0];
    for (int i = 1; i < n; ++i) {
        LL t = resdemo * demo[i] / gca(resdemo, demo[i]);
        resnume = resnume * (t / resdemo) + nume[i] * (t / demo[i]);
        resdemo = t;
        LL g = gca(resnume, resdemo);
        resnume = resnume / g;
        resdemo = resdemo / g;
    }
    if (resdemo == 1)
        cout << resnume;
    else {
        if (resnume > resdemo)
            cout << resnume / resdemo << " ";
        cout << resnume % resdemo << "/" << resdemo;
    }
    return 0;
}