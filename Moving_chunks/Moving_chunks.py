spam = input().split(' ')
n = int(spam[0]) # количество чанков на кластере
m = int(spam[1]) # количество серверов
q = int(spam[2]) # количество запросов

spam = input().split(' ')
chank = [] # список с серверами, на которых расположены чанки
for i in spam:
    chank.append(int(i))

inquiries = [] # список для запросов
for i in range(q):
    inquiries.append(input())

for inquiry in inquiries:
    spam = inquiry.split(' ')
    server_from = int(spam[0])
    server_to = int(spam[1])
    chank_b = int(spam[2]) - 1
    chank_e = int(spam[3])
    s = set(chank[chank_b : chank_e]) # множество из серверов, на которых расположены чанки, которые нужно переместить в запросе
    if len(s) == 1 and server_from in s:
        # Если перемещаемые в запросе чанки находятся на нужном сервере,
        # чанки перемещаются
        for i in range(chank_b, chank_e):
            chank[i] = server_to
        print(1)
    else:
        # Если не все перемещаемые чанки находятся на нужном сервере,
        # чанки не перемещаются
        print(0)
