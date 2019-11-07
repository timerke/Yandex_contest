#include <iostream>
#include <set>

int main(int argc, char* argv[])
{
	int n; // количество чанков на кластере
	int m; // количество серверов
	int q; // количество запросов
	std::cin >> n >> m >> q;
	int* chank = new int[n]; // массив с серверами, на которых расположены чанки
	int i, j;
	// Считывается массив с серверами, на которых расположены чанки
	for (i = 0; i < n; i++)
	{
		std::cin >> chank[i];
	}
	int** inquiries; // массив с запросами
	inquiries = new int* [q];
	// Считывается массив с запросами
	for (i = 0; i < q; i++)
	{
		inquiries[i] = new int[4];
		for (j = 0; j < 4; j++)
		{
			std::cin >> inquiries[i][j];
		}
		inquiries[i][2]--;
		inquiries[i][3]--;
	}
	// Выполняются запросы
	for (i = 0; i < q; i++)
	{
		int server_from = inquiries[i][0]; // с какого сервера нужно переместить чанки
		int	server_to = inquiries[i][1]; // на какой сервер нужно переместить чанки
		int	chank_b = inquiries[i][2]; // какой номер первого чанка, который нужно переместить
		int	chank_e = inquiries[i][3]; // какой номер последнего чанка, который нужно переместить
		for (j = chank_b; j <= chank_e; j++)
		{
			if (chank[j] != server_from)
			{
				// Если не все перемещаемые чанки находятся на нужном сервере, чанки не перемещаются
				std::cout << 0 << std::endl;
				break;
			}
		}
		if (j > chank_e)
		{
			// Если перемещаемые в запросе чанки находятся на нужном сервере, чанки перемещаются
			for (j = chank_b; j <= chank_e; j++)
			{
				chank[j] = server_to;
			}
			std::cout << 1 << std::endl;
		}
	}
	for (i = 0; i < q; i++)
	{
		delete(inquiries[i]);
	}
	delete(inquiries);
}