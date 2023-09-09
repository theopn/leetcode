class Solution:
    def simplifyPath(self, path: str) -> str:
        splits = path.split("/")
        stack = []

        for comp in splits:
            if comp == "" or comp == ".":
                continue
            elif comp == "..":
                if len(stack) != 0:
                    stack.pop()
            else:
                stack.append(comp)
                
        if len(stack) == 0: return "/" # "/" "/.." or something like that
        res = ""
        while len(stack) != 0:
            res = "/" + stack.pop() + res
            
        return res
        