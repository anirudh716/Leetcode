class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> result;

        for(int i=0; i<n; i++){
            int size = groupSizes[i];
            vector<int> temp;
            for(int j=0; j<n && temp.size() < size; j++){
                if(groupSizes[j] == size){
                    temp.push_back(j);
                    groupSizes[j] = 0;
                }
            }
            if(temp.size() > 0) 
                result.push_back(temp);
        }

        return result;
    }
};