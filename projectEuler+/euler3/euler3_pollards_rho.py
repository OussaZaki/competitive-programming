#!/bin/python3

def is_prime(n):
    if n < 2:
        return False

    ps = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]

    def is_spsp(n, a):
        d, s = n-1, 0
        while d % 2 == 0:
            d //= 2; s += 1
            t = pow(a, d, n)

        if t == 1:
            return True
        while s > 0:
            if t == n-1:
                return True

            t = (t*t) % n
            s -= 1
        return False

    if n in ps: return True
    for p in ps:
        if not is_spsp(n,p):
            return False
    return True

# return an array of factors
def rho_factors(n, limit=1000000):
    def gcd(a,b):
        while b: a, b = b, a%b
        return abs(a)

    def rho_factor(n, c, limit):
        f = lambda x : (x*x+c) % n
        t, h, d = 2, 2, 1

        while d == 1:
            t = f(t); h = f(f(h)); d = gcd(t-h, n)
            
        if d == n:
            return rho_factor(n, c+1, limit)

        if is_prime(d):
            return d

        return rho_factor(d, c+1, limit)

    fs = []
    while n % 2 == 0:
        n = n // 2
        fs = [2]
    if n == 1:
        return fs

    while not is_prime(n):
        f = rho_factor(n, 1, limit)
        n = n // f
        fs = fs + [f]
    return sorted(fs + [n])

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(rho_factors(N)[-1])
