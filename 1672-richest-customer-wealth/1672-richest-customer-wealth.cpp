class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for (const auto& customer : accounts) {
            int wealth = accumulate(customer.begin(), customer.end(), 0);
            maxi = max(maxi, wealth);
        }
        return maxi;
    }
};