class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        //Calculate sum of first k elements
        for(int i = 0; i < k; i++)
            sum += nums[i];
        
        //Initialize maxSum with current sum
        int maxSum = sum;
        for(int i = k; i < nums.size(); i++){
            //update sum by adding the current element and subtracting the element that is k positions behind
            sum += nums[i] - nums[i - k];
            //update maxSum
            maxSum = max(maxSum, sum);
        }

        //return the avg of maxSum
        return static_cast<double>(maxSum) / k;
    }
};