from typing import List

# ALG0601 验证某数组是否是顺序数组的栈序列
def judgeOrder(t: List[int]) -> bool:
    n = len(t)
    st = []
    i, j = 1, 0
    while j < n:
        if i == t[j]:
            i += 1
            j += 1
        elif len(st) > 0 and st[-1] == t[j]:
            st.pop()
            j += 1
        elif i <= n:
            st.append(i)
            i += 1
        else:
            return False
            break
    return True

t = [5, 4, 3, 2, 1]
res = judgeOrder(t)
print("res: ", res)
