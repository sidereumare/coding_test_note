import re
n = int(input())
p = re.compile('^'+input().replace('*', '[a-z]*')+'$')
for i in range(n):
    if p.match(input()) != None:
        print('DA')
    else:
        print('NE')
