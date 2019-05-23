#!/bin/python3


def isLeap(year):
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
        return True, 366
    return False, 365

def sundays_count(y0, m0, d0, yf, mf, df) :
    return 0


T = int(input().strip())
for _ in range(T):
    y0, m0, d0 = map(int, input().split())
    yf, mf, df = map(int, input().split())
    print(sundays_count(y0, m0, d0, yf, mf, df))
