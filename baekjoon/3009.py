a = input().split()
b = input().split()
c = input().split()
mx = {a[0]:0, b[0]:0, c[0]:0}
my = {a[1]:0, b[1]:0, c[1]:0}
mx[a[0]]+=1
mx[b[0]]+=1
mx[c[0]]+=1
my[a[1]]+=1
my[b[1]]+=1
my[c[1]]+=1
for k, v in mx.items():
    if v==1:
        print(k, end=' ')
for k, v in my.items():
    if v==1:
        print(k)
