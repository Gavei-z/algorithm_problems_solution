//
// Created by UestcGavei711 on 2022/7/22.
//

#include "iostream"
#include "map"
#include "vector"

using namespace std;

const int N = 100010;
int s1, s2, ne[N], n;
char ad[N];
map<int, bool> mp;

int main() {
    cin >> s1 >> s2 >> n;

    for (int i = 0; i < n; ++i) {
        int add, neadd;
        char num;
        cin >> add >> num >> neadd;
        ad[add] = num;
        ne[add] = neadd;
    }
    while(s1 != -1) {
        mp[s1] = true;
        s1 = ne[s1];
    }
    while (s2 != -1) {
        if (mp[s2]) {
            printf("%05d\n", s2);
            return 0;
        }
        s2 = ne[s2];
    }
    puts("-1");
    return 0;
}