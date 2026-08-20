/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int *a = malloc(numsSize * sizeof(int));
    int *b = malloc(numsSize * sizeof(int));
    int x = 0, y = 0;
    a[x++] = nums[0];
    b[y++] = nums[1];
    for (int i = 2; i < numsSize; i++) {
        if (a[x - 1] > b[y - 1])
            a[x++] = nums[i];
        else
            b[y++] = nums[i];
    }
    int *ans = malloc(numsSize * sizeof(int));
    for (int i = 0; i < x; i++)
        ans[i] = a[i];
    for (int i = 0; i < y; i++)
        ans[x + i] = b[i];
    free(a);
    free(b);
    *returnSize = numsSize;
    return ans;
}