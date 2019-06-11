#!/bin/python3

import sys

max = 0
max_i = 0
for i in range(5):
    s = sum([int(x) for x in input().strip().split(' ')])
    if(s > max):
        max = s
        max_i = i + 1
print(max_i, max)