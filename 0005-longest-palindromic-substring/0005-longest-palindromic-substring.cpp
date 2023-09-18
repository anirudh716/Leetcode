class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        
        // Initialize a table to store whether substrings are palindromes
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        // Initialize the longest palindrome to the first character
        string longest = s.substr(0, 1);
        
        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        
        int start = 0; // Start index of the longest palindrome found so far
        int maxLength = 1; // Length of the longest palindrome found so far
        
        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        // Check for palindromes of length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index of the current substring
                
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
