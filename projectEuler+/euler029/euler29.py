#!/bin/python3

N = int(input().strip())
print(len(set([a ** b for a in range(2, N + 1) for b in range(2, N + 1)])))