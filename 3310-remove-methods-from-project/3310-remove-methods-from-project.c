/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int to;
    int next;
} Edge;
int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    int *head = (int *)malloc(sizeof(int) * n);
    Edge *edges = (Edge *)malloc(sizeof(Edge) * invocationsSize);

    for (int i = 0; i < n; i++)
        head[i] = -1;

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        edges[i].to = v;
        edges[i].next = head[u];
        head[u] = i;
    }

    // Find all suspicious methods (reachable from k)
    bool *suspicious = (bool *)calloc(n, sizeof(bool));
    int *stack = (int *)malloc(sizeof(int) * n);
    int top = 0;

    suspicious[k] = true;
    stack[top++] = k;

    while (top) {
        int u = stack[--top];
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            if (!suspicious[v]) {
                suspicious[v] = true;
                stack[top++] = v;
            }
        }
    }

    // If any non-suspicious method invokes a suspicious one,
    // nothing can be removed.
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        if (!suspicious[u] && suspicious[v]) {
            int *ans = (int *)malloc(sizeof(int) * n);
            for (int j = 0; j < n; j++)
                ans[j] = j;

            *returnSize = n;

            free(head);
            free(edges);
            free(suspicious);
            free(stack);

            return ans;
        }
    }

    // Return remaining methods
    int *ans = (int *)malloc(sizeof(int) * n);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i])
            ans[cnt++] = i;
    }

    *returnSize = cnt;

    free(head);
    free(edges);
    free(suspicious);
    free(stack);

    return ans;
}