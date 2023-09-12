class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freqMap;
        int count = 0;
        unordered_set<int> prevFreq;

        for(auto c: s)
            freqMap[c]++;
        
        for(auto f: freqMap){
            int freq = f.second;
            while(freq > 0 && prevFreq.find(freq) != prevFreq.end()){
                freq--;
                count++;
            }
            prevFreq.insert(freq);
        }
        return count;
    }
};