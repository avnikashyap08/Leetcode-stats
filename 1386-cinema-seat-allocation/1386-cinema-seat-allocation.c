#include <stdlib.h>
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int ans=2*n;
    int *rows=malloc(reservedSeatsSize*sizeof(int));
    int *mask=malloc(reservedSeatsSize*sizeof(int));
    int cnt = 0;
    for (int i=0; i<reservedSeatsSize; i++){
        int r =reservedSeats[i][0];
        int s =reservedSeats[i][1];
        int j;
        for (j=0; j<cnt; j++)
            if(rows[j] == r)
                break;
        if (j==cnt){
            rows[cnt]=r;
            mask[cnt++]=0;
        }
        mask[j]|=1<<s;
    }
    for(int i=0; i<cnt; i++) {
        int m=mask[i];
        int groups = 0;
        if (!(m & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)))) {
            groups++;
            m |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        }
        if (!(m & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)))) {
            groups++;
            m |= (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        }
        if (groups == 0 &&
            !(mask[i] & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)))) {
            groups = 1;
        }
        ans -= 2;
        ans += groups;
    }
    free(rows);
    free(mask);
    return ans;
}