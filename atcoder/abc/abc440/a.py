x,y = map(int,input().split())
ans = 0
for i in range(1, y+1):
    if i == 1:
        ans = x*2
    else:
        ans = ans*2
print(ans)
