/*************************************************************************
    > File Name: two-sum.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2020-01-13 16:05:44
 ************************************************************************/

#include <stdio.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
void printArray(int* array, int arraySize) {
  printf("[");
  int i;
  for (i = 0; i < arraySize; ++i) {
    printf("%d", array[i]);
    if (i < (arraySize - 1)) {
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
  int* array = (int*)twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, returnSize);
  printArray(array, *returnSize);
  return 0;
}
