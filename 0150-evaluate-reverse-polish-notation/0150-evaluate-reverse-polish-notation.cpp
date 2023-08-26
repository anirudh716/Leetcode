class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Stack to store operands

        for (auto val : tokens) {
            if (val == "+" || val == "-" || val == "*" || val == "/") {
                long x = st.top(); st.pop(); // Pop the first operand
                long y = st.top(); st.pop(); // Pop the second operand

                if (val == "+") st.push(y + x); 
                else if (val == "/") st.push(y / x); 
                else if (val == "-") st.push(y - x); 
                else st.push(y * x); 
            } else {
                int n = stoi(val); // Convert string to integer
                st.push(n); // Push the operand onto the stack
            }
        }
        
        return st.top(); // The final result is at the top of the stack
    }
};