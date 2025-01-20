class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        int i = 0;
        while (i < word.size()) {
            char currchar = word[i];
            int currlen = 0;
            while (i < word.size() && currlen < 9 && currchar == word[i]) {
                currlen++;
                i++;
            }
            comp += to_string(currlen) + currchar;
        }
        return comp;
    }
};