//
// Created by Gavei on 2022/4/9.
//

#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include "algorithm"
using namespace std;

map<string,vector<int>> grade;
vector<int> v[4]; // a c m e
int n, m;

int GetRank(vector<int> a, int num)
{
    int l = 0;
    int r = a.size() - 1;
    while (l < r)
    {
        int mid = (l + r  + 1) >> 1;
        if (a[mid] <= num)
            l = mid;
        else r = mid - 1;
    }
    return a.size() - l;
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string id;
        cin >> id;
        int t[4] = {0};
        for (int j = 1; j < 4; ++j) {
            cin >> t[j];
            t[0] += t[j];
        }
        t[0] = round(t[0]/3.0);
        // 输入了三门成绩，求了平均
        for (int j = 0; j < 4; ++j) {
            // 每门成绩放在学生下面
            grade[id].push_back(t[j]);
            v[j].push_back(t[j]);
        }
    }

    for (int i = 0; i < 4; ++i) sort(v[i].begin(), v[i].end());
    char c[] ={"ACME"};
    for (int i = 0; i < m; ++i) {
        string id; cin >> id;
        if(grade.count(id) == 0)
            cout << "N/A" <<endl;
        else{
            //遍历每个成绩的排名
            int res = n + 1; char name;
            for (int j = 0; j < 4; ++j) {
                int rank = GetRank(v[j], grade[id][j]);
                if (rank < res)
                    res = rank, name = c[j];

            }
            cout << res << ' ' <<name << endl;
        }
    }
    return 0;
}