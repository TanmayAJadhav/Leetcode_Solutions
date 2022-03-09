# Input: accounts = [[1,2,3],[3,2,1]]
# Output: 6
# Explanation:
# 1st customer has wealth = 1 + 2 + 3 = 6
# 2nd customer has wealth = 3 + 2 + 1 = 6
# Both customers are considered the richest with a wealth of 6 each, so return 6.

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
            lst = [sum(i) for i in (accounts)]
            return (max(lst))