class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pushIndex = 0;

        for(int popEle: popped){
            while(st.empty() || st.top() != popEle){
                if(pushIndex >= pushed.size())
                    return false;

                st.push(pushed[pushIndex]);
                pushIndex++;
            }
            st.pop();
        }
        return st.empty();
    }
};