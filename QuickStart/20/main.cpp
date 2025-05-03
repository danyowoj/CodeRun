#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "Unable to open the file!" << endl;
        return 1;
    }

    unordered_map<string, int> word_counts;
    string word;

    while (file >> word)
    {
        int count = word_counts[word];

        cout << count << " ";

        word_counts[word]++;
    }
    cout << endl;

    file.close();

    return 0;
}
