#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;

    int nums[3];
    for (int i = 0; i < 3; i++)
        cin >> nums[i];
    sort(begin(nums), end(nums));
    cout << nums[1] << endl;

    return 0;
}
