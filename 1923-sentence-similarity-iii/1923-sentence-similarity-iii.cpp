class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string word;
        stringstream ss1(sentence1);
        vector<string> words1;
        while (ss1 >> word) words1.push_back(word);
        stringstream ss2(sentence2);
        vector<string> words2;
        while (ss2 >> word) words2.push_back(word);

        int m = words1.size(), n = words2.size();

        int commonPrefixWords = 0;
        for (int i = 0; i < min(m, n); i++) {
            if (words1[i] == words2[i]) commonPrefixWords++;
            else break;
        }
        
        int commonSuffixWords = 0;
        int i = m - 1;
        int j = n - 1;
        for (int i = m - 1, j = n - 1; i >=0 && j >= 0; i--, j--) {
            if (words1[i] == words2[j]) commonSuffixWords++;
            else break;
        }

        return (commonPrefixWords + commonSuffixWords) >= min(m, n);
    }
};