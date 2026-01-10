b = str(input())
wc = 0
c = 0
for w in b:
     if (w != "i" and c%2==0 or w !="o" and c%2==1):
          wc+=1
          c+=1
     c+=1
if (b[-1] == 'i'):
     wc+=1
print(wc)

# iは奇数
# oは偶数