#!/bin/python3

def sieve(N):
    primes = []
    sieve = [True] * (N + 1)
    for i in range(2, N + 1, 1):
        if sieve[i]:
            primes.append(i)
            for multiple in range(i * i, N + 1, i):
                sieve[multiple] = False
    return primes

def sum_until(primes, end):
    sum = 0
    for p in primes:
        if p <= end: sum += p
        else: break
    return sum

T = int(input().strip())
primes = sieve(10 ** 6)
for _ in range(T):
    N = int(input().strip())
    print(sum_until(primes, N))