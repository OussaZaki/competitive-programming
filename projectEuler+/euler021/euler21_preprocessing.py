#!/bin/python3

amicable_numbers = [284, 220, 1210, 1184, 2924, 2620, 5564, 5020, 6368, 6232, 10856, 10744, 14595, 12285, 18416, 17296, 76084, 66992, 66928, 71145, 87633, 67095, 63020, 88730, 69615, 79750]

def sum_amicable_numbers(n):
    return sum([amicable_numbers[i] for i in range(len(amicable_numbers)) if amicable_numbers[i] <= n])

T = int(input().strip())
for _ in range(T):
    N = int(input())
    print(sum_amicable_numbers(N))
