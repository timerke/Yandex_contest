#include <fstream>
#include <iostream>
#include <time.h>
#include <Windows.h>

// Функция определяет количество живых клеток - соседей клетки i, j
int number_of_living(int** c, int i, int j, int M, int N)
{
	int n = 0;
	for (int i_ = i - 1; i_ <= i + 1; i_++)
	{
		if (-1 < i_ && i_ < M)
		{
			for (int j_ = j - 1; j_ <= j + 1; j_++)
			{
				if (-1 < j_ && j_ < N && (i != i_ || j != j_) && c[i_][j_])
				{
					n++;
				}
			}
		}
	}
	return n;
}
	
// Функция определяет жизненный цикл клеток
void life_activity(int** c, int** c_n, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nl = number_of_living(c, i, j, M, N); // количество живых соседей у клетки i, j
			if (c[i][j] && (nl < 2 || nl > 3))
			{
				// Клетка умирает
				c_n[i][j] = 0;
			}	
			else if (c[i][j] == 0 && nl == 3)
			{
				// Клетка рождается
				c_n[i][j] = 1;
			}
			else
			{
				// С клеткой ничего не происходит
				c_n[i][j] = c[i][j];
			}
			printf("\t%d", c[i][j]);
		}
		printf("\n");
	}
}	

int main(int argc, char* argv[])
{
	const int MAX_MN = 10; // максимальный возможный размер доски
	int	M, N; // количество строк и столбцов
	int i, j;
	// Этапы жизни доски будут записываться поочередно на две доски
	int** cells; // двумерный массив, представляющий собой доску
	int** cells_copy; // копия двумерного массива, представляющего собой доску
	if (argc >= 2)
	{
		// Если при запуске в консоли передается имя файла со стартовым состоянием доски
		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
			// Если файл не открыт
			return -1;
		}
		file >> M >> N;
		cells = new int* [M];
		cells_copy = new int* [M];
		for (i = 0; i < M; i++)
		{
			cells[i] = new int[N];
			cells_copy[i] = new int[N];
			for (j = 0; j < N; j++)
			{
				file >> cells[i][j];
				cells_copy[i][j] = 0;
			}
		}
		file.close();
	}
	else
	{
		// Если при запуске не передается файл со стартовым состоянием,
		// определяем случайным образом начальное состояние доски
		srand(time(NULL));
		M = rand() % MAX_MN + 1; // количество строк
		N = rand() % MAX_MN + 1; // количество столбцов
		cells = new int* [M];
		cells_copy = new int* [M];
		for (i = 0; i < M; i++)
		{
			cells[i] = new int[N];
			cells_copy[i] = new int[N];
			for (j = 0; j < N; j++)
			{
				cells[i][j] = rand() % 2;
				cells_copy[i][j] = 0;
			}
		}
	}

	// Жизнь доски с клетками
	int t = 0; // время с момента запуска моделирования жизненного цикла доски
	while (t < 600)
	{
		printf("%d sec\n", t);
		if (t % 2 == 0)
		{
			life_activity(cells, cells_copy, M, N);
		}
		else
		{
			life_activity(cells_copy, cells, M, N);
		}
		t++;
		Sleep(1000);
	}

	for (i = 0; i < M; i++)
	{
		delete(cells[i]);
		delete(cells_copy[i]);
	}
	delete(cells);
	delete(cells_copy);
	return 0;
}