#!/bin/python3

import sys, math

h, v = input().strip().split(' ')
h, v = [int(h), int(v)]
print(math.ceil(h / math.sin(math.radians(v))))
