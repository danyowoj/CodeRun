#include <iostream>
#include <string>
#include <vector>

int main()
{
    long long A = 0, B = 0;

    std::cin >> A >> B;

    while ((A < 0) || (A > 2 * 1e18) || (B < 0) || (B > 2 * 1e18))
    {
        std::cin >> A >> B;
    }

    std::cout << A + B << std::endl;

    return 0;
}
