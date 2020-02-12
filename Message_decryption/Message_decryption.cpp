#include <iostream>
#include <string>
#include <vector>

void swap(std::string& a, std::string& b)
{
	std::string temp;
	temp = a;
	a = b;
	b = temp;
}

// Функция сортирует вектор со словами по увеличению длины слов
void selection_sort(std::vector<std::string>* array)
{
	int size = array->size();
	for (int i = 0; i < size - 1; i++)
	{
		int min_i = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j].size() < array[min_i].size())
			{
				min_i = j;
			}
		}
		if (min_i != i)
		{
			swap(array[i], array[min_i]);
			min_i = i;
		}
	}
}

// Функция разбивает текст на слова
void words_in_text(std::string* text, std::vector<std::string>* words)
{
	int first = 0, last = 0;
	int i = 0;
	while (true)
	{
		last = text->find_first_of(' ', first);
		if (last == std::string::npos)
		{
			words->push_back(text->substr(first, last));
			break;
		}
		else
		{
			words->push_back(text->substr(first, last - first));
		}
		first = last + 1;
	}
}

// Функция вычисляет, как получить из символа a символ b
int shift_calculation(char a, char b)
{
	const int SIZE = 26;
	if (a < b)
	{
		return b - a;
	}
	else
	{
		return SIZE + b - a;
	}
}

// Функция реализует расшифровку зашифрованного слова
std::string& decoding(std::vector<std::string>* words, std::string* encoded_word)
{
	int size = encoded_word->size(); // длина зашифрованного слова
	for (int i = 0; i < words->size(); i++)
	{
		if (words->at(i).size() == size)
		{
			// Если совпала длина зашифрованного слова и длина слова из текста для шифрования
			int shift = shift_calculation(words->at(i).at(0), encoded_word->at(0)); // сдвиг для первого символа в слове и зашифованном слове
			int j = 1; // позиция символа
			while (j < size && shift == shift_calculation(words->at(i).at(j), encoded_word->at(j)))
			{
				j++;
			}
			if (j == size)
			{
				// Если для всех символов в слове и зашифрованном слове требуется одинаковый сдвиг, то слово расшифровано
				return words->at(i);
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	// Получаем полную информацию об условии задачи
	std::string text; // текст, слова из которого зашифрованы
	std::getline(std::cin, text);
	std::vector<std::string> words; // вектор со словами из текста
	words_in_text(&text, &words); // получаем слова из текста
	//selection_sort(&words);
	int n; // количество зашифрованных слов
	std::cin >> n;
	std::string decoded_text = ""; // расшифрованный текст
	for (int i = 0; i < n; i++)
	{
		std::string encoded_word; // зашифрованное слово
		std::cin >> encoded_word;
		decoded_text += decoding(&words, &encoded_word) + "\n"; // расшифровка слова
	}
	//
	std::cout << decoded_text;
}