bool uniformArray(int* nums1, int nums1Size) {
    int min = nums1[0];
    int hasEven = 0, hasOdd = 0;
    for(int i = 0; i < nums1Size; i++) {
        if(nums1[i] < min) min = nums1[i];
        if(nums1[i] % 2 == 0) hasEven = 1;
        else hasOdd = 1;
    }
    if(!hasEven || !hasOdd){
        return true;
    }
    return min % 2 == 1;
}