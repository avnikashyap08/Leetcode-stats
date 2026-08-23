#include <stdbool.h>
bool sumGame(char* num) {
    int n = 0, sum1 = 0, sum2 = 0;
    int q1 = 0, q2 = 0;
    while (num[n])
        n++;
    for (int i = 0; i < n / 2; i++) {
        if (num[i] == '?')
            q1++;
        else
            sum1 += num[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
        if (num[i] == '?')
            q2++;
        else
            sum2 += num[i] - '0';
    }
    if ((q1 + q2) % 2)
        return true;
    return 2 * (sum1 - sum2) != 9 * (q2 - q1);
}