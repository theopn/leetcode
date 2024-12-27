class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.accessCount = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()


    """
    modified insert() that also keeping track of the number of time the node is accessed
    """
    def insert(self, word):
        node = self.root

        for c in word:
            i = ord(c) - 97
            if node.children[i] is None:
                node.children[i] = TrieNode()
            node = node.children[i]
            node.accessCount += 1

    
    """
    walk down the trie with the given word and return the accessCounts of the node that it visits
    """
    def countAccessCount(self, word):
        node = self.root
        accessCounts = []

        for c in word:
            i = ord(c) - 97
            # on the second thought, this if case will never happen assuming that the word is already in the trie
            #if node.children[i] is None:
            #    break
            node = node.children[i]
            accessCounts.append(node.accessCount)

        return accessCounts


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()

        # first, inserts all the words in the trie,
        # which also keeps the number of times the node was accessed during each insertion
        for word in words:
            trie.insert(word)

        # now walk the trie and gather the accessCounts at each node == "score" of each prefix
        # accumulate that and add them to one array
        accessCountsAccumulated = []
        for word in words:
            accessCounts = trie.countAccessCount(word)
            accessCountsAccumulated.append(sum(accessCounts))

        return accessCountsAccumulated
        