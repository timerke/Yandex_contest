#include <iostream>
#include <string>
#include <map>
#include <algorithm>

// Функция переводит строку в верхний регистр
std::string str_toupper(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
	return s;
}

// Функция переводит число из римской системы счисления в десятичную
int rome_to_decimal(std::string rome)
{
	// Словарь, хранящий значения римских цифр
	std::map<char, int>	rome_base;
	rome_base['I'] = 1;
	rome_base['V'] = 5;
	rome_base['X'] = 10;
	rome_base['L'] = 50;
	rome_base['C'] = 100;
	rome_base['D'] = 500;
	rome_base['M'] = 1000;
	// 
	int n = rome.length();
	int decimal = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((rome_base[rome[i]] > rome_base[rome[j]]) || (rome_base[rome[i]] == rome_base[rome[j]] && j == n - 1))
			{
				decimal += rome_base[rome[i]];
				break;
			}
			else if (rome_base[rome[i]] < rome_base[rome[j]])
			{
				decimal -= rome_base[rome[i]];
				break;
			}
		}
	}
	decimal += rome_base[rome[n - 1]];
	return decimal;
}

// Функция переводит число из десятичной системы счисления в римскую
std::string decimal_to_rome(int decimal)
{
	// Словарь, хранящий значения десятичных чисел
	std::map<int, char> temp;
	temp[1] = 'I';
	temp[5] = 'V';
	std::map<int, std::map<int, char>> decimal_base;
	decimal_base[1] = temp;
	temp[1] = 'X';
	temp[5] = 'L';
	decimal_base[10] = temp;
	temp[1] = 'C';
	temp[5] = 'D';
	decimal_base[100] = temp;
	temp[1] = 'M';
	decimal_base[1000] = temp;
	// Для правильной записи больших чисел римскими цифрами необходимо
	// сначала записать число тысяч, затем сотен, затем десятков и единиц
	int  base[] = {1000, 100, 10, 1};
	const int N = 4;
	std::string rome("");
	for (int i = 0; i < N; i++)
	{
		int nums = decimal / base[i]; // число тысяч, сотен, десятков или единиц
		decimal %= base[i];
		if (base[i] == 1000)
		{
			while (nums)
			{
				nums--;
				rome.append(&decimal_base[base[i]][1], 0, 1);
			}
		}
		else
		{
			while (nums)
			{
				if (nums == 9)
				{
					rome.append(&decimal_base[base[i]][1], 0, 1);
					rome.append(&decimal_base[base[i - 1]][1], 0, 1);
					nums = 0;
				}
				else if (nums == 4)
				{
					rome.append(&decimal_base[base[i]][1], 0, 1);
					rome.append(&decimal_base[base[i]][5], 0, 1);
					nums = 0;
				}
				else if (nums >= 5)
				{
					rome.append(&decimal_base[base[i]][5], 0, 1);
					nums -= 5;
				}
				else if (nums >= 1)
				{
					rome.append(&decimal_base[base[i]][1], 0, 1);
					nums -= 1;
				}
			}
		}
	}
	return rome;
}

int main()
{
	std::cout << "Enter a number in the Roman numeral system: ";
	std::string rome; // строка для числа в римской системе счисления
	std::getline(std::cin, rome);
	rome = str_toupper(rome);
	int decimal = rome_to_decimal(rome);
	std::cout << "Decimal number: " << decimal << ".\n";
	std::cout << "Again Roman number: " << decimal_to_rome(decimal) << ".\n";
}