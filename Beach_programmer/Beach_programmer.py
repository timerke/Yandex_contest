from collections import deque

# Читаем входные данные
n = int(input()) # количество тестов
m = deque() # очередь из количества лежаков в каждом тесте
a = deque() # очередь из списков чисел, характеризующих лежаки в каждом тесте
for i in range(n):
    m_ = int(input()) # количество лежаков в тесте
    m.append(m_)
    spam = input().split() # массив из чисел, характеризующих лежаки
    for j in range(m_):
        spam[j] = int(spam[j])
    a.append(spam)

# Выполняем сравнения в тестах
for i in range(n):
    m_ = m.popleft() # количество лежаков в тесте
    a_ = a.popleft() # список из чисел, характеризующих лежаки в тесте
    min_ = a_[0] ^ a_[1] # минимальное значение непохожести двух лежаков в тесте
    for j in range(m_):
        for k in range(j + 1, m_):
            if a_[j] ^ a_[k] < min_:
                min_ = a_[j] ^ a_[k]
    print(min_)
