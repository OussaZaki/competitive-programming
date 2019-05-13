#!/bin/python3
import math

def max_prime_factor(n): 
    maxPrime = -1
    
    # We keep dividing n by 2 to get rid of all the even composite factors.
    while n % 2 == 0: 
        maxPrime = 2
        n >>= 1 # equivalent to n //= 2
    
    # We loop over the possible odd factors.
    # to remove the rest of the composites, and updating maxPrime to the largest factor.
    for i in range(3, int(math.sqrt(n)) + 1, 2): 
        while n % i == 0: 
            maxPrime = i 
            n //= i 
    
    # If at this stage n is is still bigger than 2
    # then n must be prime so we return it, otherwise we return maxPrime
    return n if n > 2 else maxPrime
  

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(max_prime_factor(N))