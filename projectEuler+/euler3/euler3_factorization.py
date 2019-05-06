import math 

def max_prime_factor (n): 
    maxPrime = -1
      
    while n % 2 == 0: 
        maxPrime = 2
        n >>= 1
          
    for i in range(3, int(math.sqrt(n)) + 1, 2): 
        while n % i == 0: 
            maxPrime = i 
            n = n / i 

    if n > 2: 
        maxPrime = n 
      
    return int(maxPrime)
  

t = int(input().strip())
for i in range(t):
    N = int(input().strip())
    print(max_prime_factor(N))