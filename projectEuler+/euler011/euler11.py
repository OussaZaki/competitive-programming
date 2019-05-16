#!/bin/python3

def max_diagonal_product(g):
    max_product = 0
    rows, cols, path_size = len(g), len(g[0]), 4
    for i in range(rows):
        for j in range(cols - path_size + 1):
            phv = max(g[i][j] * g[i][j+1] * g[i][j+2] * g[i][j+3], g[j][i] * g[j+1][i] * g[j+2][i] * g[j+3][i])
            if i <= rows - path_size:
                pdd = max(g[i][j] * g[i+1][j+1] * g[i+2][j+2] * g[i+3][j+3], g[i][j+3] * g[i+1][j+2] * g[i+2][j+1] * g[i+3][j])
            max_product = max(max_product, phv, pdd)
    return max_product

grid = []
for grid_i in range(20):
	grid_t = [int(grid_temp) for grid_temp in input().strip().split(' ')]
	grid.append(grid_t)
print(max_diagonal_product(grid))