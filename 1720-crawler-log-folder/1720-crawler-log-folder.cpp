class Solution {
public:
    int minOperations(vector<string>& logs) {
        int numop = 0;
        for (auto log : logs) {
            if (log == "../") {
                numop = (numop != 0) ? (numop - 1) : (0);
            } else if (log == "./") {
                continue;
            } else {
                numop++;
            }
        }
        return numop;
    }
};