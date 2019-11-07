from time import sleep
from sys import argv
if argv and len(argv) >= 2:
    # Если при запуске в консоли передается имя файла со стартовым состоянием доски
    cells = []
    with open(argv[1], 'r') as file:
        for i, line in enumerate(file):
            if i == 0:
                # На первой строке через пробел должны быть записаны размеры доски
                M, N = line.split(' ')
                M = int(M) # количество строк
                N = int(N) # количество столбцов
            else:
                cells.append([])
                spam = line.split(' ')
                for j in spam:
                    cells[i - 1].append(int(j))            
else:
    # Если при запуске не передается файл со стартовым состоянием,
    # определяем случайным образом начальное состояние доски
    from random import getrandbits, randint
    MAX_MN = 10 # максимальный возможный размер доски
    M = randint(1, MAX_MN) # количество строк
    N = randint(1, MAX_MN) # количество столбцов
    cells = [[randint(0, 1) for _ in range(N)] for _ in range(M)]

# Этапы жизни доски будут записываться поочередно на две доски
# Одна доска с клетками cells уже есть. Создадим еще одну доску размера MxN
cells_copy = [[0 for _ in range(N)] for _ in range(M)]
# Определяем количество живых клеток-соседей клетки i, j
def number_of_living(c, i, j):
    n = 0
    for i_ in (i - 1, i, i + 1):
        if -1 < i_ < M:
            for j_ in (j - 1, j, j + 1):
                if -1 < j_ < N and (i != i_ or j != j_) and c[i_][j_]:
                    n += 1
    return n

# Определяем жизненный цикл клеток
def life_activity(c, c_n):
    for i in range(M):
        for j in range(N):
            nl = number_of_living(c, i, j) # количество живых соседей у клетки i, j
            if c[i][j] and (nl < 2 or nl > 3):
                # Клетка умирает
                c_n[i][j] = 0
            elif c[i][j] == 0 and nl == 3:
                # Клетка рождается
                c_n[i][j] = 1
            else:
                # С клеткой ничего не происходит
                c_n[i][j] = c[i][j]
            print(f'\t{c[i][j]}', end = '')
        print()

t = 0 # время с момента запуска моделирования жизненного цикла доски
# Жизнь доски с клетками
while True:
    print(f'{t} сек')
    if t % 2 == 0:
        life_activity(cells, cells_copy)
    else:
        life_activity(cells_copy, cells)
    t += 1
    sleep(1)
                
