#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    // Упорядочиваем стороны отверстия
    if (D > E)
    {
        swap(D, E);
    }

    // Упорядочиваем размеры кирпича
    int brick_sizes[3] = {A, B, C};
    sort(brick_sizes, brick_sizes + 3);
    int min_brick = brick_sizes[0];
    int mid_brick = brick_sizes[1];

    // Проверяем, проходят ли минимальные размеры кирпича через отверстие
    if (min_brick <= D && mid_brick <= E)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
