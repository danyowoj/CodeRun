Школьники из объединения КРОШ (Клуб Решателей Олимпиад Школьников) готовятся к участию в треке ML. Начать подготовку они решили с изучения линейной алгебры. Выяснилось, что существует две интересные операции над матрицами - умножение и траспонирование. Они составили много примеров и решают их на листике, однако им нужна помощь в проверке результатов. Напишите программу, которая по заданным матрицам 
A и B вычисляет:
(A x B)^T,
где A — матрица размером n×m, а B — матрица размером m×k.
Напомним, как работают данные операции:

- Умножение матриц A×B=C:

       n
C_ij = ∑ A_ik B_ik
       k=1
​
- Транспонирование матрицы (столбцы становятся строками):
(A^T)_ij = A_ji

##### Формат ввода
В первой стоке вводятся 3 числа n,m,k (1 ≤ n, m, k ≤ 100).​
Далее следуют n строк по m чисел в каждой - элементы матрицы A (0 ≤ Aij ≤ 10)
Затем вводятся m строк по k чисел в каждой - элементы матрицы B (0 ≤ Bij ≤ 10).

##### Формат вывода
Выведите матрицу результата операции (A×B)^T.

##### Пример 1
Ввод        Вывод
1 2 1       59 
3 4 
9 
8 

##### Пример 2
Ввод        Вывод
2 1 3       0 2 
0           0 4 
2           0 16 
1 2 8 

##### Пример 3
Ввод        Вывод
6 1 4       60 10 30 30 10 90 
6           12 2 6 6 2 18 
1           0 0 0 0 0 0 
3           18 3 9 9 3 27 
3 
1 
9 
10 2 0 3 
