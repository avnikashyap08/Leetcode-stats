int distinctSubseqII(char* s) {
    const long long MOD = 1000000007;
    long long end[26] = {0};
    long long total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int c = s[i] - 'a';
        long long add = (total + 1) % MOD;
        long long newTotal = (total + add - end[c]) % MOD;
        if (newTotal < 0)
            newTotal += MOD;
        total = newTotal;
        end[c] = add;
    }
    return (int)total;
}