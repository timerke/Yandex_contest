#include <iostream>

// Функция выбирает наибольшее из двух чисел
int max(int& a, int& b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

// Функция переставляет элементы в массиве
void swap(int* a, int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Функция реализует сортировку выбором в порядке убывания
void selection_sort(int a[], int b[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int max_i = i;
        int ab_max = max(a[max_i], b[max_i]);
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] > ab_max || b[j] > ab_max)
            {
                max_i = j;
                ab_max = max(a[max_i], b[max_i]);
            }
        }
        if (max_i != i)
        {
            swap(a, i, max_i);
            swap(b, i, max_i);
            max_i = i;
        }
    }
}

bool is_fit(int* a, int* b, int i, int j)
{
    if (a[i] < a[j] && b[i] < b[j])
    {
        return true;
    }
    else if (a[i] < b[j] && b[i] < a[j])
    {
        return true;
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    // Получаем полную информацию об условиях задачи
    int n; // количество поддонов
    std::cin >> n;
    int* h = new int[n]; // массив с высотами поддонов
    int* w = new int[n]; // массив с ширинами поддонов
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i] >> h[i];
    }
    // Сортируем массивы в порядке убывания размеров поддонов
    selection_sort(h, w, n);
    // 
    bool fitted = false;
    int amount = 1;
    for (int i = 1; i < n; i++)
    {
        fitted = false;
        for (int j = 0; j < i; j++)
        {
            if (is_fit(h, w, i, j))
            {
                fitted = true;
                break;
            }
        }
        if (!fitted)
        {
            amount++;
        }
    }
    std::cout << amount;
    // Удаляем динамическую память
    delete[] h;
    delete[] w;
}