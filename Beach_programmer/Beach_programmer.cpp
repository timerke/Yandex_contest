#include <iostream>
#include <deque>
#include <vector>

int main()
{
	// Читаем входные данные
	int n; // количество тестов
	std::cin >> n;
	std::deque<int>	m; // очередь из количества лежаков в каждом тесте
	std::deque<std::vector<int>> a; // очередь из списков чисел, характеризующих лежаки в каждом тесте
	int m_; // количество лежаков в тесте
	int i, j, k, min_, temp; // полезные переменные, которыми будем пользоваться в дальнейшем
	for (i = 0; i < n; i++)
	{
		std::cin >> m_;
		m.push_back(m_);
		std::vector<int> a_; // массив из чисел
		for (j = 0; j < m_; j++)
		{
			std::cin >> temp;
			a_.push_back(temp);
		}
		a.push_back(a_);
	}

	// Выполняем сравнения в тестах
	for (i = 0; i < n; i++)
	{
		std::vector<int> a_; // массив из чисел
		m_ = m.front(); // количество лежаков в тесте
		a_ = a.front(); // список из чисел, характеризующих лежаки в тесте
		min_ = a_[0] ^ a_[1]; // минимальное значение непохожести двух лежаков в тесте
		for (j = 0; j < m_; j++)
		{
			for (k = j + 1; k < m_; k++)
			{
				if ((a_[j] ^ a_[k]) < min_)
				{
					min_ = a_[j] ^ a_[k];
				}
			}
		}
		std::cout << min_ << std::endl;
		m.pop_front();
		a.pop_front();
	}
}