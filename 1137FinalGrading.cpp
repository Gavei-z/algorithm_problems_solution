//
// Created by UestcGavei711 on 2022/7/13.
//

#include "iostream"
#include "algorithm"
#include "unordered_map"
#include "cmath"

using namespace std;

const int N = 30010;
unordered_map<string, int> mp;

struct student {
    string name;
    int p = -1, m = -1, f = -1, total;

    bool operator<(const student &t) const {
        if (total != t.total)
            return total > t.total;
        else
            return name < t.name;
    }
} students[N];

int p, m, n, cnt = 0;

int main() {
    cin >> p >> m >> n;
    string name; int g;
    for (int i = 0; i < p; ++i) {
        cin >> name >> g;
        if (!mp.count(name))
            mp[name] = cnt++;
        int idx = mp[name];
        students[idx].name = name;
        students[idx].p = g;
    }
    for (int i = 0; i < m; ++i) {
        cin >> name >> g;
        if (!mp.count(name))
            mp[name] = cnt++;
        int idx = mp[name];
        students[idx].name = name;
        students[idx].m = g;
    }

    for (int i = 0; i < n; ++i) {
        cin >> name >> g;
        if (!mp.count(name))
            mp[name] = cnt++;
        int idx = mp[name];
        students[idx].name = name;
        students[idx].f = g;
    }

    for (int i = 0; i < cnt; ++i) {
        if (students[i].m > students[i].f)
            students[i].total = round(0.4 * students[i].m + 0.6 * students[i].f);
        else
            students[i].total = students[i].f;
    }

    sort(students, students + cnt);
    for (int i = 0; i < cnt; ++i) {
        if (students[i].p >= 200 && students[i].total >= 60)
            cout << students[i].name << " " << students[i].p << " " << students[i].m << " " << students[i].f << " " << students[i].total << endl;
    }
    return 0;
}