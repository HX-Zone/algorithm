#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
  int val;
  struct ListNode* next;
}LISTNODE;

LISTNODE* merge(LISTNODE* pHead1,LISTNODE* pHead2){
  if(pHead1==NULL){
    return pHead2;
  }
  if(pHead2==NULL){
    return pHead1;
  }
  LISTNODE* mergedHead = NULL; 
  if(pHead1->val < pHead2->val){
    mergedHead = pHead1;
    mergedHead->next = merge(pHead1->next,pHead2);
  }
  else
  {
    mergedHead = pHead2;
    mergedHead->next = merge(pHead1,pHead2->next);
  }
  return mergedHead;
}

void printList(LISTNODE* head){
  LISTNODE* p = head;
  while(p!=NULL){
    printf("%d\n",p->val);
    p = p->next;
  }
}

int main(){
  LISTNODE* m = (LISTNODE*)malloc(sizeof(LISTNODE));
  if(!m){
    return 1;
  }
  m->next = NULL;
  m->val = 1;
  LISTNODE* new = (LISTNODE*)malloc(sizeof(LISTNODE));
  new->val = 3;
  new->next = NULL;
  m->next = new;
  LISTNODE* n = (LISTNODE*)malloc(sizeof(LISTNODE));
  if(!m){
    return 1;
  }
  n->val = 2;
  new = (LISTNODE*)malloc(sizeof(LISTNODE));
  new->val = 4;
  n->next = new;
  printf("m:\n");
  printList(m);
  printf("n:\n");
  printList(n);

  LISTNODE* r = merge(m,n);
  printf("r:\n");
  printList(r);
  
}
