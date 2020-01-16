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

struct ListNode {
  int val;
  struct ListNode *next;
};

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

/*使unsigned long long类型防止数值过大传递值变化了比如9999999991和1000000000000000000000000000001*/
struct ListNode* store_num_to_list_node(unsigned long long val) {
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

unsigned long long covert_list_to_num(struct ListNode *list_node) {
  struct ListNode *node = list_node;
  /*注意total定义成double防止精度缺失*/
  unsigned long long total = 0;
  int i;
  for (i = 0; NULL != node; ++i) {
    /*注意double转成int的精度缺失,比如300转成了299*/
    total = total + (node->val * pow(10.0, i));
    node = node->next;
  }
  //printf("%d\n", (int)total);
  return total;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
  unsigned long long total = 0;
  unsigned long long a = covert_list_to_num(l1);
  unsigned long long b = covert_list_to_num(l2);
  total = a + b;
  return store_num_to_list_node(total);
}

int main(void) {
  struct ListNode *l1 = NULL;
  struct ListNode *l2 = NULL;
  //int a = 342;
  //int b = 465;
  //long long a = 9;
  //long long b = 9999999991;
  unsigned long long a = 1000000000000000000000000000001;
  unsigned long long b = 465;
  //unsigned long long a = 1000000000000000000000000000001;
  //unsigned long long b = 564;
  struct ListNode *total_node = NULL;
  l1 = store_num_to_list_node(a);
  l2 = store_num_to_list_node(b);
  print_list_node(l1);
  print_list_node(l2);
  total_node = addTwoNumbers(l1, l2);
  print_list_node(total_node);
  return 0;
}
