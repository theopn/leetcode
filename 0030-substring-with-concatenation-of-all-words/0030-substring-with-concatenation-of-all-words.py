class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        words_counter = Counter(words)
        word_len = len(words[0])
        total_len = word_len * len(words)
        ans = []
        
        for i in range(0, len(s) - total_len + 1): # We could loop through len(s), but that would be a waste
            curr_words = []
            window = s[i:i + total_len]
        
            for j in range(0, len(window), word_len):
                curr_word = window[j:j + word_len]
                curr_words.append(curr_word)
        
            if words_counter == Counter(curr_words):
                ans.append(i)
        
        return ans
        