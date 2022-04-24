t = []
for i in range(9):
    t.append(list(map(int, input().split())))
r = [-1, -1]
m = -1
for i, l in enumerate(t):
    for j, e in enumerate(l):
        if e > m:
            m = e
            r = [i, j]
print('{}\n{} {}'.format(m, r[0]+1, r[1]+1))