int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    static int result[2];

    int low = 0, high = numbersSize - 1;

    while (low < high)
    {
        int sum = numbers[low] + numbers[high];

        if (sum == target)
        {
            result[0] = low + 1;
            result[1] = high + 1;
            *returnSize = 2;
            return result;
        }
        else if (sum < target)
            low++;
        else
            high--;
    }

    *returnSize = 0;
    return NULL;
}