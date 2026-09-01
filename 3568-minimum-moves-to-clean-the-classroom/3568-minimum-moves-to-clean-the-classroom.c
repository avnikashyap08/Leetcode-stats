#include <stdlib.h>
#include <string.h>
typedef struct {
    int r, c, energy, mask, dist;
} State;
int minMoves(char** classroom, int classroomSize, int energy) {
    int m = classroomSize;
    int n = strlen(classroom[0]);
    int sr = 0, sc = 0;
    int litterCount = 0;
    int litter[20][20];
    int fullMask;
    int totalStates;
    int *visited;
    State *queue;
    int front = 0, back = 0;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            litter[i][j] = -1;
            if (classroom[i][j] == 'S') {
                sr = i;
                sc = j;
            } else if (classroom[i][j] == 'L') {
                litter[i][j] = litterCount++;
            }
        }
    }
    if (litterCount == 0)
        return 0;
    fullMask = (1 << litterCount) - 1;
    totalStates = m * n * (1 << litterCount) * (energy + 1);
    visited = calloc(totalStates, sizeof(int));
    queue = malloc(totalStates * sizeof(State));
    #define ID(r,c,e,mask) ((((r) * n + (c)) * (1 << litterCount) + (mask)) * (energy + 1) + (e))
    int startMask = 0;
    if (litter[sr][sc] != -1)
        startMask |= 1 << litter[sr][sc];
    int startId = ID(sr, sc, energy, startMask);
    visited[startId] = 1;
    queue[back++] = (State){sr, sc, energy, startMask, 0};
    while (front < back) {
        State cur = queue[front++];
        if (cur.mask == fullMask)
            return cur.dist;
        for (int d = 0; d < 4; d++) {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (classroom[nr][nc] == 'X')
                continue;
            if (cur.energy == 0)
                continue;
            int ne = cur.energy - 1;
            if (classroom[nr][nc] == 'R')
                ne = energy;
            int nmask = cur.mask;
            if (litter[nr][nc] != -1)
                nmask |= 1 << litter[nr][nc];
            int id = ID(nr, nc, ne, nmask);
            if (!visited[id]) {
                visited[id] = 1;
                queue[back++] = (State){nr, nc, ne, nmask, cur.dist + 1};
            }
        }
    }
    free(visited);
    free(queue);
    return -1;
}