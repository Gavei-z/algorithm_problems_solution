//
// Created by Gavei on 2022/5/4.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
const int N = 30010;
struct Student {
    string id;
    int score, location, frank, lrank;

    bool operator<(const Student &t) const {
        if (score != t.score)
            return score > t.score;
        else
            return id < t.id;
    }
}stus[310];

int n, k;

int main() {
    cin >> n;
    vector<Student> v;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string id; int score;
            cin >> id >> score;
            stus[j]  = {id, score, i};
        }
        // 局部排序
        sort(stus,stus+k);
        stus[0].lrank = 1;
        v.push_back(stus[0]);
        for (int j = 1; j < k; ++j) {
            int rank = stus[j].score == stus[j - 1].score ?  stus[j - 1].lrank : j + 1;
            stus[j].lrank = rank;
            v.push_back(stus[j]);
        }
    }
    sort(v.begin(), v.end());
    v[0].frank = 1;
    for (int i = 1; i < v.size(); ++i) {
        int rank = v[i - 1].score == v[i].score ? v[i - 1].frank : i + 1;
        v[i].frank = rank;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
        printf("%s %d %d %d\n", v[i].id.c_str(), v[i].frank, v[i].location, v[i].lrank);
    return 0;
}