T = int(input())
for test in range(T):
    n = bin(int(input()))
    n = n[::-1]
    rst = []
    for i, e in enumerate(n):
        if e=='1':
            rst.append(i)
    print(*rst, sep=' ')
