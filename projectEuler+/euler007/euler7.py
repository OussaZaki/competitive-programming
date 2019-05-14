def generate_primes(n)
    isPrime = [True] * n
    p = 2
    while p <= n ** .5:
        if isPrime[p]:
            for i in range(p + p, n, p):
                isPrime[i] = False
        p += 1
    
    primes = []
    for i in range(2, len(isPrime)):
        if isPrime[i]:
            primes.append(i)
    
    return primes

primes = generate_primes(105000)
t = int(input().strip())
for i in range(t):
    N = int(input().strip())
    print(primes[N-1])