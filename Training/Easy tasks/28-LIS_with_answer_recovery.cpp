#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // sequence size
    int n;
    std::cin >> n;

    // sequence
    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i)
        std::cin >> sequence[i];

    std::vector<int> dp(n, 1);    // subsequence length
    std::vector<int> prev(n, -1); // ancestors

    // best sequence path
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (sequence[j] < sequence[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // searching the end of the best sequence
    int best_len = 0, best_pos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] > best_len)
        {
            best_len = dp[i];
            best_pos = i;
        }
    }

    // recovering the answer
    std::vector<int> answer_indices;
    int cur = best_pos;
    while (cur != -1)
    {
        answer_indices.push_back(cur);
        cur = prev[cur];
    }
    reverse(answer_indices.begin(), answer_indices.end());

    for (int idx : answer_indices)
        std::cout << sequence[idx] << " ";
    std::cout << std::endl;

    return 0;
}
