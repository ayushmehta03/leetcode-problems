class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        map_s_t = {}
        map_t_s = {}

        for ch1, ch2 in zip(s, t):
            if (ch1 in map_s_t and map_s_t[ch1] != ch2) or (ch2 in map_t_s and map_t_s[ch2] != ch1):
                return False
            map_s_t[ch1] = ch2
            map_t_s[ch2] = ch1

        return True


# ✅ Sample usage
if __name__ == "__main__":
    sol = Solution()
    s = "paper"
    t = "title"
    print(f"Are '{s}' and '{t}' isomorphic? ->", sol.isIsomorphic(s, t))
