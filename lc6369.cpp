// LeetCode problem 6369, q1 of Single week competition 334
//
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int sum[n + 1];
        memset(sum, 0, sizeof sum);
        for (int i = 1; i <= n; ++ i) 
            sum[i] = sum[i - 1] + nums[i - 1];
        vector<int> res;
        for (int i = 1; i <= n; ++ i) {
            res.push_back(abs(sum[i - 1] - (tsum - sum[i])));
        }
        return res;
    }
};
