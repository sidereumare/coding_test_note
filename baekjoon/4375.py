
while True:
    try:
        n = int(input())
        if n==1:
            print(1)
            continue
        t, cnt = 11, 2
        while t%n!=0:
            t = t*10+1
            cnt+=1
        print(cnt)
    except:
        break
