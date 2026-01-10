import math

n = int(input())
a = list(map(int,input().split()))
# 5
# 3 1 4 1 5
# i=1 としたとき、(3) と (1,4,1,5) のそれぞれに含まれる整数の種類数は 1,3 で、これらの和は 4 です。
# i=2 としたとき、(3,1) と (4,1,5) のそれぞれに含まれる整数の種類数は 2,3 で、これらの和は 5 です。
# i=3 としたとき、(3,1,4) と (1,5) のそれぞれに含まれる整数の種類数は 3,2 で、これらの和は 5 です。
# i=4 としたとき、(3,1,4,1) と (5) のそれぞれに含まれる整数の種類数は 3,1 で、これらの和は 4 です。
# よって、 i=2,3 のときに、最大値 5 を取ります。

lList = []
rList = a
sum = 0
b = math.ceil(n/2)

for i in range(len((a))):
    lList.append(rList[0])
    rList.pop(0)
    count = len(set(lList))+ len(set(rList))
    if sum < count:
        sum = count

print(sum)