# You are given an array of integers stones where stones[i] is the weight of the ith stone.We are playing a game with the stones. 
# On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. 
# The result of this smash is:
# If x == y, both stones are destroyed, and
# If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
# At the end of the game, there is at most one stone left.
# Return the smallest possible weight of the left stone. If there are no stones left, return 0.

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        
        while len(stones) != 0:
            stone1 = stones.pop()
            if len(stones) == 0:
                return stone1
            stone2 = stones.pop()
            
            if stone1 > stone2 : 
                for i in range(len(stones)+1):
                    if i == len(stones) or stones[i] >= stone1-stone2:
                        stones.insert(i,stone1 - stone2)
                        break                   
        return 0     
        