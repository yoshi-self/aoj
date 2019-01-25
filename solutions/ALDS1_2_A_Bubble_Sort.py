def bubble_sort(l):
    swap_num = 0
    flag = True
    i = 0
    while flag:
        flag = False
        j = len(l) - 1
        while j > i:
            if l[j] < l[j - 1]:
                l[j], l[j - 1] = l[j - 1], l[j]
                swap_num += 1
                flag = True
            j -= 1
        i += 1
    return swap_num

n = int(input())
l = list(map(int, input().split()))
num = bubble_sort(l)
print(' '.join(map(str, l)))
print(num)
