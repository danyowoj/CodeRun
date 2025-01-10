#include <iostream>
#include <sstream>

using namespace std;

// Функция для ввода матрицы
void inputMatrix(int matrix[][100], int rows, int cols)
{
    string line;
    for (int i = 0; i < rows; ++i)
    {
        getline(cin >> ws, line); // Считываем строку целиком (с ws для очистки потока)
        stringstream ss(line);    // Поток для обработки строки
        for (int j = 0; j < cols; ++j)
        {
            ss >> matrix[i][j]; // Извлекаем элементы из строки
        }
    }
}

// Функция для вывода матрицы
void printMatrix(const int matrix[][100], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // * ВВОД
    // В первой стоке вводятся 3 числа n,m,k
    int n, m, k;
    std::cin >> n >> m >> k;

    int A[100][100], B[100][100], C[100][100];
    // Далее следуют n строк по m чисел в каждой - элементы матрицы A
    inputMatrix(A, n, m);
    // Затем вводятся m строк по k чисел в каждой - элементы матрицы B
    inputMatrix(B, m, k);

    
    /* 
    * Умножение матриц
           n
    C_ij = ∑ A_ik B_ik
           k=1
    */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            C[i][j] = 0;
            for (int l = 0; l < m; ++l)
            {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    /*
    * Транспонирование матрицы 
    (строки становятся столбцами)
    (A^T)_ij = A_ji
    */
    int D[k][n];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            D[i][j] = C[j][i];
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
