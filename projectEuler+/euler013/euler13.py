#!/bin/python3

N = int(input().strip())
sum = 0
for _ in range(N):
    sum += int(input().strip())
print(str(sum)[:10])