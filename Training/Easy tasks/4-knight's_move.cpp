#include <iostream>
#include <algorithm>

using namespace std;

long long knight_routes(int N, int M)
{
    // Проверяем условие достижимости
    if ((N + M - 2) % 3 != 0)
    {
        return 0;
    }

    int x = (2 * N - M - 1) / 3;
    int y = (2 * M - N - 1) / 3;

    // Проверяем, что x и y неотрицательные и удовлетворяют уравнениям
    if (x < 0 || y < 0 || (2 * x + y != N - 1) || (x + 2 * y != M - 1))
    {
        return 0;
    }

    // Вычисляем биномиальный коэффициент C(x+y, x)
    int n = x + y;
    int k = min(x, y);
    long long result = 1;

    for (int i = 1; i <= k; ++i)
    {
        result = result * (n - k + i) / i;
    }

    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;

    long long routes = knight_routes(N, M);
    cout << routes << endl;

    return 0;
}
