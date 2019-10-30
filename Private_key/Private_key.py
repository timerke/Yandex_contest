# Функция, реализующая алгоритм Евклида для поиска наибольшего общего делителя
def euclid(a, b):
    c = a if a < b else b
    d = b if a < b else a
    while True:
        while d > c:
            d -= c
        d, c = c, d
        if c == d:
            break
    return c

from math import ceil

gcd, lcm = input().split(' ')
gcd = int(gcd) # наибольший общий делитель
lcm = int(lcm) # наименьшее общее кратное
n = 0 # количество вариантов закрытого кода
for i in range(1, lcm + 1):
    for j in range(min(ceil(gcd * lcm / i), lcm + 1), i, -1):
        if i * j < gcd * lcm:
            break
        if lcm % i == 0 and lcm % j == 0 and i * j == gcd * lcm and euclid(i, j) == gcd:
            n += 1
            print(f'{i} {j}')
print(2 * n)
