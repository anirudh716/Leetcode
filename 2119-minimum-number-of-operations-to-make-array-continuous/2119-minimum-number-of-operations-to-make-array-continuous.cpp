class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int maxi = 0;    
        int count = 0;   
        int n = nums.size() - 1;  
        int l = 0;      
        sort(nums.begin(), nums.end());  
        for(int i = 0; i < nums.size(); i++) {
            if(i+1 < nums.size() && nums[i] == nums[i+1]) continue;
            nums[l++] = nums[i];
        }

        // Calculate the maximum count of consecutive numbers
        for(int i = 0, j = 0; i < l; i++) {
            while(j < l && (nums[j] - nums[i]) <= n) {
                count++;
                j++;
            }
            maxi = max(maxi, count);
            count--;
        }

        return nums.size() - maxi;
    }
};