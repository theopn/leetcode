class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, path):
        node = self.root
        folders = path.split("/")
        for folder in folders:
            if folder not in node.children:
                node.children[folder] = TrieNode()
            node = node.children[folder]
        node.end = True

    def isSubfolder(self, path):
        node = self.root
        folders = path.split("/")
        for i, folder in enumerate(folders):
            node = node.children[folder]
            if node.end and i != len(folders) - 1:
                return False

        return True

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = Trie()
        for path in folder:
            trie.insert(path)

        nonSubs = []
        for path in folder:
            res = trie.isSubfolder(path)
            if (res):
                nonSubs.append(path)

        return nonSubs