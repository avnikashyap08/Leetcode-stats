#include <stdlib.h>
int maxSubarrayLength(int* nums, int numsSize, int k) {
    int capacity = numsSize * 2 + 1;
    int *keys = (int *)calloc(capacity, sizeof(int));
    int *freq = (int *)calloc(capacity, sizeof(int));
    int left = 0;
    int maxLen = 0;
    for (int right = 0; right < numsSize; right++){
        int key = nums[right];
        int idx = ((unsigned int)key * 2654435761u) % capacity;
        while (keys[idx] != 0 && keys[idx] != key)
            idx = (idx + 1) % capacity;
        if (keys[idx] == 0)
            keys[idx] = key;
        freq[idx]++;
        while (freq[idx] > k){
            int leftKey = nums[left];
            int leftIdx = ((unsigned int)leftKey * 2654435761u) % capacity;
            while (keys[leftIdx] != leftKey)
                leftIdx = (leftIdx + 1) % capacity;
            freq[leftIdx]--;
            left++;
        }
        int len = right - left + 1;
        if (len > maxLen)
            maxLen = len;
    }
    free(keys);
    free(freq);
    return maxLen;
}