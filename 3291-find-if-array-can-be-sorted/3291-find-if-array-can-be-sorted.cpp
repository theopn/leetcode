class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num &= (num - 1);
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int currSegmentBits = countSetBits(nums[0]);
        int currSegmentMin = nums[0];
        int currSegmentMax = nums[0];
        int prevSegmentMax = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            int currBits = countSetBits(nums[i]);
            if (currBits == currSegmentBits) {
                // Segment continues, update min and max
                currSegmentMin = min(currSegmentMin, nums[i]);
                currSegmentMax = max(currSegmentMax, nums[i]);
            } else {
                // segment of consecutive n-bit integers ended, check if the min of the segment is greater than the prev max
                if (prevSegmentMax > currSegmentMin) {
                    return false;
                }

                // if everything is in order, let the element be the start of the new segment
                prevSegmentMax = currSegmentMax;
                currSegmentMin = nums[i];
                currSegmentMax = nums[i];
                currSegmentBits = currBits;
            }
        }

        return prevSegmentMax < currSegmentMin;
    }
};
