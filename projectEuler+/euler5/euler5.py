#!/bin/python3

import functools

def gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def smallest_multiple(n): 
    return int(functools.reduce(lambda x,y: x*y/gcd(x, y), range(1, n + 1)))

T = int(input().strip())
for i in range(T):
    N = int(input().strip())
    print(smallest_multiple(N))
