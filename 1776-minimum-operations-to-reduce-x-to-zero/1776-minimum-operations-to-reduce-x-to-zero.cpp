class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int targetSum = accumulate(nums.begin(), nums.end(), 0) - x;
        if(targetSum == 0)  return n;
        int currSum = 0;
        int ans = 0;
        
        while(end < n){
            currSum += nums[end];
            while(currSum > targetSum && start < end){
                currSum -= nums[start];
                start++;
            }
            if(currSum == targetSum)
                ans = max(ans, end - start + 1);

            end++;
        }
        return ans == 0 ? -1 : n - ans;
    }
};