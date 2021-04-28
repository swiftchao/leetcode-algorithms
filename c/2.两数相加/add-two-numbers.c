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

struct ListNode* store_num_to_list_node(const char* arr_val) {
    struct ListNode *header;
    struct ListNode *node;
    const char* p = arr_val;
    header = init_list_node(*p - '0');
    ++p;
    node = header;
    while ('\0' != *p) {
        int p_val = *p - '0';
        node->next = init_list_node(p_val);
        /*node后移一个防止覆盖之前的值*/
        node = node->next;
        ++p;
    }
    return header;
}

int cal_list_node_length(struct ListNode* lnode) {
    struct ListNode* node = lnode;
    int node_length = 0;
    while (NULL != node) {
        ++node_length; 
        node = node->next;
    }
    return node_length;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode *header = init_list_node(0);
    struct ListNode* node;
    node = header;
    int l1_len = cal_list_node_length(l1);
    int l2_len = cal_list_node_length(l2);
    int carry = 0;

    while (NULL != p1 || NULL != p2) {
        int sum = 0;
        if (l1_len > l2_len) {
            if (NULL != p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            --l1_len;
        } else if (l1_len < l2_len) {
            if (NULL != p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            --l2_len;
        } else if (l1_len == l2_len) {
            if (NULL != p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            --l1_len;

            if (NULL != p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            --l2_len;
        }
        if (sum >= 10) {
            sum = sum - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        if (carry != 0) {
            node->next = init_list_node(carry);
            node->val += carry;
        }
        
        node->next = init_list_node(sum);
       
        node = node->next;
    }
    return header->next; 
}

