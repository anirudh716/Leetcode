class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int totalSum = prices[0] + prices[1];
        if(totalSum - money <= 0)
            return money - totalSum;
        return money;
    }
};