def selection_sort(l):
    swap_num = 0
    n = len(l)
    for i in range(n):
        minj = i
        for j in range(i, n):
            if l[j] < l[minj]:
                minj = j
        if minj != i:
            l[minj], l[i] = l[i], l[minj]
            swap_num += 1

    return swap_num

n = int(input())
l = list(map(int, input().split()))
num = selection_sort(l)
print(' '.join(map(str, l)))
print(num)
