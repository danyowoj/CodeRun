#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, T, Q;
    cin >> N >> M >> S >> T >> Q;
    // Переводим координаты «кормушки» в нулевой базис
    int start_r = S - 1;
    int start_c = T - 1;

    // Делаем матрицу расстояний размером N x M, инициализируем -1
    vector<vector<int>> dist(N, vector<int>(M, -1));

    // Смещения ходов коня (8 вариантов)
    static const int dr[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
    static const int dc[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

    // BFS от кормушки
    queue<pair<int, int>> q;
    dist[start_r][start_c] = 0;
    q.push({start_r, start_c});

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        int d = dist[r][c];
        // Перебираем все 8 ходов коня
        for (int k = 0; k < 8; ++k)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];
            // Проверим границы
            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            // Если ещё не посещали — записываем расстояние и кладём в очередь
            if (dist[nr][nc] == -1)
            {
                dist[nr][nc] = d + 1;
                q.push({nr, nc});
            }
        }
    }

    // Теперь обрабатываем каждую блоху, суммируем её дистанцию до кормушки
    long long totalSum = 0;
    for (int i = 0; i < Q; ++i)
    {
        int x, y;
        cin >> x >> y;
        int rr = x - 1;
        int cc = y - 1;
        // Если блоха не может дойти (dist == -1) — сразу печатаем -1 и выходим
        if (dist[rr][cc] == -1)
        {
            cout << -1 << "\n";
            return 0;
        }
        totalSum += dist[rr][cc];
    }

    // Если дошли до сюда, значит все Q блох достижимы, выводим сумму
    cout << totalSum << "\n";
    return 0;
}
