class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        x = 0   
        while m < n:
            m = m >> 1
            n = n >> 1
            x += 1
        return m << x