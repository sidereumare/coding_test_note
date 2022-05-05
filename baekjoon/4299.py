a, s = map(int, input().split())
if (a-s)%2==0 and a>=s:
    print((a-s)//2+s, (a-s)//2)
else:
    print(-1)