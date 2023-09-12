class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(robRange(nums, 0, nums.size()-2), robRange(nums, 1, nums.size()-1));
    }

    int robRange(vector<int> &nums, int start, int end){
        int currMax = 0;
        int prevMax = 0;
        for(int i=start; i<=end; i++){
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }
        return currMax;
    }
};