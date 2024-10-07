#include <iostream>
#include <string>
#include <vector>

int main()
{
    // sides
    int A, B, C;

    // entering sides
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    // checking for possible triangle
    if ((A + B > C) && (A + C > B) && (B + C) > A)
        std::cout << "YES" << std::endl;

    else
        std::cout << "NO" << std::endl;

    return 0;
}
