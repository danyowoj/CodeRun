#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c; // Ввод коэффициентов a, b, c

    double discriminant = b * b - 4 * a * c; // Вычисление дискриминанта

    if (discriminant < 0)
    {
        // Если дискриминант меньше 0, корней нет
        std::cout << 0 << std::endl;
    }
    else if (discriminant == 0)
    {
        // Если дискриминант равен 0, есть один корень
        double root = -b / (2.0 * a);
        std::cout << 1 << std::endl;
        std::cout << std::fixed << std::setprecision(6) << root << std::endl;
    }
    else
    {
        // Если дискриминант больше 0, есть два корня
        double root1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2.0 * a);

        // Сохраняем корни в вектор для сортировки
        std::vector<double> roots = {root1, root2};
        std::sort(roots.begin(), roots.end()); // Сортировка корней

        std::cout << 2 << std::endl;
        std::cout << std::fixed << std::setprecision(6) << roots[0] << " " << roots[1] << std::endl;
    }

    return 0;
}
