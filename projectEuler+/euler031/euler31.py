#!/bin/python3

MOD = 10 ** 9 + 7
T = int(input().strip())

coins = [1, 2, 5, 10, 20, 50, 100, 200]
count = [1] + [0]*(10 ** 5)

for coin in coins:
    for i in range(coin, 10 ** 5 + 1):
        count[i] += count[i - coin]

for i in range(T):
    N = int(input().strip())
    print(Count[N] % MOD)