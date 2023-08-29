class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for (auto num : nums) {
            max_heap.push(-num);
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }
        return -max_heap.top(); // pop() does not reutrn, bruh what
    }
};