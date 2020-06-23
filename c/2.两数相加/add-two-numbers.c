/*************************************************************************
    > File Name: add-two-numbers.c
    > Author: chaofei
    > Mail: chaofeibest@163.com
    > Created Time: 2020-01-16 16:19:30
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 **/
/*
struct ListNode {
  int val;
  struct ListNode *next;
};
*/

struct ListNode* init_list_node(int val) {
  struct ListNode *node = (struct ListNode *)(malloc(sizeof(struct ListNode)));
  node->val = val;
  node->next = NULL;
  return node;
}

void print_list_node(struct ListNode *list_node) {
  struct ListNode *node = list_node;
  while (NULL != node) {
    printf("%d", node->val);
    if (NULL != node->next) {
      printf("->");
    }
    node = node->next;
  }
  printf("\n");
}

int cal_num_length(int val) {
  int i;
  int sub_val_right;
  for (i = 0; val > 0; ++i) {
    sub_val_right = val % 10;
    val = val / 10;
  }
  return i;
}

/*使用long long类型防止数值过大传递值变化了比如9999999991*/
struct ListNode* store_num_to_list_node(long long val) {
  int i;
  int sub_val_right = 0;
  struct ListNode *header = NULL;
  struct ListNode *node = NULL;
  sub_val_right = val % 10;
  val = val / 10;
  header = init_list_node(sub_val_right);
  node = header;
  for (i = 0; val > 0; ++i) {
    sub_val_right = val % 10;
    /*串成链表*/
    node->next = init_list_node(sub_val_right);
    /*node后移一个防止覆盖之前的值*/
    node = node->next;
    val = val / 10;
  }
  return header;
}

long long covert_list_to_num(struct ListNode *list_node) {
  struct ListNode *node = list_node;
  /*注意total定义成double防止精度缺失*/
  double total = 0;
  int i;
  for (i = 0; NULL != node; ++i) {
    /*注意double转成int的精度缺失,比如300转成了299*/
    total = total + (node->val * pow(10.0, i));
    node = node->next;
  }
  //printf("%d\n", (int)total);
  return (long long)total;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
  long long total = 0;
  long long a = covert_list_to_num(l1);
  long long b = covert_list_to_num(l2);
  total = a + b;
  return store_num_to_list_node(total);
}
