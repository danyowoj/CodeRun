#include <iostream>
#include <cstdlib>

// вычисление НОД алгоритмом Евклида
int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// вычисление НОК по формуле |a*b| / НОД(a,b)
long long lcm(int a, int b)
{
    return std::abs(1LL * a * b) / gcd(a, b); // Используем long long для предотвращения переполнения
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    int nod = gcd(a, b);
    long long nok = lcm(a, b);

    std::cout << nod << " " << nok << std::endl;

    return 0;
}
