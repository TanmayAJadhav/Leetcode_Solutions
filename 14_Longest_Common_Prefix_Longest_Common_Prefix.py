# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".

# Example 1:
# Input: strs = ["flower","flow","flight"]
# Output: "fl"

    class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        cnt = 0
        minstr = min(map(lambda x: len(x), strs))
        for i in range(minstr):
            letter = strs[0][i]
            if all(strs[i] == letter for strs in strs):
                cnt += 1
            else:
                break
        return strs[0][:cnt]