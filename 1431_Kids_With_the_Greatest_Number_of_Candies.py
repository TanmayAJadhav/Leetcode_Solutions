candies = [2,3,5,1,3]
extraCandies = 3

result = list(map(lambda candy: (candy + extraCandies) >= max(candies), candies))
print(result)