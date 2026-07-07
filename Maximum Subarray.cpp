class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1, cur = 0;

        for(int i = 0; i < nums.size(); i++){
            cur += nums[i];
            ans = max(ans, cur);
            if(cur < 0) cur = 0;
        }

        return ans;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);

        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
