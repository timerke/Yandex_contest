n = int(input()) # количество тестов
n_file = [] # количество файлов в тесте
n_delete = [] # количество файлов в тесте, которые можно удалить
rel = [] # релевантности файлов в тесте
for i in range(n):
    spam = input().split(' ')
    n_file.append(int(spam[0]))
    n_delete.append(int(spam[1]))
    rel.append([])
    spam = input().split(' ')
    for j in spam:
        rel[i].append(int(j))

for i in range(n):
    max_ = rel[i][0]
    for j in range(n_file[i]):
        for length in range(1, n_file[i] + 1):
            neg = []
            sum_ = 0
            for k in range(j, j + length):
                if k < n_file[i]:
                    sum_ += rel[i][k]
                    if rel[i][k] < 0:
                        neg.append(rel[i][k])
                else:
                    sum_ += rel[i][k - n_file[i]]
                    if rel[i][k - n_file[i]] < 0:
                        neg.append(rel[i][k - n_file[i]])
            if n_delete[i] and len(neg):
                neg.sort()
                for k in range(min(n_delete[i], len(neg))):
                    if k < length - 1:
                        sum_ -= neg[k]
                    else:
                        break
            if sum_ > max_:
                max_ = sum_
    print(max_)
                
