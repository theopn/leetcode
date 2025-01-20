class Solution {
public:
    bool isCircularSentence(string sentence) {
        string word;
        stringstream ss(sentence);
        ss >> word;
        char lastCharOfLastWord = word.back();

        while (ss >> word) {
            if (lastCharOfLastWord != word.front()) {
                return false;
            }
            lastCharOfLastWord = word.back();
        }

        return sentence.front() == sentence.back();
    }
};