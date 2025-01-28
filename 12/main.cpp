#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N; // размер массива
    cin >> N;

    vector<int> array(N); // массив чисел
    for (int i = 0; i < N; i++)
        cin >> array[i];

    int x; // число для поиска
    cin >> x;

    int closest = array[0];          // предполагаем, что ближайший элемент первый
    int minDiff = abs(array[0] - x); // Разница между первым элементом и заданным числом
    for (int i = 0; i < N; i++)
    {
        int diff = abs(array[i] - x);
        if (diff < minDiff)
        {
            minDiff = diff;
            closest = array[i];
        }
    }

    cout << closest << endl;

    return 0;
}
