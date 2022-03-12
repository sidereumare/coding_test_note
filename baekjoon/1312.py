a, b, c = map(int, input().split())
a = a%b
answer = 0
for i in range(c):
    a *= 10
    answer = a//b
    a %= b
print(answer)