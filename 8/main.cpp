#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    // ввод строки со списком
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> numbers;
    std::istringstream iss(input);
    int number;

    // чтение чисел из строки и добавление их в вектор
    while (iss >> number)
    {
        numbers.push_back(number);
    }

    // цикл по элементам списка
    for (int i = 1; i < numbers.size(); i++)
    {
        // если список не возрастающий
        // выводим NO и завершаем программу
        if (numbers[i] <= numbers[i - 1])
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    // если список возрастающий
    // выводим YES и завершаем программу 
    std::cout << "YES" << std::endl;
    return 0;
}