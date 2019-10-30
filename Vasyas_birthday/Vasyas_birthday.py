from math import ceil

# Класс, отвечающий за ингредиенты в одной порции блюда
class Portion():
    def __init__(self, recipe):
        spam = recipe.split(' ')
        self.name = spam[0] # название ингредиента
        self.num = float(spam[1]) # количество ингредиента для одной порции
        self.unit = spam[2] # единица измерения
        
# Класс, отвечающий за блюда
class Dish():
    def __init__(self, order):
        spam = order.split(' ')
        self.name = spam[0] # название блюда
        self.num = int(spam[1]) # количество порций
        self.num_ingr = int(spam[2]) # количество ингредиентов в блюде
        self.ingr = [] # список для ингредиентов в блюде
        self.quantity = {} # словарь из полного количества требуемых ингредиентов
        self.cost = 0 # полная стоимость всего количества блюда
        self.energy = {'pr': 0.0, 'f': 0.0, 'ch': 0.0, 'fv': 0.0} # список из количества белков, жиров, углеродов и калорий в одном блюде
        
    def ingredient(self, recipe):
        # Определяем ингредиенты для блюда
        self.ingr.append(Portion(recipe))
        
    def calculate(self, shop, ingr_char):
        for ingr in self.ingr:
            # Определяем сколько и за сколько нужно купить ингредиентов для всех порций блюда
            quantity = ceil(self.num * ingr.num / shop[ingr.name][1]) # количество ингредиентов нужно для всех порций
            self.cost += shop[ingr.name][0] * quantity
            self.quantity[ingr.name] = quantity
            # Определяем сколько белков, жиров, углеродов и калорий в одном блюде
            self.energy['pr'] += ingr_char[ingr.name][2] * ingr.num * units[ingr.unit] / (ingr_char[ingr.name][0] * units[ingr_char[ingr.name][1]])
            self.energy['f'] += ingr_char[ingr.name][3] * ingr.num * units[ingr.unit] / (ingr_char[ingr.name][0] * units[ingr_char[ingr.name][1]])
            self.energy['ch'] += ingr_char[ingr.name][4] * ingr.num * units[ingr.unit] / (ingr_char[ingr.name][0] * units[ingr_char[ingr.name][1]])
            self.energy['fv'] += ingr_char[ingr.name][5] * ingr.num * units[ingr.unit] / (ingr_char[ingr.name][0] * units[ingr_char[ingr.name][1]])
    
# Словарь перевода из одних единиц в другие
units = {'cnt': 1, 'tens': 10, 'g': 1, 'kg': 1000, 'l': 1000, 'ml': 1}

num_dishes = int(input()) # количество блюд для приготовления
dishes = [] # список из блюд
for i in range(num_dishes):
    dishes.append(Dish(input())) # добавляем новое блюдо
    for j in range(dishes[i].num_ingr):
        dishes[i].ingredient(input()) # добавляем ингредиенты для блюда

num_ingr_in_shop = int(input()) # количество товаров-ингредиентов в магазине
shop = {} # словарь для товаров в магазине
for i in range(num_ingr_in_shop):
    spam = input().split(' ')
    shop[spam[0]] = (int(spam[1]), int(spam[2]), spam[3])
    for dish in dishes:
        for ingr in dish.ingr:
            if spam[0] == ingr.name:
                if spam[3] != ingr.unit:
                    ingr.num *= units[ingr.unit]/units[spam[3]]
                    ingr.unit = spam[3]

num_ingr = int(input()) # количество ингредиентов в словаре с характеристиками
ingr = {} # словарь для характеристик ингредиентов по белкам, жирам, углерода и калориям
for i in range(num_ingr):
    spam = input().split(' ')
    ingr[spam[0]] = (int(spam[1]), spam[2], float(spam[3]), float(spam[4]), float(spam[5]), float(spam[6]))

# Вычисляем полную стоимость требуемых ингредиентов, их количество и содержание белков, жиров и углеродов в одной порции
total_cost = 0 # полная стоимость
ingr_total = {} #
for i in shop:
    ingr_total[i] = 0

for i in dishes:
    i.calculate(shop, ingr)
    total_cost += i.cost
    for j in i.quantity:
        ingr_total[j] += i.quantity[j]
        
# Полная стоимость
print(total_cost)
for i in ingr_total:
    print(f'{i} {ingr_total[i]}')
    
for i in dishes:
    print(f'{i.name} {round(i.energy["pr"], 4)} {round(i.energy["f"], 4)} {round(i.energy["ch"], 4)} {round(i.energy["fv"], 4)}')
