class Solution {
public:
    string makeFancyString(string s) {
        char currchar = '0';
        int currlen = 1;
        string fancy = "";
        for (auto c : s) {
            if (currlen >= 2 && c == currchar) {
                continue;
            }

            fancy += c;
            currlen = (c == currchar) ? (currlen + 1) : (1);
            currchar = c;
        }

        return fancy;
    }
};