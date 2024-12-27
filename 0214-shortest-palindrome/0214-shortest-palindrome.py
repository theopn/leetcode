class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # KMP failure function returns the table with
        # the length of matching prefix and suffix of the substr at given index
        # e.g., s = "abacaaba"
        # failure[0] ("a") = 0
        # failure[1] ("ab") = 0
        # failure[2] ("|a| b |a|") = 1
        # failure[3] ("abac") = 0
        # failure[4] ("|a| bac |a|") = 1
        # failure[5] ("|a| baca |a|") = 1
        # failure[6] ("|ab| aca |ab|") = 2
        # failure[7] ("|aba| ca |aba|") = 3
        # so we can get the result of failure(s + some sort of seperator + s.rev) and utilize the failure[-1]
        def failure(s):
            M = len(s)
            lps = [0] * M

            length = 0
            i = 1

            while i < M:
                if s[i] == s[length]:
                    length += 1
                    lps[i] = length
                    i += 1
                else:
                    if length != 0:
                        length = lps[length - 1]
                    else:
                        lps[i] = 0
                        i += 1

            return lps

        rev = s[::-1]
        idx = failure(s + "|" + rev)[-1]

        return rev[:len(s) - idx] + s
