import sys, math

def area(x1, y1, x2, y2, x3, y3):
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)

def pointInTriangle(x1, y1, x2, y2, x3, y3, x, y):
    condition_1 = sign(x, y, x1, y1, x2, y2) < 0.0
    condition_2 = sign(x, y, x2, y2, x3, y3) < 0.0
    condition_3 = sign(x, y, x3, y3, x1, y1) < 0.0

    return (condition_1 == condition_2) and (condition_2 == condition_3)

def isNotTriangle(x1, y1, x2, y2, x3, y3):

    
n = int(input())
for i in range(n):
    x1, y1, x2, y2, x3, y3, x, y = map(int, input().strip().split(' '))
    if isNotTriangle(x1, y1, x2, y2, x3, y3):
        print(x1, y1, x2, y2, x3, y3)
        print("INSIDE")
    else:   
        a = pointInTriangle(x1, y1, x2, y2, x3, y3, x, y)
        print("INSIDE") if a else print("OUTSIDE")
    
  