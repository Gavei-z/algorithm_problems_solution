//
// Created by Gavei on 2022/3/22.
//

#include "iostream"
#include "algorithm"

using namespace std;
const int N = 100010;
struct Person{
    int id, virtue, talent, level;
    int total() const
    {
        return virtue + talent;
    }

    bool operator< (const Person &t) const
    {
        if(level != t.level) return level < t.level;
        if(total() != t.total()) return total() > t.total();
        if(virtue != t.virtue) return virtue > t.virtue;
        else return id < t.id;
    }
}P[N];

int main(){
    int n, l, h;
    cin >> n >> l >> h;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int id, virtue, talent;
        scanf("%d %d %d", &id, &virtue, &talent);
        if(virtue < l || talent < l) continue;
        int level = 0;
        if(virtue >= h && talent >= h) level = 1;
        else if(virtue >= h && talent < h) level = 2;
        else if(virtue < h && talent < h && virtue >= talent) level = 3;
        else level = 4;
        P[cnt++]  = {id, virtue, talent, level};
    }
    sort(P, P+cnt);
    cout << cnt <<endl;
    for (int i = 0; i < cnt; ++i) {
        printf("%08d %d %d\n", P[i].id, P[i].virtue, P[i].talent);
    }
    return 0;
}


