#!/bin/python3
from itertools import accumulate

def primes_upto(limit):
    "Return the list of prime numbers less than the limit passed"
    primes = [2, 3]
    is_prime = [False, False, True, True] + [False, True] * int((limit - 2)/2)
    
    for n in range(3, int(limit ** 0.5 + 1.5), 2):
        if is_prime[n]:
            for i in range(n * n, limit + 1, 2*n):
                is_prime[i] = False

    for i in range(5, limit + 1, 2):
        if is_prime[i]:
            primes.append(i)

    return primes

def sieve(limit):
    "Return the sieve for sum calculation"
    is_prime = [False, False, True, True] + [False, True] * int((limit - 2)/2)
    
    for n in range(3, int(limit ** 0.5 + 1.5), 2):
        if is_prime[n]:
            for i in range(n * n, limit + 1, 2*n):
                is_prime[i] = False

    return is_prime



def accumulate(sieve, limit):
    sums, s = [], 0
    for i in range(0, limit):
        if sieve[i]:
            s += i
        sums.append(s)
    return sums

# Generate sums
limit = 10 ** 6 + 1
sums = accumulate(sieve(limit), limit)
# print(sums)

# Solve
T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(sums[N])