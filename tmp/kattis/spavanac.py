#!/bin/python3

import sys

h, m = input().strip().split(' ')
h, m = [int(h), int(m)]
m -= 45
if (m < 0):
    h -= 1
    m += 60
    if (h < 0):
        h = 23

print(h, m)