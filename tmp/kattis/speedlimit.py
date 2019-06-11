#!/bin/python3

import sys

n = int(input().strip())
while n != -1:
    old_h, sum = 0, 0
    for i in range (n):
        s, h = input().strip().split(' ')
        s, h = [int(s), int(h)]
        sum += s * (h - old_h)
        old_h = h
    n = int(input().strip())
    print(sum, "miles")