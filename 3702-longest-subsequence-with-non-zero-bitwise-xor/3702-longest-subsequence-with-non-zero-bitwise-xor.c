int longestSubsequence(int* nums, int numsSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++)
        x ^= nums[i];
    if (x != 0)
        return numsSize;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != 0)
            return numsSize - 1;
    }
    return 0;
}