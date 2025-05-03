#include <iostream>
#include <sstream>
#include <set>
#include <string>

int main()
{
    // Вводим многострочный текст
    std::string input;
    std::string line;

    while (std::getline(std::cin, line))
    {
        if (line.empty()) // Пустая строка завершает ввод
            break;
        input += line + '\n'; // Добавляем строку и перенос строки
    }

    // Определяем разделители текста
    const std::string separators = " \n";

    // Используем set для хранения уникальных слов
    std::set<std::string> unique_words;

    size_t start = input.find_first_not_of(separators);

    while (start != std::string::npos)
    {
        size_t end = input.find_first_of(separators, start);
        if (end == std::string::npos)
            end = input.length();

        // Извлекаем слово и добавляем его в set
        std::string word = input.substr(start, end - start);
        unique_words.insert(word);

        start = input.find_first_not_of(separators, end);
    }

    // Выводим количество уникальных слов
    std::cout << unique_words.size() << std::endl;

    return 0;
}
