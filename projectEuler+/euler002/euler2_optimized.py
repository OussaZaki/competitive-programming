def even_fibonacci_sum(n):
    fn_2 = 2 #Fn-2
    fn_1 = 8 #Fn-1
    sum = 10 #first even number Fn-2 + Fn-1
    while True :
        fn = 4 * fn_1 + fn_2
        if fn >= n: return sum
        sum += fn
        fn_2, fn_1 = fn_1, fn

t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    print(even_fibonacci_sum(n))