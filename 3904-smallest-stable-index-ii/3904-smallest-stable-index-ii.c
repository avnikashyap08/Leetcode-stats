int firstStableIndex(int* nums, int numsSize, int k) {
    int suffixMin[numsSize];
    suffixMin[numsSize - 1] = nums[numsSize - 1];
    for(int i = numsSize - 2; i >= 0; i--)
        suffixMin[i] = nums[i] < suffixMin[i + 1] ? nums[i] : suffixMin[i + 1];
    int max = nums[0];
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > max)
            max = nums[i];
        if(max - suffixMin[i] <= k)
            return i;
    }
    return -1;
}