n = int(input())
l = [int(input()) for _ in range(n)]

maxv = -2 * 10 ** 9
minv = l[0]
for num in l[1:]:
    maxv = max(maxv, num - minv)
    minv = min(minv, num)

print(maxv)
