#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component)
{
    visited[u] = true;      // отмечаем вершину как посещенную
    component.push_back(u); // добавляем вершину в компоненту

    // перебираем все смежные вершины
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, adj, visited, component); // рекурсивно вызываем DFS
        }
    }
}

int main()
{
    // кол-во вершин (N) и ребер (M)
    int N, M;

    cin >> N >> M;

    vector<vector<int>> adj(N + 1); // список смежных вершин

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(N + 1); // вектор посещенных вершин
    vector<int> component;       // вектор для хранения вершин компоненты связности

    // запускаем DFS из вершины 1
    dfs(1, adj, visited, component);

    // сортируем вершины компоненты
    sort(component.begin(), component.end());

    cout << component.size() << endl;
    for (int v : component)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
