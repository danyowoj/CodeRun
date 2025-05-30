#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    // После чтения N сразу перейдём к чтению уровней (с переносом строки)
    string line;
    getline(cin, line); // «выпиваем» остаток первой строки

    // 3D-массив символов: grid[z][x][y]
    vector<vector<string>> grid(N, vector<string>(N));
    int sx = -1, sy = -1, sz = -1; // координаты S

    for (int z = 0; z < N; ++z)
    {
        // Между блоками может стоять пустая строка — пропускаем её
        while (true)
        {
            if (!std::getline(cin, line))
                break;
            if (!line.empty())
            {
                // Это первая строка уровня z
                grid[z][0] = line;
                break;
            }
            // иначе строка была пустой — читаем дальше
        }
        // Читаем остальные N-1 строк этого уровня
        for (int x = 1; x < N; ++x)
        {
            std::getline(cin, grid[z][x]);
        }
        // Теперь в этом блоке найдем, есть ли буква 'S'
        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                if (grid[z][x][y] == 'S')
                {
                    sx = x;
                    sy = y;
                    sz = z;
                    // Заменим «S» на «.», чтобы дальше считалось, что клетка свободна
                    grid[z][x][y] = '.';
                }
            }
        }
    }

    // Трёхмерный массив расстояний: dist[z][x][y], инициализируем -1
    static int dist[30][30][30];
    for (int z = 0; z < N; ++z)
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < N; ++y)
                dist[z][x][y] = -1;

    // BFS-очередь
    deque<tuple<int, int, int>> q;
    dist[sz][sx][sy] = 0;
    q.emplace_back(sz, sx, sy);

    // Сдвиги по 6 направлениям (x, y, z)
    static const int dx[6] = {+1, -1, 0, 0, 0, 0};
    static const int dy[6] = {0, 0, +1, -1, 0, 0};
    static const int dz[6] = {0, 0, 0, 0, +1, -1};

    while (!q.empty())
    {
        auto [z, x, y] = q.front();
        q.pop_front();
        int d = dist[z][x][y];

        // Если мы попали на уровень z=0 — уже вышли на поверхность
        if (z == 0)
        {
            cout << d << "\n";
            return 0;
        }

        // Иначе пробуем перейти в каждую из 6 смежных клеток
        for (int dir = 0; dir < 6; ++dir)
        {
            int nz = z + dz[dir];
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nz < 0 || nz >= N || nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (grid[nz][nx][ny] == '#')
                continue; // камень, невозможно пройти
            if (dist[nz][nx][ny] != -1)
                continue; // уже посещали

            dist[nz][nx][ny] = d + 1;
            q.emplace_back(nz, nx, ny);
        }
    }

    // По условию задачи выход всегда возможен,
    // так что сюда мы никогда не попадём. Но на всякий случай:
    cout << -1 << "\n";
    return 0;
}
