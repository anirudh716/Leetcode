class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long M=1e9+7, ans=0;
        set<int> s(arr.begin(), arr.end());
        map<int, int> mp;
        for(int x : s){
            long curr=1;
            for(int y : s){
                if((long)y * y > (long)x){
                    break;
                }
                if(x%y==0){
                    if(!s.count(x/y)){
                        continue;
                    }
                    if(y != x/y){
                        curr = (curr + (long)2*mp[x/y]*mp[y])%M;
                    }else{
                        curr = (curr + (long)mp[x/y]*mp[y])%M;
                    }
                }
            }
            mp[x]=curr;
            ans=(ans+curr)%M;
        }
        return ans;
    }
};