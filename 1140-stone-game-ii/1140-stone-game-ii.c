#include <stdlib.h>
int stoneGameII(int* piles, int pilesSize) {
    int n = pilesSize;
    int *suffix = (int *)malloc((n + 1) * sizeof(int));
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }
    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + piles[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int M = n; M >= 1; M--) {
            if (i + 2 * M >= n) {
                dp[i][M] = suffix[i];
            } else {
                int best = 0;
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int opponent = dp[i + X][M > X ? M : X];
                    int current = suffix[i] - opponent;
                    if (current > best)
                        best = current;
                }
                dp[i][M] = best;
            }
        }
    }
    int result = dp[0][1];
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    free(suffix);
    return result;
}