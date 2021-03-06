Алиса, Боб и шифрование

Алиса и Боб все еще работают в отделе безопасности передачи данных и занимаются любимым делом — исследуют
только что придуманный алгоритм шифрования на криптостойкость.
Алгоритм, придуманный Алисой и Бобом, весьма прост. Во время шифрования алгоритм принимает символы шифруемого
текста по одному и заменяет этот символ на ровно один другой символ. Кодировка, которой пользуются Алиса и Боб,
состоит из m символов, поэтому можно считать, что текст преставляет собой последовательность натуральных чисел,
не превосходящих m. Во время работы алгоритм шифрования поддерживает перестановку натуральных чисел от 1 до m.
В начале работы перестановка тождественна, то есть pi=iдля всех i. Когда алгоритму на вход поступает символ x,
алгоритм заменяет его на номер позиции в перестановке (в 1-индексации), на которой находится символ x, а также
переносит x в начало перестановки. Например, если в некоторый момент работы алгоритма перестановка символов в
нем равна [4,2,1,3], а на вход подается символ 1, то символ 1 будет заменен на символ 3, поскольку 1 стоит в
перестановке на третьей позиции, а перестановка примет вид [1,4,2,3]. Несложно заметить, что результатом
шифрования текста, состоящего из n натуральных чисел, не превосходящих m, также является текст, состоящий из
n натуральных чисел, не превосходящих m.
Для упрощения исследования Алиса и Боб решили реализовать эффективное кодирование и декодирование текстов при
помощи своего алгоритма, однако Чак, Крейг и Ева нарушили их планы, поэтому Алиса и Боб просят вас реализовать
их алгоритм кодирования.

Формат ввода
В первой строке заданы три целых числа n, m и type (1≤n,m≤300000, type∈{1,2}) — длина текста, количество символов
в кодировке и режим работы программы соответственно. Если type=1, то требуется зашировавть заданный текст.
Если type=2, то требуется расшировать заданный зашифрованный текст. В следующей строке задано n целых чисел
(1≤ai≤m) — текст для обработки.

Формат вывода
Выведите 
n целых чисел — результат обработки текста. Можно показать, что результат расшифровки текста всегда существует
и единственен.

Пример 1
Ввод
7 3 1
2 3 1 2 1 1 1

Вывод
2 3 3 3 2 1 1

Пример 2
Ввод
7 3 2
2 3 3 3 2 1 1

Вывод
2 3 1 2 1 1 1