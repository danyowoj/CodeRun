#include <iostream>
#include <vector>

using namespace std;

// Функция проверки, является ли вектор симметричным
bool isSymmetrical(vector<int> &arr, int start)
{
    int left = start;
    int right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }

    return true;
}

int main()
{
    //* ВВОД ДАННЫХ
    int N; // длина последовательности
    cin >> N;

    vector<int> arr(N); // последовательность
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    //* Проверка на симметричность
    // Если последовательность уже симметрична, заканчиваем работу
    if (isSymmetrical(arr, 0))
    {
        cout << "0" << endl;
        return 0;
    }

    // поиск минимального суффикса, который является симметричным
    int min_add = 0;
    for (int i = 0; i < N; i++)
    {
        if (isSymmetrical(arr, i))
        {
            min_add = i;
            break;
        }
    }

    // дополняем недостающими элементами (числа перед индексом min_add в обратном порядке)
    cout << min_add << endl;
    for (int i = min_add - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
