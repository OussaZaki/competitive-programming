def even_fibonacci_sum(n):
    fn_2 = 1 #Fn-2
    fn_1 = 1 #Fn-1
    sum = 0
    while True :
        fn = fn_2 + fn_1 #Fn
        if fn >= n: return sum
        if fn % 2 == 0: sum += fn
        fn_2, fn_1 = fn_1, fn

t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    print(even_fibonacci_sum(n))