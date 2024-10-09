#include <iostream>

int main()
{
    int n = 0, sum = 0;

    while ((n < 1) || (n > 35))
        std::cin >> n;

    if (n == 1)
    {
        std::cout << 1;
        return 0;
    }

    if (n == 2)
    {
        std::cout << 2;
        return 0;
    }

    // создать динамический массив тегов
    int *t = new int[n];

    // задать t[1] = t[2] = 1
    t[0] = t[1] = 1;
    sum = 2;

    // посчиать остальные теги
    for (int i = 2; i < n; i++)
    {
        t[i] = t[i - 1] + t[i - 2];
        sum += t[i];
    }

    // выветси количество
    std::cout << sum;

    return 0;
}
