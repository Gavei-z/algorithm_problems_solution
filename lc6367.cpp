// lc problem 6367, q3 of competition 334
//
//the key is greedy mind, we should create the pair as much as we can
//use double pointer to implement this.
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // cout << n << endl;
        int res = 0;
        for (int i = 0, j = n % 2 == 0 ? n / 2: n / 2 + 1; j < n; ++ i, ++ j) {
            while (j < n && nums[i] * 2 > nums[j]) j ++;
            if (j < n) res += 2;
        }
        return res;
    }
};

