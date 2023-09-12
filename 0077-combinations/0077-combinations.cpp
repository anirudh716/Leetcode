class Solution {
public:
    void findCombinations(int ind, int n, int k, vector<int> &ds, vector<vector<int>> &ans){
        if(k == 0){
            ans.push_back(ds);
            return;
        }
        if(ind > n)
            return;
            
        ds.push_back(ind);
        findCombinations(ind+1, n, k-1, ds, ans);

        //skip the ind element
        ds.pop_back();
        findCombinations(ind+1, n, k, ds, ans);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(1, n, k, ds, ans);
        return ans;
    }
};