/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int)); ;
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return (res);
            }
        }
    }
    res[0] = 0;
    res[1] = 1;
    return (res);
}

int main(void) {
    int nums[] = {2,7,11,15};
    int numsSize = 3;
    int target = 9;
    int *returnSize;
    int *output = twoSum(nums, numsSize, target, returnSize);

    for (int i = 0; i < 2; i++) {
        printf("%d", output);
    }
    return (0);
}