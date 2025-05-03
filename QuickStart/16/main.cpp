/*
S = 2a + 3b + 4c
N = a + b + c
avg = S / N
avg' = (S + 5d) / (N + d)
(S + 5d) / (N + d) ≥ 3.5
d ≥ (3.5N - S) / 1.5
d ≥ (7N - 2S + 2) / 3
*/
#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long S = 2 * a + 3 * b + 4 * c; // Сумма баллов
    long long N = a + b + c;             // Количество оценок

    // Проверяем, если уже достаточно оценок
    if (S * 2 >= 7 * N)
    {
        cout << 0 << endl;
        return 0;
    }

    // Вычисляем минимальное количество пятёрок в целочисленном виде
    long long d = (7 * N - 2 * S + 2) / 3;

    cout << d << endl;
    return 0;
}
