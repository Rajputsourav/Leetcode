int removeDuplicates(int* nums, int numsSize) {
    int counts= 1;
    for ( int i =1; i< numsSize;i++){
        if(nums[i] != nums[i-1]){
            nums[counts] = nums[i];
            counts++;
        }
    }
    return counts;
}