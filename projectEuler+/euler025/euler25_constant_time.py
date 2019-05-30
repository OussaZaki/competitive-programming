#!/bin/python3

from math import ceil, log,

phi = (1 + 5 ** 0.5) / 2


def first_fib_with_N_digits(n):
    "Using Binet's formula"
    return int(ceil((log(10) * (n - 1) + log(5) / 2) / Math.log(phi)))


T = int(input().strip())
for _ in range(T):
    N = int(input())
    print(first_fib_with_N_digits(N))
