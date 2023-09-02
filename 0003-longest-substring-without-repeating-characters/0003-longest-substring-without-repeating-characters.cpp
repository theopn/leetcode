class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curr = 0, longest = 0, head = 0;
        unordered_map<char, int> hash;
        
        for (auto c : s) {
            hash[c]++; // Add the char to the hashmap
            curr++; // Increase the curr window length

            if (hash[c] == 1) { // Current char isn't repeated
                if (curr > longest) {
                    longest = curr;
                }
            } else { // Current char is repeated
                // Shrink the window until curr char is not repeated
                while (hash[c] > 1) {
                    hash[s[head]]--;
                    head++;
                    curr--;
                } // end while
            } // end if
        } // end for

        return longest;
    }
};