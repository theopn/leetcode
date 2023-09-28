class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_sum = 0, curr_sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            curr_sum = std::max(0, curr_sum += prices[i] - prices[i - 1]);
            best_sum = std::max(curr_sum, best_sum);
        }
        return best_sum;
    }
};