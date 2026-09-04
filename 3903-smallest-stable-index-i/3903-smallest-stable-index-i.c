int firstStableIndex(int* nums, int numsSize, int k) {
    int suffixMin[100];
    suffixMin[numsSize - 1] = nums[numsSize - 1];
    for(int i = numsSize - 2; i >= 0; i--) {
        suffixMin[i] = nums[i] < suffixMin[i + 1] ? nums[i] : suffixMin[i + 1];
    }
    int prefixMax = nums[0];
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > prefixMax){
            prefixMax = nums[i];
        }
        if(prefixMax - suffixMin[i] <= k){
            return i;
        }
    }
    return -1;
}