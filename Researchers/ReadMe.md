# Исследователи
Дан список, в которой хранятся исследователи и топонимы (имена мест) где они бывали. Список имеет следующий формат:
  [  
  [<explorer1>, <toponym1>, <toponym2>, ...],  
  [<explorer2>, <toponym2>, <toponym3>, ...],  
  [<explorer3>, <toponym4>, <toponym1>, ...],  
  ...  
  ]
Надо развернуть этот список, таким образом, чтобы на первом месте оказался топоним, а на остальных исследователи.

## Формат ввода
  [  
  ["Mallory", "Everest", "Mont Blanc", "Pillar Rock"],  
  ["Mawson", "South Pole", "New Hebrides"],  
  ["Hillary", "Everest", "South Pole"]  
  ]
## Формат вывода
  [  
  ["Everest", "Hillary", "Mallory"],  
  ["South Pole", "Hillary", "Mawson"],  
  ["Mont Blanc", "Mallory"],  
  ["Pillar Rock", "Mallory"],  
  ["New Hebrides", "Mawson"]  
  ]
## Примечания
Решение необходимо предоставить в виде CommonJS-модуль:
  module.exports = function (explorers) {  
    // Your code here.  
  };
