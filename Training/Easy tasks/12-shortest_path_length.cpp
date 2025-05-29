#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N; // Количество вершин
    cin >> N;

    // Мтарица смежности
    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> adj[i][j];

    int start, finish;
    cin >> start >> finish;
    // Перевод в 0-индексацию для удоства работы
    start--;
    finish--;

    vector<bool> visited(N, false); // Метки о посещенности вершины
    vector<int> dist(N, -1);        // Расстояние (число ребер от start)

    queue<int> q;

    // Начинаем обход с вершины start
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    // BFS обход
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        // Перебираем всех соседей v
        for (int u = 0; u < N; u++)
        {
            // Если есть ребро `v -> u` и мы еще не были в `u`
            if (adj[v][u] == 1 && !visited[u])
            {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    cout << dist[finish] << endl;

    return 0;
}
