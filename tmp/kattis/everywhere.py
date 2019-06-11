#!/bin/python3

import sys

t = int(input().strip())
for i in range(t):
    s = set()
    n = int(input().strip())
    for j in range(n):
        s.add(input().strip())
    print(len(s))