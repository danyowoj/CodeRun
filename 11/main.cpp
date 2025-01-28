#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // ввод количества записей в словаре
    int N;
    cin >> N;

    // создание словаря синонимов
    map<string, string> synonyms;

    // заполнение словаря
    string word1, word2;
    for (int i = 0; i < N; i++)
    {
        cin >> word1 >> word2;

        // каждое слово связывается с его синонимом
        synonyms[word1] = word2;
        synonyms[word2] = word1;
    }

    // считывание слова для поиска
    string query;
    cin >> query;

    // вывод синонима
    cout << synonyms[query] << endl;

    return 0;
}
