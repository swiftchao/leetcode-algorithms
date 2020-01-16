/*************************************************************************
    > File Name: two-sum.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2020-01-13 16:05:44
 ************************************************************************/

#include <stdlib.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int i;
  int j;
  int *array = (int*)malloc(2 * sizeof(int));
  for (i = 0; i < numsSize - 1; ++i) {
    for (j = i + 1; j < numsSize; ++j) {
      if (target == (nums[i] + nums[j])) {
        array[0] = i;
        array[1] = j;
        /*returnSize为返回的数组的元素的个数
         * 找到两个数字和等于target时returnSize设置为2*/
        *returnSize = 2;
        return array;
      }
    }
  }
  /*找不到两个数字和等于target时returnSize设置为0*/
  *returnSize = 0;
  return array;
}
