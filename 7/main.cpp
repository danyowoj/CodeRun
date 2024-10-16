#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <vector>

// * Сделать нормальный ввод, чтобы можно было скопировать пример из задания и вставить его в консоль

int main()
{
    // вводим текст
    std::string input;
    std::getline(std::cin, input);

    // определяем разделители текста
    const std::string separators = {" \n"};

    // определяем вектор для хранения слов, потому что количество сло не определено
    std::vector<std::string> words;

    // определяем индекс первого слова
    // Для этого применяется функция find_first_not_of(),
    // которая возвращает первый индекс любого символа, который не входит в строку separators
    size_t start{input.find_first_not_of(separators)};

    // Далее в цикле while смотрим, является ли полученный индекс действительным индексом
    // Например, если в строке одни только символы из набора separators, тогда функция find_first_not_of()
    // возвратит значение std::string::npos, что будет означать, что в тексте больше нет непунктационных знаков.
    while (start != std::string::npos)
    {
        // И если start указывает на действительный индекс начала слова, то находим индекс после последнего символа слова,
        // который помещаем в переменную end.
        // Для нахождения позиции окончания слова используем функцию find_first_of(),
        // которая возвращает первую позицию любого символа из separators, начиная с индекса start+1
        size_t end = input.find_first_of(separators, start + 1);

        if (end == std::string::npos) // если НЕ найден ни один из символов-разделителей
            end = input.length();     // устанавливаем переменную end на конец текста

        std::string word = input.substr(start, end - start); // выделяем слово из текста

        bool unique = true; // устанавливаем идентификатор уникальности слова
        for (int i = 0; i < words.size(); i++)
            if (word == words[i])
            {
                unique = false;
                break;
            }

        if (unique)                                            // если слово уникальное
            words.push_back(input.substr(start, end - start)); // добавляем слова в вектор

        start = input.find_first_not_of(separators, end + 1); // находим начальный индекс следующего слова и переустанавливаем start
    }

    // выводим количество слов
    std::cout << words.size() << std::endl;

    return 0;
}
