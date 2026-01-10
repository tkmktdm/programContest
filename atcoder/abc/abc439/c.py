
# 問題文
# 正整数 n が次の条件を満たす時、n を 良い整数 と呼びます。
# 0<x<y かつ x**2 +y**2 =n を満たす整数の組 (x,y) がただ 1 つ存在する。
# 例えば n=2026 とすると、0<x<y かつ x 2 +y 2 =n を満たす整数の組は (x,y)=(1,45) しか存在しないことが確認できます。よって 2026 は良い整数です。
# 正整数 N が与えられます。N 以下の良い整数を全て列挙してください。


# def goodInt(n):
#     ans = 0
#     existInt = set()
#     while n != 1:
#         n = sum([int(i) ** 2 for i in str(n)])
#         if n in existInt:
#             return False
#         else: existInt.add(n)
#     else:
#         return True

# 条件
# (0 < x < y) && (x**2 + y**2 <= n)
n = int(input())  # nはint型
# result = goodInt(n)

for i in range(1, n):
    print(i , i+1)
    # for k in range()
    # print(i)
    # print(n-i)10

    temp = (i**2 + (n-i)**2)
    # if ():
        
    # print()

# if result == 1:
#     print("Yes")
# else:
#     print("No")
