#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();

    vector<int> cnt(26, 0); // частоста букв в текущем окне
    int left = 0;
    int ans = 0;
    int maxFreq = 0; // максимальная частота в окне

    for (int right = 0; right < n; ++right)
    {
        // добавляем первый символ в окно
        int idx = s[right] - 'a';
        cnt[idx]++;
        // Обновляем максимум — пока без пересчёта, он может быть завышен,
        // но при проверке условия мы потом скорректируем
        maxFreq = max(maxFreq, cnt[idx]);

        // Пока условие нарушено, сдвигаем левую границу
        while ((right - left + 1) - maxFreq > k)
        {
            // Убираем левый символ
            int leftIdx = s[left] - 'a';
            cnt[leftIdx]--;
            left++;
            // Обязательно пересчитываем maxFreq по всему массиву
            maxFreq = 0;
            for (int i = 0; i < 26; ++i)
            {
                if (cnt[i] > maxFreq)
                {
                    maxFreq = cnt[i];
                }
            }
        }
        // Текущее окно удовлетворяет условию: обновляем ответ
        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;

    return 0;
}
