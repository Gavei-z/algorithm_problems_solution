//
// Created by 10263 on 2023/2/27.
//
//A typical consumer-producer model code
//
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <vector>

using namespace std;

const int MAX_CAPACITY = 10;
int id = 0;

mutex m;
condition_variable cv_csm,cv_pdc;

struct cacheData {
    int id;
    string data;
};
queue<cacheData> q;

void consumerActor() {
    unique_lock<mutex> lck(m);
    cout << "Consumer has got the mutex" << this_thread::get_id << endl;
    cv_csm.wait(lck, [&](){return q.size() > 0;});
    cout << "Consumer got one value" << endl;
    cacheData top = q.front();
    q.pop();
    cout << "Get the top: " << top.id << ' ' << top.data << endl;
    cout << "Consumer unlock" << endl;
    cv_pdc.notify_one();
    return;
}

void producerActor() {
    unique_lock<mutex> lck(m);
    cout << "Producer has got the mutex" << this_thread::get_id <<  endl;
    cv_pdc.wait(lck, [&](){return q.size() < MAX_CAPACITY;});
    string data = to_string(rand());
    cout << "push " << id << ' ' << data << endl;
    q.push({id ++, data});
    cout << "Producer unlock" << endl;
    cv_csm.notify_one();
    return;
}

void consumerTask() {
    while (1) {
        consumerActor();
    }
    return;
}

void producerTask() {
    while (1) {
        producerActor();
    }
    return;
}
void Dispatch(int pcnt, int ccnt) {
    vector<thread> v_pdc;
    for (int i = 0; i < pcnt; ++ i)
        v_pdc.push_back(thread(producerTask));

    vector<thread> v_csm;
    for (int i = 0; i < ccnt; ++ i)
        v_csm.push_back(thread(consumerTask));

    for (auto &x: v_pdc)
        if (x.joinable())
            x.join();
    for(auto &x: v_csm)
        if (x.joinable())
            x.join();
    return ;
}

int main() {
    srand(time(0));
    Dispatch(1,1);
    return 0;
}
