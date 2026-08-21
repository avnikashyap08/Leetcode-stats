long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
long long count(long long x, int *coins, int n) {
    long long ans = 0;
    int total = 1 << n;
    for (int mask = 1; mask < total; mask++) {
        long long v = 1;
        int bits = 0;
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bits++;
                v = lcm(v, coins[i]);
                if (v > x) {
                    ok = 0;
                    break;
                }
            }
        }
        if (!ok)
            continue;
        if (bits % 2)
            ans += x / v;
        else
            ans -= x / v;
    }
    return ans;
}
long long findKthSmallest(int* coins, int coinsSize, int k) {
    long long lo = 1;
    long long hi = (long long)coins[0] * k;
    for (int i = 1; i < coinsSize; i++) {
        long long v = (long long)coins[i] * k;
        if (v < hi)
            hi = v;
    }
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (count(mid, coins, coinsSize) >= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}