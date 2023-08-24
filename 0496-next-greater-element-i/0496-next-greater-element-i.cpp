class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);

        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for (int i = 0; i < n; ++i) {
            if (nextGreater.find(nums1[i]) != nextGreater.end()) {
                ans[i] = nextGreater[nums1[i]];
            }
        }
        return ans;
    }
};