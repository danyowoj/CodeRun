#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printVector(const std::vector<T> &vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main()
{
    // кирпич размером AxBxC
    // отверстие размером DxE

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    vector<int> brick_sides;
    brick_sides.push_back(A);
    brick_sides.push_back(B);
    brick_sides.push_back(C);
    sort(begin(brick_sides), end(brick_sides));

    vector<int> hole_sides;
    hole_sides.push_back(D);
    hole_sides.push_back(E);
    sort(begin(hole_sides), end(hole_sides));

    if ((brick_sides[0] <= hole_sides[0]) && (brick_sides[1] <= hole_sides[1]))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
