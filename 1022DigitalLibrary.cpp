//
// Created by Gavei on 2022/4/27.
//

#include "iostream"
#include "map"
#include "cstring"
#include "set"

using namespace std;
map<string, set<int>> title, author, keyw, publisher, py;
int n, m;

void query(map<string, set<int>> &m, string key){
    if (m.count(key) == 0){
        cout << "Not Found" << endl;
    }
    else{
        for (auto out:m[key])
            printf("%07d\n", out);
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id;
        string s;
        scanf("%d\n", &id);
        getline(cin, s);
        title[s].insert(id);
        getline(cin, s);
        author[s].insert(id);
        getline(cin, s);
        int p = 0, head = 0;
        while(p < s.size()){
            if (s[p] == ' '){
                string subs;
                subs = s.substr(head, p - head);
                keyw[subs].insert(id);
                head = p + 1;
            }
            p ++;
        }
        keyw[s.substr(head)].insert(id);
        getline(cin, s);
        publisher[s].insert(id);
        getline(cin, s);
        py[s].insert(id);
    }
    scanf("%d\n", &m);
    for (int i = 1; i <= m; ++i) {
        string in;
        getline(cin, in);
        cout << in << endl;
        int opnum = stoi(in.substr(0, 1));
        string key = in.substr(3);
        switch (opnum) {
            case 1:
                query(title, key);
                break;
            case 2:
                query(author, key);
                break;
            case 3:
                query(keyw, key);
                break;
            case 4:
                query(publisher, key);
                break;
            case 5:
                query(py, key);
                break;
            default:
                break;
        }
    }
    return 0;
}