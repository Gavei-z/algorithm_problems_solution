//
// Created by Gavei on 2022/4/3.
//

#include "iostream"

using namespace std;

int main(){
    int m;
    cin >> m;
    string open_id, open_time, close_id, close_time;
    for (int i = 0; i < m; ++i) {
        string id, intime, outtime;
        cin >> id >> intime >> outtime;
        if (!i || intime < open_time)
        {
            open_time = intime;
            open_id = id;
        }
        if (!i || outtime > close_time){
            close_time = outtime;
            close_id = id;
        }
    }
    cout << open_id << " " << close_id;
    return 0;
}