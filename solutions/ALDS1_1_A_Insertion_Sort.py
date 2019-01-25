def insertion_sort(l):
    i = 1
    while i < len(l):
        print(' '.join(map(str, l)))

        v = l[i]
        j = i - 1
        while j >= 0 and l[j] > v:
            l[j + 1] = l[j]
            j -= 1
        l[j + 1] = v
        i += 1


n = int(input())
l = list(map(int, input().split()))
insertion_sort(l)
print(' '.join(map(str, l)))
