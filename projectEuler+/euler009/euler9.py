#!/bin/python3

def abc(n):
    product = -1
    for a in range(1, n // 3 + 1):
        b = (n**2 - 2 * a * n) // (2 * n - 2 * a)
        c = n - b - a
        if (a**2 + b **2 == c**2) and (a * b * c > product):
            product = a * b * c
    return product
        

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(abc(N))