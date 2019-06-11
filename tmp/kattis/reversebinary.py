#!/bin/python3

import sys

def revbits(x):
    rev = 0
    while x:
        rev <<= 1
        rev += x & 1
        x >>= 1
    return rev

res = revbits(int(input().strip()))
print(res)