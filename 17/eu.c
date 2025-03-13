#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    const int N = n, M = m, K = k;

    // построить матрицу
    char field[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            field[i][j] = '0';
        }
    }

    int p, q;
    for (int i = 0; i < K; i++)
    {
        // ввод
        scanf("%d %d", &p, &q);
        p--;
        q--;

        // ставим мину -> увеличиваем значение клеток
        if (field[p][q] != '*')
        {
            field[p][q] = '*';

            if (p - 1 >= 0 && field[p - 1][q] != '*')
                field[p - 1][q] += 1;

            if (q - 1 >= 0 && field[p][q - 1] != '*')
                field[p][q - 1] += 1;

            if (p - 1 >= 0 && q - 1 >= 0 && field[p - 1][q - 1] != '*')
                field[p - 1][q - 1] += 1;

            if (p + 1 < N && field[p + 1][q] != '*')
                field[p + 1][q] += 1;

            if (q + 1 < M && field[p][q + 1] != '*')
                field[p][q + 1] += 1;

            if (p + 1 < N && q + 1 < M && field[p + 1][q + 1] != '*')
                field[p + 1][q + 1] += 1;

            if (p - 1 >= 0 && q + 1 < M && field[p - 1][q + 1] != '*')
                field[p - 1][q + 1] += 1;

            if (p + 1 < N && q - 1 >= 0 && field[p + 1][q - 1] != '*')
                field[p + 1][q - 1] += 1;
        }
    }

    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c ", field[i][j]);
        printf("\n");
    }

    return 0;
}
