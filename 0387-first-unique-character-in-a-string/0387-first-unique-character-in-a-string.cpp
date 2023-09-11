class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> charFreq;
        for(auto alpha: s)
            charFreq[alpha]++;

        for(int i=0; i<s.size(); i++){
            if(charFreq[s[i]] == 1)
                return i;
        }
        return -1;
    }
};