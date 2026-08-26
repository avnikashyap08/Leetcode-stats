#include <stdlib.h>
#include <string.h>
char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int bestLen = n + 1;
    int bestStart = -1;
    for (int i = 0; i < n; i++) {
        int ones = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1')
                ones++;
            if (ones == k) {
                int len = j - i + 1;
                if (len < bestLen ||(len == bestLen && (bestStart == -1 ||
                strncmp(s + i, s + bestStart, len) < 0))) {
                    bestLen = len;
                    bestStart = i;
                }
                break;
            }
            if (ones > k)
                break;
        }
    }
    if (bestStart == -1)
        return "";
    char *ans = malloc((bestLen + 1) * sizeof(char));
    strncpy(ans, s + bestStart, bestLen);
    ans[bestLen] = '\0';
    return ans;
}