//
// Created by 10263 on 2022/8/10.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
const int N = 100010;
int n, k, m;
int book[210];

struct Person {
    string name;
    int age, w;

    bool operator<(const Person &t) const {
        if (w != t.w)
            return w > t.w;
        if (age != t.age)
            return age < t.age;
        return name < t.name;
    }
};

int main() {
    cin >> n >> k;
    vector<Person> persons;
    for (int i = 0; i < n; ++i) {
        char name[10];
        int age, w;
        scanf("%s %d %d", name, &age, &w);
        persons.push_back({name, age, w});
    }
    sort(persons.begin(), persons.end());
    vector<Person> v;
    for (int i = 0; i < persons.size(); ++i) {
        Person p = persons[i];
        if (book[p.age] <= 100)
            v.push_back(p), book[p.age]++;
    }
    for (int i = 1; i <= k; ++i) {
        int cnt, a, b;
        cin >> cnt >> a >> b;
        vector<Person> res;
        for (int j = 0; j < v.size(); ++j) {
            if (v[j].age >= a && v[j].age <= b)
                res.push_back(v[j]);
        }
        printf("Case #%d:\n", i);
        for (int j = 0; j < res.size() && j < cnt; ++j) {
            cout << res[j].name << " " << res[j].age << " " << res[j].w << endl;
        }
        if (!res.size())
            cout << "None" << endl;
    }
    return 0;
}