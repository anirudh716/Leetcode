class Solution {
public:
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        memset(dp, -1, sizeof dp);
        for(auto word: wordDict)    
            wordSet.insert(word);

        return help(0,s,wordSet);
    }

    int help(int i, string s, unordered_set<string>& wordDict){
        if(i == s.size())
            return 1;
        if(dp[i] != -1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                if(help(j+1, s, wordDict))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
};