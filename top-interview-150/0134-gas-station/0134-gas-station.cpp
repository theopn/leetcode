class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas = 0, total_gas = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curr_gas += gas[i] - cost[i];
            total_gas += gas[i] - cost[i];
            // Reset
            if (curr_gas < 0) {
                start = i + 1;
                curr_gas = 0;
            }
        }
        return total_gas >= 0 ? start : -1;
    }
};