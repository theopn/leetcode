class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashbrown = {} # maps Counter(s) to s
        for s in strs:
            counter = "".join(sorted(s))
            if counter in hashbrown:
                hashbrown[counter].append(s)
            else:
                hashbrown[counter] = [s]
                
        return list(hashbrown.values())