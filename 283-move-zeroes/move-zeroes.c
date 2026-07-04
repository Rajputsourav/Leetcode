void moveZeroes(int* nums, int numsSize) {
    int low =0;

    int high =1;

    while(high<numsSize && low <numsSize){
        if((nums[low] == 0) && (nums[high] != 0)){
            int temp =nums[high];
            nums[high]= nums[low];
            nums[low]=temp;
            low++;
            high++;
        }else if(nums[low] != 0) {
            low++;
            if(high<=low){
                high=low+1;
            }
        }
        else high++;
    }

}