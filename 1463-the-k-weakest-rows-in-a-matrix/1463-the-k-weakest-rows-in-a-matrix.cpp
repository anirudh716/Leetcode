class Solution {
    int calculateSoldierCount(vector<int> &v){
        int low = 0, high = v.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(v[mid]==0){
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return low;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0; i< mat.size(); ++i){
            pq.push({calculateSoldierCount(mat[i]),i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};