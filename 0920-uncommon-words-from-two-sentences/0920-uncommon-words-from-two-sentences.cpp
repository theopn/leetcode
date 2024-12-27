class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1.append(" ");
        s1.append(s2);

        unordered_map<string, int> wordmap;
        int end = s1.find(" ");
        while (end != -1) {
            wordmap[s1.substr(0, end)]++;
            s1.erase(s1.begin(), s1.begin() + end + 1);
            end = s1.find(" ");
        }
        wordmap[s1.substr(0, end)]++;

        vector<string> unique;
        for (auto it : wordmap) {
            if (it.second == 1) unique.push_back(it.first);
        }

        return unique;
    }
};