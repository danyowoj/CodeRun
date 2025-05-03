#include <iostream>

using namespace std;

int main()
{
    int prev, cur;
    bool isConstant = true;
    bool isAscending = true, isWeaklyAscending = true;
    bool isDescending = true, isWeaklyDescending = true;

    // Считать первое число
    if (!(cin >> prev) || prev == -2000000000)
    {
        cout << "CONSTANT" << endl;
        return 0;
    }

    while (cin >> cur && cur != -2000000000)
    {
        if (cur > prev) // убывание нарушено
        {
            isConstant = false;
            isDescending = false;
            isWeaklyDescending = false;
        }
        else if (cur < prev) // возрастание нарушено
        {
            isConstant = false;
            isAscending = false;
            isWeaklyAscending = false;
        }
        else // строгие порядки нарушены
        {
            isAscending = false;
            isDescending = false;
        }
        prev = cur; // обновляем предыдущее значение
    }

    // определение типа последовательности
    if (isConstant)
        cout << "CONSTANT" << endl;
    else if (isAscending)
        cout << "ASCENDING" << endl;
    else if (isWeaklyAscending)
        cout << "WEAKLY ASCENDING" << endl;
    else if (isDescending)
        cout << "DESCENDING" << endl;
    else if (isWeaklyDescending)
        cout << "WEAKLY DESCENDING" << endl;
    else
        cout << "RANDOM" << endl;

    return 0;
}
