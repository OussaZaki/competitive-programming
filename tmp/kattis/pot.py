#!/bin/python3

import sys

n = int(input().strip())
sum = 0
for i in range (n):
    p = input().strip()
    sum += int(p[:-1]) ** int(p[-1])
print(sum)