#include <iostream>
#include <vector>

//
int find(std::vector<int>* table, int symbol)
{
    for (int i = 0; i < table->size(); i++)
    {
        if (table->at(i) == symbol)
        {
            return i;
        }
    }
}

//
void shift(std::vector<int>* table, int pos)
{
    int temp = table->at(pos);
    table->erase(table->begin() + pos);
    table->insert(table->begin(), temp);
}

// Функция реализует кодировку текста
void coding(int n, int* text, int m)
{
    // Создаем таблицу для кодирования
    std::vector<int> coding_table(m); // таблица для кодировки
    for (int i = 0; i < m; i++)
    {
        coding_table[i] = i + 1;
    }
    //
    for (int i = 0; i < n; i++)
    {
        int pos = find(&coding_table, text[i]);
        std::cout << pos + 1;
        if (i < n - 1)
        {
            std::cout << " ";
        }
        shift(&coding_table, pos);
    }
}

// Функция реализует расшифровку текста
void encoding(int n, int* text, int m)
{
    // Создаем таблицу для декодирования
    std::vector<int> coding_table(m); // таблица для декодировки
    for (int i = 0; i < m; i++)
    {
        coding_table[i] = i + 1;
    }
    //
    for (int i = 0; i < n; i++)
    {
        int pos = text[i] - 1;
        std::cout << coding_table[pos];
        if (i < n - 1)
        {
            std::cout << " ";
        }
        shift(&coding_table, pos);
    }
}

int main()
{
    // Получаем исходные данные
    int n; // количество символов в тексте
    int m; // количество символов в кодировке
    int type; // режим работы программы
    std::cin >> n >> m >> type;
    int* text = new int[n]; // текст для кодировки или раскодировки
    for (int i = 0; i < n; i++)
    {
        std::cin >> text[i];
    }
    //
    if (type == 1)
    {
        // Требуется зашифровать заданный текст
        coding(n, text, m);
    }
    else
    {
        // Требуется расшифровать заданный текст
        encoding(n, text, m);
    }
    //
    delete[] text;
}