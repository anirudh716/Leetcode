class Solution {
public:
    static bool compare(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        return a > b;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[k - 1];
    }
};
