int minimumDeletions(int* nums, int numsSize) {
    int minPos = 0, maxPos = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[minPos])
            minPos = i;
        if (nums[i] > nums[maxPos])
            maxPos = i;
    }
    if (minPos > maxPos) {
        int temp = minPos;
        minPos = maxPos;
        maxPos = temp;
    }
    int front = maxPos + 1;
    int back = numsSize - minPos;
    int bothFront = maxPos + 1;
    int bothBack = numsSize - minPos;
    int mixed = (minPos + 1) + (numsSize - maxPos);
    int ans = bothFront;
    if (bothBack < ans)
        ans = bothBack;
    if (mixed < ans)
        ans = mixed;
    return ans;
}