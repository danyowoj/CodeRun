#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> numbers;
    std::istringstream iss(input);
    int number;

    // Чтение чисел из строки и добавление их в вектор
    while (iss >> number)
    {
        numbers.push_back(number);
    }

    int count = 0;

    // Перебор элементов, начиная с 1 и заканчивая на n-2
    for (size_t i = 1; i < numbers.size() - 1; ++i)
    {
        if (numbers[i] > numbers[i - 1] && numbers[i] > numbers[i + 1])
        {
            ++count; // Увеличиваем счетчик, если условие выполнено
        }
    }

    std::cout << count << std::endl; // Выводим результат

    return 0;
}
