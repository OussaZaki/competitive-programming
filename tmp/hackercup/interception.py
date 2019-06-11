#!/usr/bin/env python3
#-*- coding:utf-8 -*-
import sys
import math

f = open('interception.out', 'w')
sys.stdout = f

INPUT = open(sys.argv[1])
T = int(INPUT.readline().strip())

for t in range(1, T + 1):
    N = int(INPUT.readline().strip())
    for i in range(N):
        coef = int(INPUT.readline().strip())

    print('Case #%i: ' %t, end='')
    for i in range(K - 1):
        print(ATTRACTIONS[i], end=' ')
    print(ATTRACTIONS[K - 1])

f.close()
