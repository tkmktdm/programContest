'''
abc.abc440.b の Docstring

- 入出力系
https://qiita.com/_-_-_-_-_/items/34f933adc7be875e61d0#%E5%87%BA%E5%8A%9B
https://zenn.dev/rabbit_penguin0/articles/bcc95f7703124a#%E5%87%BA%E5%8A%9B_print%E6%96%87

- for
https://ai-inter1.com/python-for-range/

- 並べ替え・ソート系
https://docs.python.org/ja/3.13/howto/sorting.html

- Python, enumerateの使い方: リストの要素とインデックスを取得
https://note.nkmk.me/python-enumerate-start/


- 辞書型（連想配列）
https://python.joho.info/dict-tutorial/#toc5

- 辞書型の並び替え
https://qiita.com/yousuke_yamaguchi/items/23014a3c8d8beb8ba073

'''
# 4
# 100 110 105 95


n = int(input())
t = list(map(int,input().split()))
ans = {}
text = ""
for i, time in enumerate(t):
    ans[time] = i+1

a = sorted(ans.items(), key=lambda x:x[0])
# score = {'kokugo': 33, 'sansuu': 85, 'eigo': 60}
# score_sorted = sorted(score.items(), key=lambda x:x[0])

for i in range(3):
    if i ==3:
        text += str(a[i][1])
    else:
        text += str(a[i][1])+" "
print(text)




