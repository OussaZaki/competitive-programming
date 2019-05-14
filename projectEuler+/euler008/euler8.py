#!/bin/python3

from operator import mul
from functools import reduce

def max_product(n):
    digits = [int(x) for x in str(n)]
    products = []
    for i in range(0, len(digits) - k):
        products.append(reduce(mul, digits[i:i+k]))
    return max(products)

t = int(input().strip())
for _ in range(t):
    n, k = input().strip().split(' ')
    n, k = [int(n), int(k)]
    num = input().strip()
    
    print(max_product(num))