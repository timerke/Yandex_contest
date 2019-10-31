spam = input().split(' ')
n = int(spam[0]) # количество чанков на кластере
m = int(spam[1]) # количество серверов
q = int(spam[2]) # количество запросов

spam = input().split(' ')
chank = []
for i in spam:
    chank.append(int(i))

inquiries = [] # запросы
for i in range(q):
    inquiries.append(input())

execution = []
for inquiry in inquiries:
    spam = inquiry.split(' ')
    server_from = int(spam[0])
    server_to = int(spam[1])
    chank_b = int(spam[2])
    chank_e = int(spam[3])
    flag = True
    for i in range(chank_b, chank_e + 1):
        if chank[i - 1] != server_from:
            flag = False
            break
    if not flag:
        execution.append(0)
        continue
    else:
        for i in range(chank_b, chank_e + 1):
            chank[i - 1] = server_to
        execution.append(1)
for i in execution:
    print(i)
