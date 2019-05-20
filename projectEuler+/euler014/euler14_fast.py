#!/bin/python3

limit = 5000001

collatz_len = [0, 1] + [0] * limit
max_len = [0, 1] + [1] * limit

def collatz(n):
    if n < limit and collatz_len[n] != 0:
        return collatz_len[n]
    else:
        length = 1 + collatz(3 * n + 1 if n % 2 else n >> 1)
        if n < limit: collatz_len[n] = length
        return length

def precompute_max_length():
    for i in range(2, limit):
        len_i = collatz(i)
        max_len[i] = i if len_i >= collatz_len[max_len[i - 1]] else max_len[i - 1]

T = int(input().strip())
precompute_max_length()
for _ in range(T):
    N = int(input().strip())
    print(max_len[N])
