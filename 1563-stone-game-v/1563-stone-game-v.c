#include <stdlib.h>
int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int *prefix = (int *)malloc((n + 1) * sizeof(int));
    int *dp = (int *)calloc(n * n, sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + stoneValue[i];
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                int left = prefix[k + 1] - prefix[l];
                int right = prefix[r + 1] - prefix[k + 1];
                if (left < right){
                    int val = left + dp[l * n + k];
                    if (val > dp[l * n + r])
                        dp[l * n + r] = val;
                }
                else if (right < left){
                    int val = right + dp[(k + 1) * n + r];
                    if (val > dp[l * n + r])
                        dp[l * n + r] = val;
                } 
                else{
                    int leftVal = left + dp[l * n + k];
                    int rightVal = right + dp[(k + 1) * n + r];
                    if (leftVal > dp[l * n + r])
                        dp[l * n + r] = leftVal;
                    if (rightVal > dp[l * n + r])
                        dp[l * n + r] = rightVal;
                }
            }
        }
    }
    int ans = dp[n - 1];
    free(prefix);
    free(dp);
    return ans;
}