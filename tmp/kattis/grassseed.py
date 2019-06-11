#!/bin/python3

import sys

price = float(input().strip())
n = int(input().strip())
s = 0.0
for i in range(n):
    w, l = input().strip().split(' ')
    w, l = [float(w), float(l)]
    s += w * l * price
print("%.7f" % s)