#include <iostream>
#include <math.h>

// Функция получает из стандартного ввода данные
void input(int n, int l[], int a[], int b[], int c[])
{
    for (int i = 0; i < n + 1; i++)
    {
        std::cin >> l[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i] >> b[i] >> c[i];
    }
}

//
double fg(double x, int& f_a, int& f_b, int& f_c, int& g_a, int& g_b, int& g_c)
{
    return abs((f_a - g_a) * x * x + (f_b - g_b) * x + f_c - g_c);
}

double step_square(int left, int right, int& f_a, int& f_b, int& f_c, int& g_a, int& g_b, int& g_c)
{
    double dx = 0.000001;
    double x = left;
    double square = 0.0;
    while (x < right)
    {
        square += dx * (fg(x, f_a, f_b, f_c, g_a, g_b, g_c) + fg(x + dx, f_a, f_b, f_c, g_a, g_b, g_c)) / 2;
        x += dx;
    }
    return square;
}

// Функция вычисляет площадь
double square_calculation(int n, int* f_l, int* f_a, int* f_b, int* f_c, int m, int* g_l, int* g_a, int* g_b, int* g_c)
{
    int f_i = 1, g_i = 1;
    double square = 0.0; // площадь между функциями f и g
    int left = f_l[0], right;
    while (left < f_l[n])
    {
        if (f_l[f_i] == g_l[g_i])
        {
            right = f_l[f_i];
            square += step_square(left, right, f_a[f_i - 1], f_b[f_i - 1], f_c[f_i - 1], g_a[g_i - 1], g_b[g_i - 1], g_c[g_i - 1]);
            f_i++;
            g_i++;
        }
        else if (f_l[f_i] < g_l[g_i])
        {
            right = f_l[f_i];
            square += step_square(left, right, f_a[f_i - 1], f_b[f_i - 1], f_c[f_i - 1], g_a[g_i - 1], g_b[g_i - 1], g_c[g_i - 1]);
            f_i++;
        }
        else
        {
            right = g_l[g_i];
            square += step_square(left, right, f_a[f_i - 1], f_b[f_i - 1], f_c[f_i - 1], g_a[g_i - 1], g_b[g_i - 1], g_c[g_i - 1]);
            g_i++;
        }
        left = right;
    }
    return square;
}

int main()
{
    // Получаем исходные данные
    int n, m; // из скольки частей состоят функции f и g соответственно
    std::cin >> n >> m;
    int* l = new int[n + 1]; // границы участков для функции f
    int* f_a = new int[n]; // значения коэффициентов a функции f = a * x^2 + b * x + c на разных участках
    int* f_b = new int[n]; // значения коэффициентов b функции f = a * x^2 + b * x + c на разных участках
    int* f_c = new int[n]; // значения коэффициентов c функции f = a * x^2 + b * x + c на разных участках
    input(n, l, f_a, f_b, f_c); // получаем данные для функции f
    int* r = new int[m + 1]; // границы участков для функции g
    int* g_a = new int[m]; // значения коэффициентов a функции g = a * x^2 + b * x + c на разных участках
    int* g_b = new int[m]; // значения коэффициентов b функции g = a * x^2 + b * x + c на разных участках
    int* g_c = new int[m]; // значения коэффициентов c функции g = a * x^2 + b * x + c на разных участках
    input(m, r, g_a, g_b, g_c); // получаем данные для функции g
    //
    printf("%.10f", square_calculation(n, l, f_a, f_b, f_c, m, r, g_a, g_b, g_c));
}