class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter
        
        n, m = len(s1), len(s2)
        if n > m:
            return False

        mp = Counter(s1)
        freq = Counter()

        i = 0
        for j in range(m):
            freq[s2[j]] += 1

            # shrink window if size > n
            if j - i + 1 > n:
                freq[s2[i]] -= 1
                if freq[s2[i]] == 0:
                    del freq[s2[i]]
                i += 1

            # check match
            if freq == mp:
                return True

        return False
