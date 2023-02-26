// lc problem 6368, q2 of Single competition 334
//
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> res;
        long long c = 0;
        for (int i = 0; i < n; ++ i) {
            long long x = c * 10 + word[i] - '0';
            if (x % m == 0) res.push_back(1);
            else res.push_back(0);
            c = x % m;
        }
        return res;
    }
};
