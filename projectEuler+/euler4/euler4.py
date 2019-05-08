def generate_palindrome_list(): 
    palindromes = set()
    for i in range(100, 1000):
        for j in range(100000//i + 1, 1000):
            a = i * j
            if str(a) == str(a)[::-1] and a not in palindromes:
                palindromes.add(a)

    return sorted(palindromes)

T = int(input().strip())
palindrome_list = generate_palindrome_list()
for i in range(T):
    N = int(input().strip())
    l = len(palindrome_list)
    for i in range(l - 1, -1, -1):
        if palindrome_list[i] < N:
            print(palindrome_list[i])
            break
