//
// Created by Gavei on 2022/4/3.
//

#include "iostream"
using namespace std;

int main(){
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }
    string str = to_string(sum);
    char word[10][10] = {"zero", "one", "two", "three", "four", "five",
                         "six", "seven", "eight", "nine"};
    for (int i = 0; i < str.size(); ++i) {
        if(i != 0)
            cout <<" ";
        cout << word[str[i] - '0'];
    }
    return 0;
}