/*题目：输入一个链表的头结点，从未到头反过来打印出每个结点的值
 * 思路：根据链表的结构，先找到的结点最后打印，这是栈的特征，可利用栈进行解决
 */

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
  int m_nKey;
  struct ListNode* m_pNext;
};

int printListNode(struct ListNode* head){
  if(!head){
    return 1;
  }
  printf("ListNode:");
  while(head){
    printf("%d->",head->m_nKey);
    head = head->m_pNext;
  }
  printf("%p\n",head);
  return 0;
}

int printListNodeReversely(struct ListNode* head){
  if(!head){
    return 1;
  }
  if(head->m_pNext){
    printListNodeReversely(head->m_pNext);
  }
  printf("%d->",head->m_nKey);
  return 0;
}

int main(){
  struct ListNode* list;
  list = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* head=list;
  if(!list){
    return 1;
  }
  list->m_nKey = 8;
  printListNode(head);
 // struct ListNode* temp;
  for(int i=0;i<4;i++){
    struct ListNode* tem;
    tem = (struct ListNode*)malloc(sizeof(struct ListNode));
    tem->m_nKey = i+1;
    list->m_pNext = tem;
    list = tem;
  }
  printListNode(head);
  printListNodeReversely(head);
  printf("\n");
  free(head);
}
