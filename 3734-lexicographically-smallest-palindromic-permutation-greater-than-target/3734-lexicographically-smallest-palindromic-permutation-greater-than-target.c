char* lexPalindromicPermutation(char* s, char* target) {
    int n = strlen(s);
    int cnt[26] = {0};
    for (int i = 0; i < n; i++){
        cnt[s[i]-'a']++;
    }
    int numOdd = 0, midChar = -1;
    for (int c = 0; c < 26; c++) {
        if (cnt[c] % 2 == 1){
            numOdd++;
            midChar = c;
        }
    }
    if (n % 2 == 0) {
        if (numOdd != 0){
            char* r = malloc(1); 
            r[0]='\0'; 
            return r; 
        }
    }
    else {
        if (numOdd != 1) { 
            char* r = malloc(1); 
            r[0]='\0'; 
            return r;
        }
    }
    int p[26];
    for (int c = 0; c < 26; c++){
        p[c] = cnt[c] / 2;
    }
    int half = n / 2;
    int cntP[26] = {0};
    for (int i = 0; i < half; i++){
        cntP[target[i]-'a']++;
    }
    int feasibleFull = 1;
    for (int c = 0; c < 26; c++) {
        if (cntP[c] > p[c]) { 
            feasibleFull = 0; 
            break; 
        }
    }
    if (feasibleFull) {
        char* h = malloc(half + 1);
        memcpy(h, target, half);
        h[half] = '\0';
        char* candidate = malloc(n + 1);
        memcpy(candidate, h, half);
        int pos = half;
        if (n % 2 == 1){
            candidate[pos++] = 'a' + midChar;
        }
        for (int k = half - 1; k >= 0; k--) {
            candidate[pos++] = h[k];
        }
        candidate[n] = '\0';
        if (strcmp(candidate, target) > 0) {
            free(h);
            return candidate;
        }
        free(h);
        free(candidate);
    }
    int running[26];
    memcpy(running, cntP, sizeof(cntP));
    for (int i = half - 1; i >= 0; i--) {
        running[target[i]-'a']--;
        int feasible = 1;
        for (int c = 0; c < 26; c++) {
            if (running[c] > p[c]) { 
                feasible = 0; 
                break; 
            }
        }
        if (!feasible){
            continue;
        }
        int remaining[26];
        for (int c = 0; c < 26; c++) {
            remaining[c] = p[c] - running[c];
        }
        int chosen = -1;
        for (int c = target[i]-'a' + 1; c < 26; c++) {
            if (remaining[c] > 0) { 
                chosen = c; 
                break; 
            }
        }
        if (chosen == -1){
            continue;
        }
        remaining[chosen]--;
        char* h = malloc(half + 1);
        memcpy(h, target, i);
        h[i] = 'a' + chosen;
        int idx = i + 1;
        for (int c = 0; c < 26; c++) {
            while (remaining[c] > 0) {
                h[idx++] = 'a' + c;
                remaining[c]--;
            }
        }
        h[half] = '\0';
        char* answer = malloc(n + 1);
        memcpy(answer, h, half);
        int pos = half;
        if (n % 2 == 1) {
            answer[pos++] = 'a' + midChar;
        }
        for (int k = half - 1; k >= 0; k--) {
            answer[pos++] = h[k];
        }
        answer[n] = '\0';
        free(h);
        return answer;
    }
    char* r = malloc(1);
    r[0] = '\0';
    return r;
}