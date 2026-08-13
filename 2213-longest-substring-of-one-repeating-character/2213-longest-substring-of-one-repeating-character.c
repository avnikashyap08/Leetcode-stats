#include <stdlib.h>
#include <string.h>
typedef struct {
    char leftChar;
    char rightChar;
    int leftLen;
    int rightLen;
    int best;
    int len;
} Node;
Node merge(Node a, Node b) {
    Node res;
    res.len = a.len + b.len;
    res.leftChar = a.leftChar;
    res.rightChar = b.rightChar;
    res.leftLen = a.leftLen;
    res.rightLen = b.rightLen;
    res.best = a.best > b.best ? a.best : b.best;
    if (a.rightChar == b.leftChar) {
        int cross = a.rightLen + b.leftLen;
        if (cross > res.best)
            res.best = cross;
    }
    if (a.leftLen == a.len && a.leftChar == b.leftChar)
        res.leftLen = a.len + b.leftLen;
    if (b.rightLen == b.len && a.rightChar == b.rightChar)
        res.rightLen = a.rightLen + b.len;
    return res;
}
void build(Node *tree, char *s, int p, int l, int r) {
    if (l == r) {
        tree[p].leftChar = s[l];
        tree[p].rightChar = s[l];
        tree[p].leftLen = 1;
        tree[p].rightLen = 1;
        tree[p].best = 1;
        tree[p].len = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(tree, s, p * 2, l, mid);
    build(tree, s, p * 2 + 1, mid + 1, r);
    tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
}
void update(Node *tree, char *s, int p, int l, int r, int index) {
    if (l == r) {
        tree[p].leftChar = s[index];
        tree[p].rightChar = s[index];
        tree[p].leftLen = 1;
        tree[p].rightLen = 1;
        tree[p].best = 1;
        tree[p].len = 1;
        return;
    }
    int mid = (l + r) / 2;
    if (index <= mid)
        update(tree, s, p * 2, l, mid, index);
    else
        update(tree, s, p * 2 + 1, mid + 1, r, index);
    tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
}
int* longestRepeating(char* s, char* queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize){
    int n = strlen(s);
    *returnSize = queryIndicesSize;
    int *ans = (int *)malloc(queryIndicesSize * sizeof(int));
    Node *tree = (Node *)malloc(4 * n * sizeof(Node));
    build(tree, s, 1, 0, n - 1);
    for (int i = 0; i < queryIndicesSize; i++) {
        int index = queryIndices[i];
        s[index] = queryCharacters[i];
        update(tree, s, 1, 0, n - 1, index);
        ans[i] = tree[1].best;
    }
    free(tree);
    return ans;
}