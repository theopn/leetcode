class TrieNode:
    def __init__(self):
        self.children = [None] * 10


class Trie:
    def __init__(self):
        self.root = TrieNode()


    """
    walks down the trie,
    and when it cannot walk down anymore, inserts a new node
    """
    def insert(self, key):
        curr = self.root

        for c in str(key):
            i = int(c)
            if not curr.children[i]:
                curr.children[i] = TrieNode()
            curr = curr.children[i]


    """
    walks down the trie while keeping the num of nodes encountered,
    and when it cannot walk down anymore, it returns the number
    """
    def findLongestCommonPrefix(self, key):
        curr = self.root
        longest = 0

        for c in str(key):
            i = int(c)
            if not curr.children[i]:
                break
            longest += 1
            curr = curr.children[i]

        return longest


class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        trie = Trie()

        # build a trie for elements in arr2
        for key in arr1:
            trie.insert(key)

        # find longest prefix in each elemeent of arr2
        longest = 0
        for key in arr2:
            # optimization since if the key is shorter than the longest prefix so far,
            # it cannot possibly have the longest common prefix in it
            if len(str(key)) > longest:
                longest = max(longest, trie.findLongestCommonPrefix(key))

        return longest