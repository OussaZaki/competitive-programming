#!/bin/python3

N = int(input().strip())

_sum = 0
for i in range(10 ** (N - 2), 9 ** N * (N - 1)):
    tmp_sum = 0
    Number = i
    while Number > 0:
        tmp_sum += (Number % 10) ** N
        Number = Number // 10
    if tmp_sum == i:
        _sum += i

print(_sum)