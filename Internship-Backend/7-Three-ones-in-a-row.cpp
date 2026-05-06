#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    long long dp0 = 1, dp1 = 1, dp2 = 0; // for i = 1
    for (int i = 2; i < n + 1; ++i)
    {
        long long new0 = dp0 + dp1 + dp2;
        long long new1 = dp0;
        long long new2 = dp1;
        dp0 = new0;
        dp1 = new1;
        dp2 = new2;
    }
    long long ans = dp0 + dp1 + dp2;

    std::cout << ans << std::endl;

    return 0;
}
