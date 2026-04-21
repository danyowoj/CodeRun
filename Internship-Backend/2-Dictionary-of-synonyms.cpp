#include <iostream>
#include <map>
#include <string>

int main()
{
    // number of pairs
    int n;
    std::cin >> n;

    // dictionary of synonyms
    std::map<std::string, std::string> synonyms;

    // filling up the dictionary
    std::string word1, word2;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> word1 >> word2;
        // linking words
        synonyms[word1] = word2;
        synonyms[word2] = word1;
    }

    std::string query;
    std::cin >> query;

    std::cout << synonyms[query] << std::endl;

    return 0;
}
