n = int(input())
for i in range(n):
    print('{0}{1}'.format(' '*i,'*'*(2*n-(i*2+1))))