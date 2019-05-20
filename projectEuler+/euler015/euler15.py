#!/bin/python3

from math import factorial

mod = 1000000007
T = int(input().strip())
for _ in range(T):
    m, n = [int(x) for x in input().split(" ")]
    print((factorial(m + n) // (factorial(m) * factorial(n))) % 1000000007)