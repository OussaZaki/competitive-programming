from math import sqrt, floor, log
from decimal import *

context = Context(prec=3000, rounding=ROUND_05UP)
setcontext(context)

phi = Decimal(1 + Decimal(5).sqrt()) / Decimal(2)
psi = Decimal(1 - Decimal(5).sqrt()) / Decimal(2)

def reverse_fib(fn):
    return floor(
        log((fn * sqrt(5) + sqrt(5 * (fn ** 2) - 4)) / 2, phi)
    )

def get_k(n):
    return reverse_fib(n) // 3


def sum_even(k):
    phi3 = context.power(phi, 3)
    psi3 = context.power(psi, 3)
    return int((Decimal(1) / Decimal(5).sqrt()) * (
        phi3 * ((1 - context.power(phi3, k)) / (1 - phi3)) -
        psi3 * ((1 - context.power(psi3, k)) / (1 - psi3))
    ))

t = int(input().strip())
for i in range(t):
    N = int(input().strip())
    k = get_k(N)
    print(sum_even(k))