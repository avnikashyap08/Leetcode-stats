int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int min = nums[0];
    int max = nums[0];
    for(int i=1; i<numsSize; i++){
        if(nums[i]<min){
            min=nums[i];
        }
        if(nums[i]>max)
            max=nums[i];}
    int* ans= (int*)malloc((max-min+1) *sizeof(int));
    int count=0;
    for(int num=min;num<=max;num++){
        int found=0;
        for(int i=0;i<numsSize;i++){
            if(nums[i]==num){
                found=1;
                break;
            }
        }
        if(found==0){
            ans[count]=num;
            count++;
        }
    }
    *returnSize = count;
    return ans;
}