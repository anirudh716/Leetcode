class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // Initialize the answer vector with zeros
        stack<int> st;

        for(int i=0; i<n; i++){
            // Check if the current temperature is higher than the temperature
            // at the index stored in the stack's top
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push(i); // Push the current index onto the stack
        }
        return ans;
    }
};
