//
// Created by Gavei on 2022/3/2.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct stu {
    int id, Ge, Gi, total;
    vector<int> choice;
};

int n, m, k;
int quota[110], cnt[110];

int cmp(stu a, stu b) {
    if (a.total != b.total)
        return a.total > b.total;
    return a.Ge > b.Ge;
}

int cmp2(stu a, stu b) {
    return a.id < b.id;
}

int main() {
    cin >> n >> m >> k;
    vector<stu> s(n), sch[110];
    for (int i = 0; i < m; ++i) cin >> quota[i];
    for (int i = 0; i < n; ++i) {
        s[i].id = i;
        cin >> s[i].Ge >> s[i].Gi;
        s[i].total = s[i].Ge + s[i].Gi;
        s[i].choice.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> s[i].choice[j];
        }

    }
    sort(s.begin(), s.end(), cmp);
    // 遍历每一个学生的每一个志愿
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int schid = s[i].choice[j];
            int index = cnt[schid] - 1;
            if (cnt[schid] < quota[schid] ||
                s[i].total == sch[schid][index].total && s[i].Ge == sch[schid][index].Ge) {
                cnt[schid]++;
                sch[schid].push_back(s[i]);
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        sort(sch[i].begin(), sch[i].end(), cmp2);
        for (int j = 0; j < cnt[i]; ++j) {
            if (j != 0) cout << " ";
            cout << sch[i][j].id;
        }
        cout << endl;
    }
    return 0;
}