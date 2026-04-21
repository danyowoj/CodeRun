#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::unordered_set<std::string> unique_words;
    std::string word;

    while (std::cin >> word)
    {
        if (word.empty())
            break;
        unique_words.insert(word);
    }

    std::cout << "Answer: " << unique_words.size() << std::endl;

    return 0;
}
