/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int *ans = malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;
    struct ListNode *prev = head;
    struct ListNode *cur = head->next;
    int pos = 1;
    int first = -1;
    int last = -1;
    int minDist = 1000000;
    while (cur->next != NULL) {
        struct ListNode *next = cur->next;
        if ((cur->val > prev->val && cur->val > next->val) || (cur->val < prev->val && cur->val < next->val)) {
            if (first == -1) {
                first = pos;
            }
            else {
                int dist = pos - last;
                if (dist < minDist)
                    minDist = dist;
            }
            last = pos;
        }
        prev = cur;
        cur = next;
        pos++;
    }
    if (first != -1 && first != last) {
        ans[0] = minDist;
        ans[1] = last - first;
    }
    return ans;
}