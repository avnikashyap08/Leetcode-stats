#include <stdlib.h>
#include <string.h>
char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);
    int cnt[26] = {0};
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    char *ans = malloc(n + 1);
    int i = 0;
    while (i < n) {
        int c = target[i] - 'a';
        if (cnt[c] == 0)
            break;
        ans[i] = target[i];
        cnt[c]--;
        i++;
    }
    int start = i == n ? n - 1 : i;
    for (int j = start; j >= 0; j--) {
        if (j < i)
            cnt[ans[j] - 'a']++;
        int c = target[j] - 'a';
        for (int x = c + 1; x < 26; x++) {
            if (cnt[x] > 0) {
                ans[j] = 'a' + x;
                cnt[x]--;
                int p = j + 1;
                for (int y = 0; y < 26; y++) {
                    while (cnt[y] > 0)
                        ans[p++] = 'a' + y, cnt[y]--;
                }
                ans[n] = '\0';
                return ans;
            }
        }
    }
    free(ans);
    return "";
}