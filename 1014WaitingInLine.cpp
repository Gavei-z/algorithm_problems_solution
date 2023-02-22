//
// Created by Gavei on 2022/4/12.
//

#include "iostream"
#include "queue"
#include "map"

using namespace std;

const int N = 20;
int n, m, k, q;
int sum[N];
queue<int> Q[N]; //存完成时间
map<int,int> Map;
int main() {
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; ++i) {
        int time;
        cin >> time;
        int t = 0;
        for (int j = 0; j < n; ++j) {
            if (i <= n * m) {
                if (Q[j].size() < Q[t].size())
                    t = j;
            } else {
                if (Q[j].front() < Q[t].front())
                    t = j;
            }
        }
        sum[t] += time;
        if (Q[t].size() >= m)
            Q[t].pop();
//        if (i > n*m) Q[t].pop();
        if (sum[t] - time < 540) { //
            Q[t].push(sum[t]);
            Map[i] = sum[t];

        }

    }
    while(q--)
    {
        int id;
        cin >> id;
        if(Map.count(id)) printf("%02d:%02d\n", Map[id] / 60 + 8, Map[id] % 60);
        else cout << "Sorry" <<endl;
    }
    return 0;
}