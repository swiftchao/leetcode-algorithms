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
void printArray(int* returnSize) {
  int* pi;
  printf("[");
  for (pi = returnSize; pi < (returnSize+2); ++pi) {
    printf("%d", *pi);
    if (pi < (returnSize+1)) {
      printf(",");
    }
  }
  printf("]");
  printf("\n");
}

int main(void) {
  int  nums[] = {2, 7, 11, 15};
  int target = 9;
  int* returnSize;
  twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, returnSize);
  printArray(returnSize);
  return 0;
}
