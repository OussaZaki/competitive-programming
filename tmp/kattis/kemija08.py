#!/bin/python3

import sys, math

s = input().strip()
decoded = ""
i = 0
while i < len(s):
    decoded += s[i]
    if s[i] in "aeiou":
        i += 3
    else:
        i += 1
print(decoded)