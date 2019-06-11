#!/bin/python3

import sys

s = set()
for i in range(10):
    s.add(int(input().strip()) % 42)
print(len(s))