class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;
        for (char ch : magazine) {
            charCount[ch]++;
        }
        for (char ch : ransomNote) {
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                charCount[ch]--;
            } else {
                return false;
            }
        }
        return true;
        
    }
};