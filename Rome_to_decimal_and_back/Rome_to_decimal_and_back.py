# Словарь, хранящий значения римских цифр
rome_base = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
# Словарь, хранящий значения десятичных чисел
decimal_base = {1: {1: 'I', 5: 'V'}, 10: {1: 'X', 5: 'L'}, 100: {1: 'C', 5: 'D'}, 1000: {1: 'M'}}

# Функция переводит число из римской системы счисления в десятичную
def rome_to_decimal(rome):
    n = len(rome)
    decimal = 0
    for i in range(n):
        for j in range(i + 1, n):
            if (rome_base[rome[i]] > rome_base[rome[j]]) or (rome_base[rome[i]] == rome_base[rome[j]] and j == n - 1):
                decimal += rome_base[rome[i]]
                break
            elif rome_base[rome[i]] < rome_base[rome[j]]:
                decimal -= rome_base[rome[i]]
                break
    else:
        decimal += rome_base[rome[n - 1]]
    return decimal

# Функция переводит число из десятичной системы счисления в римскую
def decimal_to_rome(decimal):
    # Для правильной записи больших чисел римскими цифрами необходимо
    # сначала записать число тысяч, затем сотен, затем десятков и единиц
    base = (1000, 100, 10, 1)
    rome = ''
    for i, n in enumerate(base):
        nums = decimal // n # число тысяч, сотен, десятков или единиц
        decimal %= n
        if n == 1000:
            while nums:
                nums -= 1
                rome += decimal_base[n][1]
        else:
            while nums:
                if nums == 9:
                    rome += decimal_base[n][1] + decimal_base[base[i - 1]][1]
                    nums = 0
                elif nums == 4:
                    rome += decimal_base[n][1] + decimal_base[n][5]
                    nums = 0
                elif nums >= 5:
                    rome += decimal_base[n][5]
                    nums -= 5
                elif nums >= 1:
                    rome += decimal_base[n][1]
                    nums -= 1
    return rome

# Перевод числа из римской системы счисления в десятичную систему
rome = input('Введите число в римской системе счисления: ').upper()
decimal = rome_to_decimal(rome)
print(f'Число в десятичной системе счисления: {decimal}.')
print(f'Число обратно в римской системе счисления: {decimal_to_rome(decimal)}.')
