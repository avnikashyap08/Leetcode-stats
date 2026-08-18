int largestInteger(int* nums, int numsSize, int k){
    int count[51] = {0};
    for (int i=0;i<=numsSize-k;i++){
        int seen[51] = {0};
        for (int j=i;j<i+k;j++){
            seen[nums[j]] = 1;
        }
        for(int x=0;x<=50;x++){
            if(seen[x])
                count[x]++;
        }
    }
    for(int x=50;x>=0;x--){
        if(count[x]==1)
            return x;
    }
    return -1;
}