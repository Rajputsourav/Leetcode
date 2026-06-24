int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = nums[0];

    int maxSum = nums[0];
    int currMax = nums[0];

    int minSum = nums[0];
    int currMin = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currMax = (currMax + nums[i] > nums[i]) ?
                  currMax + nums[i] : nums[i];
        maxSum = (maxSum > currMax) ? maxSum : currMax;

        currMin = (currMin + nums[i] < nums[i]) ?
                  currMin + nums[i] : nums[i];
        minSum = (minSum < currMin) ? minSum : currMin;

        totalSum += nums[i];
    }


    if (maxSum < 0)
        return maxSum;

    return (maxSum > totalSum - minSum) ?
           maxSum : totalSum - minSum;
}