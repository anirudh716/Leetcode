class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string number = to_string(num);
        int n = number.length();
        int count = 0;
        int i = 0, j = 0;

        while (j < n) {
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                string sub = number.substr(i, k);
                int subNum = stoi(sub);
                if (subNum != 0 && num % subNum == 0) { // Corrected condition here
                    count++;
                }
                i++;
                j++;
            }
        }
        return count;
    }
};
