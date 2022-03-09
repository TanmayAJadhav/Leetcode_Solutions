class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        ans = 0
        for opt in operations:
            if opt[0] == '+' or opt[2] == '+':
                ans = ans + 1
            else:
                ans -= 1
        return ans    