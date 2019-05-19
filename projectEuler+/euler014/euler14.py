collatz = {1:1}

def iterate (n):
    if n % 2 == 0:
        return n // 2
    return 3 * n + 1

def getCollatz (n):
    if n in collatz:
        return collatz[n]
    else:
        length = getCollatz(iterate(n)) + 1
        collatz[n] = length
        return length

def solve (n):
    max_length = 1
    value = 1
    for i in range(1, n + 1):
        if getCollatz(i) >= max_length:
            max_length = getCollatz(i)
            value = i
    return value


T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(solve(N))