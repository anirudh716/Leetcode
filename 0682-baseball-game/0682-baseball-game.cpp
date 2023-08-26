class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st; // Stack to store scores
        int sum = 0; // Total sum of valid scores
        
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "D") { // Double: Double the previous score and add it to the stack
                int x = st.top() * 2;
                st.push(x);
                sum += st.top();
            } 
            else if (operations[i] == "C") { // Cancel: Remove the previous score from the stack and sum
                sum -= st.top();
                st.pop();
            } 
            else if (operations[i] == "+") { // Plus: Add the sum of the two previous scores to the stack
                int temp = st.top();
                st.pop();
                int y = st.top() + temp;
                st.push(temp);
                st.push(y);
                sum += st.top();
            } 
            else { // Integer: Convert the string to an integer and add it to the stack
                st.push(stoi(operations[i]));
                sum += st.top();
            }
        }
        
        return sum; // Return the total sum of valid scores
    }
};
