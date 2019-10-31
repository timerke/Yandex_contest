n = int(input())
min_value = []
for i in range(n):
    m = int(input())
    a = input().split()
    min_ = [0, 1]
    for j in range(m):
        a[j] = int(a[j])
        for k in range(j + 1, m):
            a[k] = int(a[k])
            if a[j] ^ a[k] < a[min_[0]] ^ a[min_[1]]:
                min_ = [j, k]
    min_value.append(a[min_[0]] ^ a[min_[1]])
for i in min_value:
    print(i)
