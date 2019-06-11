# 
#!/usr/bin/env python3
#-*- coding:utf-8 -*-
import sys
import math

f = open('tourist.out', 'w')
sys.stdout = f

INPUT = open(sys.argv[1])
T = int(INPUT.readline().strip())

for t in range(1, T + 1):
    N, K, V = [int(x) for x in INPUT.readline().strip().split(' ')]
    ATTRACTIONS, TMP = [], []
    last_position = ((V - 1) * K % N)
    
    for i in range(N):
        attraction = INPUT.readline().strip()
        if i >= last_position:
            ATTRACTIONS.append(attraction)
        else:
            TMP.append(attraction)
    
    diff = K - len(ATTRACTIONS)
    if diff != 0:
        ATTRACTIONS = TMP[:diff] + ATTRACTIONS

    print('Case #%i: ' %t, end='')
    for i in range(K - 1):
        print(ATTRACTIONS[i], end=' ')
    print(ATTRACTIONS[K - 1])

f.close()
