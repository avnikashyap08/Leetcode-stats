#include <stdlib.h>
int stoneGameVIII(int* stones, int stonesSize) {
    int n = stonesSize;
    long long *p = malloc(n * sizeof(long long));
    p[0] = stones[0];
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + stones[i];
    long long ans = p[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        long long cur = p[i] - ans;
        if (cur > ans)
            ans = cur;
    }
    free(p);
    return (int)ans;
}