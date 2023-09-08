class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> patt_to_w;
        unordered_map<string, char> w_to_patt;
        
        for (int i = 0; i < pattern.size(); i++) {
            if (patt_to_w.find(pattern[i]) == patt_to_w.end()) {
                patt_to_w[pattern[i]] = words[i];
            } else if (patt_to_w[pattern[i]] != words[i]) {
                return false;
            }

            if (w_to_patt.find(words[i]) == w_to_patt.end()) {
                w_to_patt[words[i]] = pattern[i];
            } else if (w_to_patt[words[i]] != pattern[i]) {
                return false;
            }
        }

        return true;
    }
};