//
// Created by UestcGavei711 on 2022/6/30.
//

#include "iostream"

using namespace std;

const int N = 10005;
int n;
double v[N];
int main(){
    cin >> n;
    double res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        res += v[i] * i * (n - i + 1) ;
    }
    printf("%.2lf", res);
    return 0;
}