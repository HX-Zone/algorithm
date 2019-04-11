#include <stdio.h>

typedef struct Node{
  int val;
  struct Node* next;
}LISTNODE;

LISTNODE* TheCommonNode(LISTNODE* head1,LISTNODE* head2){
  if(head1==NULL || head2==NULL){
    return NULL;
  }
  LISTNODE* p1 = head1;
  LISTNODE* p2 = head2;
  int len1 = 1,len2 = 1;
  while(p1->next!=NULL){
    p1 = p1->next;
    ++ len1;
  }
  while(p2->next!=NULL){
    p2 = p2->next;
    ++ len2;
  }
  p1 = head1;
  p2 = head2;
  if(len2 > len1){
    for(int i=0;i<(len2-len1);i++){
      p2 = p2->next;
    }
  }else{
    for(int i=0;i<(len1 - len2);i++){
      p1 = p1->next;
    }
  }
  while(p1!=NULL && p2!=NULL){
    if(p1==p2)
      break;

    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}
