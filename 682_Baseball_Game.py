class Solution:
    def calPoints(self, ops: List[str]) -> int:
        res = []
        for i in range(len(ops)):
            if ops[i] == 'C':
                res.remove(res[len(res)-1])
            elif ops[i] == 'D':
                print(res[len(res)-1])
                res.append(2*res[len(res)-1])
            elif ops[i] == '+':
                res.append(res[len(res)-1]+res[len(res)-2])
            else:
                res.append(int(ops[i]))
        return sum(res)   