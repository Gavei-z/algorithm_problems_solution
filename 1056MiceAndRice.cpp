//
// Created by Gavei on 2022/3/9.
//
#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;
int p, g;
struct node{
    int weigh, index, index0, rank;
};

int cmp(node a, node b){
    return a.index0 < b.index0;
}
int main() {
    cin >> p >> g;
    vector<int> w(p);
    vector<node> m(p);
    for (int i = 0; i < p; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < p; ++i) {
        int num; // 顺序
        cin >> num;
        m[i].index = i;
        m[i].index0 = num;
        m[i].weigh = w[num]; // ?
    }

    queue<node> q;
    // 所有老鼠进队
    for (int i = 0; i < p; ++i) {
        q.push(m[i]);
    }

    while(!q.empty()){
        int size = q.size();
        if(size == 1){
            node top = q.front();
            m[top.index].rank = 1;
            break;
        }

        int group = size / g;
        if (size % g != 0)
            group += 1;

        node maxnode;
        int cnt = 0, maxw = -1;
        for (int i = 0; i < size; ++i) {
            node top = q.front();
            cnt ++;
            m[top.index].rank = group + 1;
            q.pop();
            // 更新最大值
            if (top.weigh > maxw)
            {
                maxw = top.weigh;
                maxnode = top;
            }
            if (cnt == g || i == size -1){
                q.push(maxnode);
                cnt = 0;
                maxw = -1;
            }
        }
    }
    sort(m.begin(), m.end(), cmp);
    for (int i = 0; i < p; ++i) {
        if (i != 0)
            cout<<" ";
        cout << m[i].rank;
    }
    return 0;
}