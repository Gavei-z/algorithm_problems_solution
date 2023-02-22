//
// Created by Gavei on 2022/4/17.
//

#include "iostream"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;
const int N = 1010, M = 1440 * 31 + 10;
int n, cost[24];
double sum[M];
struct Record{
    int time;
    string state, ftime;
    bool operator< (const Record& t) const{
        return time < t.time;
    }
};
map<string, vector<Record>> persons;
int main() {
    for (int i = 0; i < 24; ++i)
        cin >> cost[i];
    cin >> n;
    for (int i = 1; i <M; ++i) {
        sum[i] = sum[i-1] + cost[(i - 1) % 1440 / 60];
    }
    char name[25], s[10], format_time[20];
    int month, day, hour, minute;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, s);
        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);
        int m = (day-1) * 1440 + hour * 60 + minute;
        persons[name].push_back({m, s, format_time});
    }

    for (auto person : persons)
    {
        auto name = person.first;
        auto record = person.second;
        sort(record.begin(), record.end());
        double total = 0;
        for (int i = 0; i + 1 < record.size(); ++i) {
            string a = record[i].state, b = record[i + 1].state;
            if (a == "on-line" && b == "off-line")
            {
                if (!total)
                    printf("%s %02d\n", name.c_str(), month);

                double c = (sum[record[i + 1].time] - sum[record[i].time]) / 100;
                printf("%s %s %d $%.2lf\n", record[i].ftime.c_str(), record[i + 1].ftime.c_str(),
                       record[i + 1].time - record[i].time, c);
                total += c;
            }
        }
        if (total)
            printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}