#include <iostream>
#include <queue>

void printFromTopToBottom(BinaryTreeNode* pTreeRoot){
  if(!pTreeRoot){
    return;
  }

  std::deque<BinaryTreeNode*> dequeTreeNode;

  dequeTreeNode.push_back(pTreeRoot);

  while(!dequeTreeNode.empty()){//队列不为空
    if(pTreeRoot->m_pLeft!=NULL){
      dequeTreeNode.push_back(pTreeRoot->m_pLeft);
    }
    if(pTreeRoot->m_pRight!=NULL){
      dequeTreeNode.push_back(pTreeRoot->m_pRight);
    }
    printf("%d,",pTreeRoot->m_nValue);
    dequeTreeNode.pop();
  }
}

