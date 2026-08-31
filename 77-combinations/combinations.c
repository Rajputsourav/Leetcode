/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 * Note: Both returned array and *returnColumnSizes must be malloced,
 * assume caller calls free().
 */

#include <stdlib.h>

void backtrack(int start, int n, int k, int depth,
               int *temp, int **result,
               int *returnSize, int *returnColumnSizes) {

    // Combination is complete
    if (depth == k) {
        result[*returnSize] = (int *)malloc(k * sizeof(int));

        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = temp[i];
        }

        returnColumnSizes[*returnSize] = k;
        (*returnSize)++;

        return;
    }

    // Choose the next number
    for (int i = start; i <= n - (k - depth) + 1; i++) {
        temp[depth] = i;

        backtrack(i + 1, n, k, depth + 1,
                  temp, result, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    // Maximum number of combinations is C(n,k)
    long long total = 1;

    for (int i = 1; i <= k; i++) {
        total = total * (n - i + 1) / i;
    }

    int **result = (int **)malloc(total * sizeof(int *));
    *returnColumnSizes = (int *)malloc(total * sizeof(int));

    int *temp = (int *)malloc(k * sizeof(int));

    backtrack(1, n, k, 0,
              temp, result, returnSize, *returnColumnSizes);

    free(temp);

    return result;
}