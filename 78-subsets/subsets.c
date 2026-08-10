/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 */
void backtrack(int* nums, int numsSize, int start,
               int* current, int currentSize,
               int** result, int* returnSize,
               int* returnColumnSizes) {

    result[*returnSize] = malloc(currentSize * sizeof(int));

    for (int i = 0; i < currentSize; i++) {
        result[*returnSize][i] = current[i];
    }

    returnColumnSizes[*returnSize] = currentSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {

        current[currentSize] = nums[i];

        backtrack(nums, numsSize, i + 1,
                  current, currentSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {

    int total = 1 << numsSize;

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    int* current = malloc(numsSize * sizeof(int));

    *returnSize = 0;

    backtrack(nums, numsSize, 0,
              current, 0,
              result, returnSize,
              *returnColumnSizes);

    free(current);

    return result;
}