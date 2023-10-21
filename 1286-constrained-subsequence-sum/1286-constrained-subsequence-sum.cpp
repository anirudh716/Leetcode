class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int ret = INT_MIN;
        dp[0] = nums[0];
        ret = max(ret, dp[0]);
        dq.push_back(0);
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(0, dp[dq.front()]) + nums[i];
            ret = max(ret, dp[i]);
            while(!dq.empty() and dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i - k)
                dq.pop_front();
        }
        return ret;
    }
};