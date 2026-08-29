#include <stdlib.h>
typedef struct {
    int val;
    int idx;
} Pair;
int cmp(const void *a, const void *b) {
    Pair *x = (Pair *)a;
    Pair *y = (Pair *)b;
    if (x->val < y->val) return -1;
    if (x->val > y->val) return 1;
    return 0;
}
int cmpInt(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}
int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    Pair *arr = malloc(numsSize * sizeof(Pair));
    int *ans = malloc(numsSize * sizeof(int));
    int *values = malloc(numsSize * sizeof(int));
    int *indices = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    qsort(arr, numsSize, sizeof(Pair), cmp);
    int start = 0;
    while (start < numsSize) {
        int end = start;
        while (end + 1 < numsSize && (long long)arr[end + 1].val - arr[end].val <= limit) {
            end++;
        }
        int len = end - start + 1;
        for (int i = 0; i < len; i++) {
            values[i] = arr[start + i].val;
            indices[i] = arr[start + i].idx;
        }
        qsort(values, len, sizeof(int), cmpInt);
        qsort(indices, len, sizeof(int), cmpInt);
        for (int i = 0; i < len; i++){
            ans[indices[i]] = values[i];
        }
        start = end + 1;
    }
    free(arr);
    free(values);
    free(indices);
    *returnSize = numsSize;
    return ans;
}