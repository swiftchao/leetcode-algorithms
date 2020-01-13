/*************************************************************************
    > File Name: two-sum.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2020-01-13 16:05:44
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int i;
  int j;
  int *arr = (int*)malloc(2*sizeof(int));
  for (i = 0; i < numsSize - 1; ++i) {
    for (j = i + 1; j < numsSize; ++j) {
      if (target == (nums[i] + nums[j])) {
        arr[0] = i;
        arr[1] = j;
        returnSize[0] = i;
        returnSize[1] = j;
        return arr;
      }
    }
  }
  return NULL;
}
