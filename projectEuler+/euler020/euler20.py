#!/bin/python3

from math import factorial

def sum_factorial_digits (n):
    return sum(map(int, str(factorial(n))))

T = int(input().strip())
for _ in range(T):
    N = int(input())
    print(sum_factorial_digits(N))