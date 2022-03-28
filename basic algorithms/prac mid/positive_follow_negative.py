def merge(a, temp, left, mid, right):
    t_i = left
    for i in range(left, mid + 1):
        # negative from left 
        if a[i] < 0:
            temp[t_i] = a[i]
            t_i += 1
    
    for i in range(mid + 1, right + 1):
        # negative from right 
        if a[i] < 0:
            temp[t_i] = a[i]
            t_i += 1
    
    for i in range(left, mid + 1):
        # positive from left 
        if a[i] >= 0:
            temp[t_i] = a[i]
            t_i += 1
    
    for i in range(mid + 1, right + 1):
        # positive from right
        if a[i] >= 0:
            temp[t_i] = a[i]
            t_i += 1
    
    for i in range(left, right + 1):
        a[i] = temp[i]

def solve(a, temp, left, right):
    if left < right:
        mid = (left + right) // 2
        solve(a, temp, left, mid)
        solve(a, temp, mid + 1, right)
        merge(a, temp, left, mid, right)

a = [-2, 10, 5, -8, -4, -10, 12, 1]
print(a)
solve(a, a.copy(), 0, len(a) - 1)
print(a)