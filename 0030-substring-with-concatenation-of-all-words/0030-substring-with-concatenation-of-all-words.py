class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_hash = {}
        for word in words:
            word_hash[word] = word_hash.get(word, 0) + 1
        word_len = len(words[0])
        total_len = word_len * len(words)
        ans = []
        
        for i in range(0, len(s)):
            curr_hash = {}
            window = s[i:i + total_len]
        
            for j in range(0, len(window), word_len):
                curr_word = window[j:j + word_len]
                curr_hash[curr_word] = curr_hash.get(curr_word, 0) + 1
        
            if curr_hash == word_hash:
                ans.append(i)
        
        return ans
        