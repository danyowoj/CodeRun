#include <iostream>
#include <string>

int main()
{
    // Считывание ввода
    int x, y, z;
    std::cin >> x >> y >> z;

    // Возможные кнопки в множестве
    std::string availableButtons = {'0' + x, '0' + y, '0' + z};

    // Считываем число N
    std::string N;
    std::cin >> N;

    // Счетчик недостающих кнопок
    int missingButtonsCount = 0;

    // Проверяем каждую цифру в N
    for (char digit : N)
        if (availableButtons.find(digit) == -1) // если для такой цифры нет кнопки
        {
            missingButtonsCount++;              // увеличиваем счетчик
            availableButtons.push_back(digit);  // и добавляем кнопку
        }

    // Выводим результат
    std::cout << missingButtonsCount << std::endl;

    return 0;
}
