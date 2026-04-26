#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // amount of segments
    int n;
    std::cin >> n;

    // amount of points
    int m;
    std::cin >> m;

    std::vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        L[i] = std::min(a, b);
        R[i] = std::max(a, b);
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    for (int i = 0; i < m; ++i)
    {
        int x;
        std::cin >> x;
        int cntL = upper_bound(L.begin(), L.end(), x) - L.begin();
        int cntR = lower_bound(R.begin(), R.end(), x) - R.begin();
        std::cout << cntL - cntR << " ";
    }
    std::cout << std::endl;

    return 0;
}
