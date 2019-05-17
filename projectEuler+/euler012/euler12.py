def tau(n):
    num, i, p = n, 2, 1

    if n == 1: return 1

    while i * i <= num: 
        c = 1
        while num % i == 0:
            num /= i
            c += 1
        i += 1
        p *= c

    if (n == num) or (num > 1):
        p *= 1 + 1

    return p

def divisors_under(n):
    i, triangular_n = 1, 1
    while tau(triangular_n) <= n:
        i += 1
        triangular_n += i
    return triangular_n

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(divisors_under(N))
