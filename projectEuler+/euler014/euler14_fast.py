limit = 5000001
collatz = [0] * limit
max_length = [0] * limit

def precalculate_collatz (n):
    for i in range(1, limit):
        num = i
		counter = 1
		while num != 1:
			if num < MAXN and collatz[num] != 0:
				counter += collatz[num] - 1
				break
			if num & 1:
                num = 3 * num + 1
			else:
                num >>= 1
			counter += 1

		collatz[i] = counter
        if (collatz[max_length[i - 1]] > counter) :
            max_length[i] = max_length[i-1]
        else:
            max_length[i] = i


T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    print(max_length[N])