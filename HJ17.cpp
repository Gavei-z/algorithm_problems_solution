// This is my first time to write regex, it's awesome
#include <iostream>
#include <vector>
#include <numeric>
#include <regex>
using namespace std;

vector<int> lr, ud;
int main() {
    string str;
    while (cin >> str) { 
        int len = str.length();
        for (int i = 0, j = 0; i < len; ++ i) {
            if (str[i] == ';') {
                string subs = str.substr(j, i - j);
                regex e("^[WASD][0-9]{1,2}$");
                bool f = regex_search(subs, e);
                if (!f) {
                    j = i + 1;
                    continue;
                }
                int num = stoi(subs.substr(1));
                if (subs[0] == 'W') 
                    ud.push_back(num);
                else if (subs[0] == 'S')
                    ud.push_back(-num);
                else if (subs[0] == 'A')
                    lr.push_back(-num);
                else lr.push_back(num);
                j = i + 1;
            }
        }
        int x = accumulate(lr.begin(), lr.end(), 0);
        int y = accumulate(ud.begin(), ud.end(), 0);
        cout << x << ',' << y << endl;
    }
    return 0;
}
