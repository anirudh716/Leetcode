class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        // Convert the integer to a string
        string numStr = to_string(x);
    
        // Initialize pointers
        int i = (x < 0) ? 1 : 0;
        int j = numStr.length() - 1;
    
        // Reverse the string
        while (i < j) {
            swap(numStr[i], numStr[j]);
            i++;
            j--;
        }
    
        // Remove leading zeros
        while (numStr[i] == '0') {
            i++;
        }
    
        // Check for overflow
        long long result = stoll(numStr); // Convert back to long long to check for     overflow
        if (result > INT_MAX || result < INT_MIN) {
            return 0; // Overflow
        }
    
        return static_cast<int>(result); // Convert back to int
    }

};