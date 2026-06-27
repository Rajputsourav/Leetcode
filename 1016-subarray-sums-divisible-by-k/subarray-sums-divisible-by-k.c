#include <stdlib.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
    int *freq = (int *)calloc(k, sizeof(int));

    freq[0] = 1;         

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];

        int rem = prefixSum % k;
        if (rem < 0)
            rem += k;     

        count += freq[rem];
        freq[rem]++;
    }

    free(freq);
    return count;
}