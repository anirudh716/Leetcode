class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for (char c : s) {
            if (c == '#' && !st1.empty())   st1.pop();
            else if (c != '#')  st1.push(c);
        }

        for (char c : t) {
            if (c == '#' && !st2.empty())   st2.pop(); 
            else if (c != '#')  st2.push(c);
        }

        while (!st1.empty() && !st2.empty()) {
            if (st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }

        return st1.empty() && st2.empty();
    }
};