class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0, end = numbers.size() - 1;
        
        while (front < end) {
            int sum = numbers[front] + numbers[end];
            
            if (sum == target) {
                return { front + 1, end + 1 };
            } else if (sum > target) {
                end--;
            } else {
                front++;
            }
        }
        
        return { -1, -1 };
    }
};