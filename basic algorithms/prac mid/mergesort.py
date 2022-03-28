import math 

def merge(a, left, mid, right):
    n1 = mid - left + 1 
    n2 = right - mid
    a1 = [0] * (n1 + 1)
    a2 = [0] * (n2 + 1)
    for i in range(0, n1):
        a1[i] = a[left + i]
    for i in range(0, n2):
        a2[i] = a[mid + 1 + i]
    a1[n1] = math.inf 
    a2[n2] = math.inf 
    i1 = 0
    i2 = 0
    for i in range(left, right + 1):
        if a1[i1] <= a2[i2]:
            a[i] = a1[i1]
            i1 += 1
        else:
            a[i] = a2[i2]
            i2 += 1 

def mergesort(a, left, right):
    if left < right:
        mid = (left + right) // 2
        mergesort(a, left, mid)
        mergesort(a, mid + 1, right)
        merge(a, left, mid, right)

a = [-2, 10, 5, -8, -4, -10, 12, 1]
print(a)
mergesort(a, 0, len(a) - 1)
print(a)

    
    