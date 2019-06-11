#!/bin/python3

import sys

cards = input().strip()
counts = {'T': 0, 'C': 0, 'G': 0}
for card in cards:
    counts[card] += 1
sum = 0
addSeven = True
for card, count in counts.items():
    sum += count ** 2

min_val = min(counts.values())
print(sum + 7 * min_val)