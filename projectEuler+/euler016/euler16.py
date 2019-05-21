#!/bin/python3

def sum_of_digits(N):
    return sum(map(int, str(2 ** N)))

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(sum_of_digits(N))