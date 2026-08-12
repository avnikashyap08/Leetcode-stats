#include <stdlib.h>
char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        int sum = 0;
        int best = -1000000000;
        for (int j = 0; j < 3 && i + j < n; j++){
            sum += stoneValue[i + j];
            int current = sum - dp[i + j + 1];
            if (current > best)
                best = current;
        }
        dp[i] = best;
    }
    char *result;
    if (dp[0] > 0){
        result = "Alice";
    }
    else if (dp[0] < 0){
        result = "Bob";
    }
    else{
        result = "Tie";
    }
    free(dp);
    return result;
}