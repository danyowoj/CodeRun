#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> c(n);
    for (int i = 0; i < n; ++i)
        std::cin >> c[i];

    long long answer = 0;
    for (int i = 0; i < n - 1; ++i)
        answer += std::min(c[i], c[i + 1]);

    std::cout << answer << std::endl;

    return 0;
}
