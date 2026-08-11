int missingInteger(int* nums, int numsSize){
    int sum = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1] + 1){
            sum += nums[i];
        }
        else{
            break;
        }
    }
    int x = sum;
    while(1){
        int found = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] == x){
                found = 1;
                break;
            }
        }
        if(found == 0){
            return x;
        }
        x++;
    }
}