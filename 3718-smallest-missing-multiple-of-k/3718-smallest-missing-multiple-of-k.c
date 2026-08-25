int missingMultiple(int* nums, int numsSize, int k) {
    int x = k;
    while (1) {
        int found = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == x) {
                found = 1;
                break;
            }
        }
        if (!found)
            return x;
        x += k;
    }
}