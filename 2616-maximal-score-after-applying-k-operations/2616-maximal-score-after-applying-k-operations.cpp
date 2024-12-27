class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto num : nums) {
            pq.push(num);
        }

        long long score = 0;
        for (int i = 0; i < k; i++) {
            int num = pq.top();
            pq.pop();
            score += num;
            pq.push(ceil( ((double) num) / 3 ));
        }

        return score;
    }
};