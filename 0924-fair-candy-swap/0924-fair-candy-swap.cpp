class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int diff = (accumulate(aliceSizes.begin(), aliceSizes.end(), 0) - accumulate(bobSizes.begin(), bobSizes.end(), 0)) / 2;
        unordered_set<int> st(aliceSizes.begin(), aliceSizes.end());
        for(int b: bobSizes){
            if(st.count(b + diff))
                return {b + diff, b};
        }
        return {0,0};
    }
};