class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 1e9;
        function<bool(int)> check = [&](int x) {
            int f[n + 1]; // f[i] 前i家偷窃能力小于等于x的数量
            memset(f, 0, sizeof f);
            f[1] = nums[0] <= x ? 1 : 0;
            for (int i = 2; i <= n; ++ i) {
                f[i] = f[i - 1];
                if (nums[i - 1] <= x) f[i] = max(f[i], f[i - 2] + 1);
            }
            return f[n] >= k;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
            // cout << l << ' ' << r <<  endl;
        }
        return l;
    }
};
