//
// Created by UestcGavei on 2022/9/21.
//

#include "iostream"
#include "vector"


using namespace std;


/**
12
tel:+8613812345678
tel:+86138abcd8888
tel:+12345
tel:+86-755-7780000
tel:+86-755-7780000-
sip:zhangsan@huawei.com
sip:z12345@huawei.com
sip:123456@huawei.com
sip:+8613812345678@uc.shenzhen.com
sip:+12345@uc.shenzhen.com
sip:+86-755889900@shenzhen.com
sip:+86-755889900@shen@zhen.com

 */
string s;
int n;
vector<int> v;
bool check (char ch) {
    // 检测号码中的非法字符
    if ((ch >= '0' && ch <= '9') || ch == '-')
        return true;
    return false;
}
bool judge_num(string s) {
    if (s[0] != '+')
        return false;
    int cnt = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] > '0' && s[i] < '9')
            cnt ++;
    }
    if (cnt < 6)
        return false;

    for (int i = 1; i < s.length(); ++i)
        if (s[i] == '-' && s[i - 1] == '-')
            return false;
    if (s[1] == '-' || s[s.length() - 1] == '-')
        return false;

    for (int i = 1; i < s.length(); ++i)
        if (!check(s[i]))
            return false;

    return true;
}

bool judge_letter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

bool judge_ln(char ch) {
    if (ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
        return true;

    return false;
}
int main() {
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s.length() > 128)
            v.push_back(0);

        if (s.substr(0, 3) == "tel") {
            string str = s.substr(4); // 从＋号开始
            if (judge_num(str))
                v.push_back(1);
            else
                v.push_back(0);
            continue;
        }
        else if (s.substr(0, 3) == "sip"){
            bool res = true;
            string str = s.substr(4); // 去除sip:
            int j = 0;
            while (str[j] != '@') j++; // 找到@
            if (j == str.length())
                res = false; // 找不到@
            else {
                string str1 = str.substr(0, j); // @之前的字符串
                if (judge_letter(str1[0])) {
                    // 跟字母 数字字符串
                    if (str1.length() < 6)
                        res = false;
                    for (int i = 0; i < str1.length(); ++i)  // 判断是否是数字和字母
                        if (!judge_ln(str1[i])) {
                            res = false;
                            break;
                        }
                }
                else if (str1[0] == '+'){
                    // 是电话
                    if (!judge_num(str1))
                        res = false;
                }
                else
                    res = false;
                string str2 = str.substr(j + 1); // @ 以后的字符 不包含@
                if (str2[0] == '.' || str2[str2.length() - 1] == '.' || str2.find('.') == string::npos)
                    res = false;
                else {
                    for (int i = 1; i < str2.length(); ++i)
                        if (str2[i] == '.' && str2[i - 1] == '.') {
                            res = false;
                            break;
                        }
                    for (int i = 0; i < str2.length(); ++i) {
                        if (!judge_ln(str2[i]) && str2[i] != '.') {
                            res = false;
                            break;
                        }
                    }
                }
            }
            if (res)
                v.push_back(1);
            else
                v.push_back(0);
            continue;
        }
        v.push_back(0); // 不是 tel 也不是 sip
    }
    bool is_first = true;
    for (int i = 0; i < v.size(); ++i) {
        if (is_first)
            cout << v[i], is_first = false;
        else
            cout << ' ' << v[i];
    }
    return 0;
}