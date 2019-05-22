#!/bin/python3


def max_path_sum(n, numbers):
    row = n - 2
    while row >= 0:
        for i in range(len(numbers[row])):
            numbers[row][i] += max(numbers[row+1][i], numbers[row+1][i+1])
        row -= 1
    return numbers[0][0]


T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    numbers = []
    for _ in range(N):
        numbers.append(list(map(int, input().split())))
    print(max_path_sum(N, numbers))
