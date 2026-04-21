#include <iostream>
#include <vector>
#include <deque>

int main()
{
    // sequence size and window size
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i)
        std::cin >> sequence[i];

    // processing the first window
    std::deque<int> dq; // stores indices
    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && sequence[dq.back()] >= sequence[i])
            dq.pop_back();
        dq.push_back(i);
    }
    std::cout << sequence[dq.front()] << std::endl;

    // processing other windows
    for (int i = k; i < n; ++i)
    {
        // removing indices to the left of the window (i-k)
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // adding new element
        while (!dq.empty() && sequence[dq.back()] >= sequence[i])
            dq.pop_back();
        dq.push_back(i);

        std::cout << sequence[dq.front()] << std::endl;
    }

    return 0;
}
