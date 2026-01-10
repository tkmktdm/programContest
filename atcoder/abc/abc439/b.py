# 正整数 
# N が与えられるので、 N がハッピー数であるかを判定してください。
# ハッピー数とは、以下の操作を有限回繰り返すことで 1 になる非負整数を指します。
# 自身を、十進法表記の各桁の数字の二乗和を取った整数に置き換える。
# 例えば、操作前に 2026 であれば、この操作を 1 度行うと自身が 2 2+0 2+2 2+6 2 =4+0+4+36=44 に置き換えられます。
# 具体的なハッピー数の例は入出力例の説明を参照してください。

# set()関数について
# https://popinsight.jp/blog/?p=14834
# 正解のコード
# https://yuni-wiki.com/python/leetcode_happy_number/

def happy(n):
    ans = 0
    existInt = set()
    while n != 1:
        n = sum([int(i) ** 2 for i in str(n)])
        if n in existInt:
            return False
        else: existInt.add(n)
    else:
        return True
# この書き方だとansがnより大きくなった後にハッピー数になるパターンが対応しきれないのでダメだった
# def happy(n):
#     ans = 0
#     for i in str(n):
#         ans += int(i)**2
#     if (n > ans):
#         ans = happy(ans)
#     return ans

n = int(input())  # nはint型
# ans = n
result = happy(n)
if result == 1:
    print("Yes")
else:
    print("No")
