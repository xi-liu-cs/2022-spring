def alleq(a, left, right):
    if left == right:
        return True
    if a[left] != a[right]:
        return False
    mid = (left + right) // 2
    return alleq(a, left, mid) and alleq(a, mid + 1, right)

a = [0, 1, 1]
print(alleq(a, 0, len(a) - 1))